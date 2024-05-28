
#program name
NAME= pipex

#bonus program name
NAME_B= pipex_bonus

#cc compiler with all flags
CCF= cc -Wall -Wextra -Werror

#mandatory
SRC = $(shell find "source" -name "*.c")
OBJ = $(SRC:.c=.o)

#bonus
SRC_B = $(shell find "source_bonus" -name "*.c")
OBJ_B = $(SRC_B:.c=.o)

#include header
INC= -I includes

#debuging
ifeq ($(DEBUG), 1)
   GDB = -g
endif


all: $(NAME)


$(NAME): $(OBJ)
		@$(CCF) $(INC) $^ -o $@
		@echo "compiling"
		@sleep 0.5
		@echo "pipex is ready"


bonus: $(OBJ_B)
		@$(CCF) $^ -o $(NAME_B)
		@echo "compiling"
		@sleep 0.5
		@echo "pipex_bonus is ready"


%.o: %.c
		@$(CCF) $(INC) $(GDB)-c $< -o $@ 


clean:
		@rm -f $(OBJ) $(OBJ_B)
		@echo "cleaning..."


fclean: clean
		@rm -f $(NAME) $(NAME_B)
		@echo "cleaning program..."


re: fclean all


clear: all bonus clean