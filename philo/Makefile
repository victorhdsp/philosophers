NAME=philo
FILES=./main.o ./time.o ./monitor.o ./philo.o ./utils.o ./philo_actions.o ./monitor_actions.o ./join.o
CC=cc -Wall -Wextra -ggdb -O0

all: $(NAME)

$(NAME): $(FILES)
	$(CC) $^ -o $@  -lpthread #-fsanitize=thread -lc

.o:.c
	$(CC) -o $<

clean:
	rm -rf $(FILES) $(B_FILES)

fclean: clean
	rm -rf $(NAME) $(B_NAME)

re:	fclean all