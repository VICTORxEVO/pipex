NAME= pipex

NAME_B= pipex_bonus


CCF= cc -Wall -Wextra -Werror

SRC = $(shell find "source" -name "*.c")
OBJ = $(SRC:.c=.o)

SRC_B = $(shell find "source_bonus" -name "*.c")
OBJ_B = $(SRC_B:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		@$(CCF) $^ -o $@
		@echo "compiling"
		@sleep 0.5
		@echo "pipex is ready"

bonus: $(OBJ_B)
		@$(CCF) $^ -o $(NAME_B)
		@echo "compiling"
		@sleep 0.5
		@echo "pipex_bonus is ready"

%.o: %.c
		@$(CCF) -c $< -o $@ -g

clean:
		@rm -f $(OBJ) $(OBJ_B)
		@echo "cleaning..."

fclean: clean
		@rm -f $(NAME) $(NAME_B)
		@echo "cleaning program..."

re: fclean all

clear: all bonus clean