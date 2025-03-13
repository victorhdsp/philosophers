NAME=philo
FILES=./src/main.o ./src/time.o ./src/monitor.o ./src/philo.o ./src/utils.o ./src/philo_actions.o
CC=cc -Wall -Wextra -ggdb

all: $(NAME)

$(NAME): $(FILES)
	$(CC) $^ -o $@  -lpthread #-fsanitize=thread -lc

.o:.c
	$(CC) -o $<

clean:
	rm -rf $(FILES)

fclean: clean
	rm -rf $(NAME)

re:	fclean all