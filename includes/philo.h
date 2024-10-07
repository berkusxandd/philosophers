#ifndef PHILO_H
#define PHILO_H
#include <pthread.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../Libft/libft.h"
#define ERR_THREAD 0
#define ERR_MALLOC_PH 1
#define ERR_MALLOC_F 2
typedef struct s_philosopher
{
    int id;
    pthread_t thread;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
    long long last_meal;
    int meals_eaten;
    int full;
    struct s_params *params;
} t_philosopher;

typedef struct s_params
{
    int n_philo;
    int t_die;
    int t_eat;
    int t_sleep;
    int meals_requested;
    int meals_to_finish;
    int all_alive;
    pthread_mutex_t *forks;
    pthread_mutex_t mtx_print;
    pthread_mutex_t mtx_meal;
    pthread_mutex_t mtx_last_meal;
    pthread_mutex_t mtx_alive;
    pthread_mutex_t mtx_time;
    pthread_mutex_t mtx_full_meal;
    long long start_time;
    t_philosopher *philosophers; // Add this to hold the philosophers array
} t_params;

long long current_timestamp();
void print_state(t_philosopher *philo, char *state);
void *philosopher_routine(void *philosopher);
void clean_exit(t_philosopher *philosophers, t_params *params);
#endif