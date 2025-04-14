NAME=philo
FILES=./main.o ./philo_actions.o ./time.o ./utils.o ./philo.o ./join.o
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