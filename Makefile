
#program name
NAME= pipex

#bonus program name
NAME_B= pipex_bonus

#cc compiler with all flags
CCF= cc -Wall -Wextra -Werror

#mandatory
SRC = $(shell find "./source" -type f )
OBJ = $(SRC:.c=.o)

#bonus
SRC_B = $(shell find "./source_bonus" -type f )
OBJ_B = $(SRC_B:.c=.o)

#include header
INC= -I includes

#debuging
ifeq ($(DEBUG), YES)
   GDB = -g
endif

.PHONY: all clean fclean re clear bonus

all: $(NAME)


$(NAME): $(OBJ)
		@$(CCF) $(INC) $^ -o $@
		@echo "compiling"
		@sleep 0.5
		@echo "pipex is ready"


bonus: $(OBJ_B)
		@$(CCF) $(INC) $^ -o $(NAME_B)
		@echo "compiling"
		@sleep 0.5
		@echo "pipex_bonus is ready"


%.o: %.c
		@$(CCF) $(GDB) $(INC) -c $< -o $@ 


clean:
		@rm -f $(OBJ) $(OBJ_B)
		@echo "cleaning..."


fclean: clean
		@rm -f $(NAME) $(NAME_B)
		@echo "cleaning program..."


re: fclean all


clear: all bonus clean

norm :
		@norminette $(SRC) $(SRC_B) includes/
