#include "../includes/philo.h"

void set_all_alive(t_params *params)
{
    pthread_mutex_lock(&params->mtx_alive);
    params->all_alive = 0;
    pthread_mutex_unlock(&params->mtx_alive);   
}
long long get_last_meal(t_params *params, int i)
{
    long long last_meal;

    pthread_mutex_lock(&params->mtx_last_meal);
    last_meal = current_timestamp() - params->philosophers[i].last_meal;
    pthread_mutex_unlock(&params->mtx_last_meal);
    return last_meal;
}

void *monitor_routine(void *params_ptr)
{
    t_params *params = (t_params *)params_ptr;
    long long last_meal;
    int i;
    
    i = 0;
    while (1)
    {
        while (i < params->n_philo)
        {
            last_meal = get_last_meal(params, i);
            if (last_meal >= params->t_die)
            {
                print_state(&params->philosophers[i], "died");
                set_all_alive(params);
                return NULL;
            }
            pthread_mutex_lock(&params->mtx_meal);
            if (params->meals_to_finish == params->n_philo)
            {
                set_all_alive(params);
                pthread_mutex_unlock(&params->mtx_meal);
                return NULL;
            }
            pthread_mutex_unlock(&params->mtx_meal);
            i++;
        }
        i = 0;
    usleep(500);
    }
    return NULL;
}

