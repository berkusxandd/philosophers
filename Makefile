NAME = philo
SRCS = ./srcs/main.c

OBJS_DIR = ./objs
OBJS = $(SRCS:./srcs/%.c=$(OBJS_DIR)/%.o)
LIBFT = ./Libft/libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
PTHREAD= -pthread
RM = rm -rf

GREEN = \033[0;92m
BLUE = \033[0;94m
WHITE = \033[0;97m

all: makelibs $(NAME)

makelibs:
	@make bonus -C ./Libft
	@echo "$(BLUE)**libft compiled"

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: ./srcs/%.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBFT) $(PTHREAD) -o $(NAME)
	@echo "$(GREEN)philo compiled $(WHITE)"

clean:
	$(RM) $(OBJS_DIR)
	@make clean -C ./Libft

fclean: clean
	$(RM) $(NAME)
	@make fclean -C ./Libft

re: fclean all