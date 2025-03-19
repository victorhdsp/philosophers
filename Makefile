NAME=philo
FILES=./src/main.o ./src/time.o ./src/monitor.o ./src/philo.o ./src/utils.o ./src/philo_actions.o ./src/monitor_actions.o ./src/join.o
B_NAME=philo_bonus
B_FILES=./src/bonus/main.o ./src/bonus/philo_actions.o ./src/bonus/time.o ./src/bonus/utils.o ./src/bonus/philo.o ./src/bonus/join.o
CC=cc -Wall -Wextra -ggdb -O0

all: $(NAME)

$(NAME): $(FILES)
	$(CC) $^ -o $@  -lpthread #-fsanitize=thread -lc

bonus: $(B_NAME)

$(B_NAME): $(B_FILES)
	$(CC) $^ -o $@  -lpthread #-fsanitize=thread -lc

.o:.c
	$(CC) -o $<

clean:
	rm -rf $(FILES) $(B_FILES)

fclean: clean
	rm -rf $(NAME) $(B_NAME)

re:	fclean all