long long current_timestamp()
{
    struct timeval time;
    gettimeofday(&time, NULL);
    return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void philo_sleep(long long time)
{
    long long now;

    now = current_timestamp();
    while (1)
    {
        if (current_timestamp() - now > time)
            return ;
        usleep(5);
    }
}
void print_state(t_philosopher *philo, char *state)
{
    pthread_mutex_lock(&(philo->params->mtx_print));
    long long time = current_timestamp() - philo->params->start_time;
    printf("%lld %d %s\n", time, philo->id, state);
    pthread_mutex_unlock(&(philo->params->mtx_print));
}

void lock_forks(t_philosopher *philo)
{
    if (philo->id % 2 == 0 && philo->params->all_alive != 0)
    {

        pthread_mutex_lock(philo->left_fork);
        pthread_mutex_lock(philo->right_fork);

    }
    if (philo->id % 2 != 0 && philo->params->all_alive != 0)
    {
        usleep(50);
        pthread_mutex_lock(philo->right_fork);
        pthread_mutex_lock(philo->left_fork);
    }
}

void finish_eat(t_philosopher *philo)
{
  pthread_mutex_unlock(philo->right_fork);
    pthread_mutex_unlock(philo->left_fork);
    if (philo->full == 0)
        philo->meals_eaten++;
    if (philo->meals_eaten >= philo->params->meals_requested && philo->full == 0)
    {
        philo->full = 1;
        pthread_mutex_lock(&philo->params->mtx_meal);
        philo->params->meals_to_finish++;
        pthread_mutex_unlock(&philo->params->mtx_meal);
    }
}

void eat_monitor(t_philosopher *philo)
{
    print_state(philo, "has taken a fork");
    print_state(philo, "has taken a fork");
    print_state(philo, "is eating");
}

void eat(t_philosopher *philo)
{
    pthread_mutex_lock(&philo->params->mtx_alive);
    if (philo->params->all_alive != 1)
    {
        pthread_mutex_unlock(&philo->params->mtx_alive);
        return ;
    }
    pthread_mutex_unlock(&philo->params->mtx_alive);
    lock_forks(philo);
    pthread_mutex_lock(&philo->params->mtx_alive);
    if (philo->params->all_alive != 1)
    {
        pthread_mutex_unlock(&philo->params->mtx_alive);
        pthread_mutex_unlock(philo->right_fork);
        pthread_mutex_unlock(philo->left_fork);

        return;
    } 
    pthread_mutex_unlock(&philo->params->mtx_alive);
    if (philo->left_fork == philo->right_fork)
    {
        pthread_mutex_unlock(philo->right_fork);
        pthread_mutex_unlock(philo->left_fork);
        return;
    } 
    eat_monitor(philo);
    pthread_mutex_lock(&philo->params->mtx_last_meal);
    philo->last_meal = current_timestamp();
    pthread_mutex_unlock(&philo->params->mtx_last_meal);
    usleep(philo->params->t_eat * 1000);
    finish_eat(philo);
    usleep(100);
}

void *philosopher_routine(void *philosopher)
{
    t_philosopher *philo = (t_philosopher *)philosopher;
    print_state(philo, "is thinking");
    while (1)
    {
        eat(philo);
        pthread_mutex_lock(&philo->params->mtx_alive);
        if (!philo->params->all_alive)
        {
            pthread_mutex_unlock(&philo->params->mtx_alive);
            return NULL;
        }
        pthread_mutex_unlock(&philo->params->mtx_alive);
        print_state(philo, "is sleeping");
        philo_sleep((long long)philo->params->t_sleep);        
        pthread_mutex_lock(&philo->params->mtx_alive);
        if (!philo->params->all_alive)
        {
            pthread_mutex_unlock(&philo->params->mtx_alive);
            break;
        }
        pthread_mutex_unlock(&philo->params->mtx_alive);
        print_state(philo, "is thinking");
        usleep(100);
    }
    return NULL;
}

void initialize_philosophers(t_philosopher *philosophers, t_params *params)
{
    params->philosophers = philosophers;
    for (int i = 0; i < params->n_philo; i++)
    {
        philosophers[i].id = i + 1;
        philosophers[i].params = params;
        philosophers[i].meals_eaten = 0;
        philosophers[i].last_meal = current_timestamp();
        philosophers[i].left_fork = &params->forks[i];
        philosophers[i].right_fork = &params->forks[(i + 1) % params->n_philo];
        philosophers[i].full = 0;
    }
}

void start_simulation(t_philosopher *philosophers, t_params *params)
{
    int i;

    i = 0;
    params->start_time = current_timestamp();
    while (i < params->n_philo)
    {
        pthread_create(&philosophers[i].thread, NULL, philosopher_routine, &philosophers[i]);
        i++;
    }
    pthread_t monitor_thread;
    pthread_create(&monitor_thread, NULL, monitor_routine, (void *)params);
    pthread_join(monitor_thread, NULL);
    i = 0;
    while(i < params->n_philo)
    {
        pthread_join(philosophers[i].thread, NULL);
        i++;
    }
}

int arg_check(int argc)
{
    if (argc < 5 || argc > 6)
    {
        printf("Invalid arguments\n");
        return 1;
    }
    else
        return 0;
}

t_params init_params(int argc, char **argv)
{
    t_params params;

    params.n_philo = ft_atoi(argv[1]);
    params.t_die = ft_atoi(argv[2]);
    params.t_eat = ft_atoi(argv[3]);
    params.t_sleep = ft_atoi(argv[4]);
    params.all_alive = 1;
    if (argc == 6)
    {
        params.meals_requested = ft_atoi(argv[5]);
        params.meals_to_finish = 0; 
    }
    else
    {
        params.meals_requested = -1;
        params.meals_to_finish = -1;
    }
    return params;
}

void mtx_init(t_params *params)
{
    int i;

    i = 0;
    pthread_mutex_init(&params->mtx_print, NULL);
    pthread_mutex_init(&params->mtx_meal, NULL);
    pthread_mutex_init(&params->mtx_last_meal, NULL);
    pthread_mutex_init(&params->mtx_alive, NULL);
    pthread_mutex_init(&params->mtx_full_meal, NULL);
    params->forks = malloc(sizeof(pthread_mutex_t) * params->n_philo);
    while(i < params->n_philo)
    {
        pthread_mutex_init(&params->forks[i], NULL);
        i++;
    }
}

void clean_exit(t_philosopher *philosophers, t_params *params)
{
    int i;

    i = 0;
    while (i < params->n_philo)
    {
        pthread_mutex_destroy(&params->forks[i]);
        i++;
    }
    pthread_mutex_destroy(&params->mtx_print);
    pthread_mutex_destroy(&params->mtx_meal);
    pthread_mutex_destroy(&params->mtx_alive);
    pthread_mutex_destroy(&params->mtx_full_meal);
    pthread_mutex_destroy(&params->mtx_last_meal);
    free(params->forks);
    free(philosophers);
}

int main(int argc, char **argv)
{
    t_philosopher *philosophers;
    t_params params;

    if (arg_check(argc) != 0)
        return 1;
    params = init_params(argc,argv);
    mtx_init(&params);
    philosophers = malloc(sizeof(t_philosopher) * params.n_philo);
    initialize_philosophers(philosophers, &params);
    start_simulation(philosophers, &params);
    clean_exit(philosophers, &params);
    return 0;
}