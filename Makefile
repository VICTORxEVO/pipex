NAME= pipex

CCF= cc -Wall -Wextra -Werror

SRC = $(shell find . -name "*.c")
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		@$(CCF) -g -o $(NAME) $^
		@echo "compiling"
		@sleep 0.5
		@echo "pipex is ready"

%.o: %.c
		@$(CCF) -c $< -o $@ -g

clean:
		@rm -f $(OBJ)
		@echo "cleaning..."

fclean: clean
		@rm -f $(NAME)
		@echo "cleaning program..."

re: fclean all

clear: all clean