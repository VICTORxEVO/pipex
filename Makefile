#program name
NAME= pipex

#bonus program name
NAME_B= pipex_bonus

#cc compiler with all flags
CCF= cc -Wall -Wextra -Werror

#some colors and values
RED := \033[0;31m
GREEN := \033[0;32m
YELLOW := \033[33;1m
RESET := \033[0m
CLEAR := \033[K
RETURN := \r
BOLD_PURPLE := \033[35;1m
BOLD_UNDER_GREEN := \033[32;1;4m
BOLD_GREEN := \033[32;1m


#object directory for mandatory
obj_dir = objects

#source files and directorys of mandatory
ch_dir = source/child
ch_files = child_action dup2fd exec_cmd getting_cmd in_out

cl_dir = source/clear
cl_files = malloc_v1e2 peexit destroy delete_1cmd

ext_dir = source/external
ext_files = ft_lstadd_back ft_lstclear ft_lstnew_cmd ft_strncmp ft_lstdelone \
ft_split is_all_spaces ft_strdup puterr ft_strchr ft_strjoin get_next_line get_next_line_utils

par_dir = source/parent
par_files = seal_all_p create_pipes parent_action 

parse_dir = source/parsing
parse_files = parser get_paths get_cmds 

main = source/pipex

#add path and extension to source files for mandatory
ch_src = $(addprefix $(ch_dir)/, $(addsuffix .c, $(ch_files)))
cl_src = $(addprefix $(cl_dir)/, $(addsuffix .c, $(cl_files)))
ext_src = $(addprefix $(ext_dir)/, $(addsuffix .c, $(ext_files)))
par_src = $(addprefix $(par_dir)/, $(addsuffix .c, $(par_files)))
parse_src = $(addprefix $(parse_dir)/, $(addsuffix .c, $(parse_files)))
main_src = $(addsuffix .c, $(main))

#MANDATORY
###############################################################################
###############################################################################
#BOUNS

#object directory for bonus
obj_dir_b = objects_bonus

#source files and directorys of bonus
ch_dir_b = source_bonus/child
ch_files_b = getting_cmd child_action exec_cmd dup2fd in_out

cl_dir_b = source_bonus/clear
cl_files_b = malloc_V1e5 peexit destroy delete_1cmd

ext_dir_b = source_bonus/external
ext_files_b = get_next_line_utils ft_lstadd_back get_next_line ft_lstclear ft_lstnew_cmd ft_strncmp \
ft_lstdelone ft_split is_all_spaces ft_strdup puterr ft_strchr ft_itoa ft_strjoin

hd_dir_b = source_bonus/here_doc
hd_files_b = here_doc print_null_err read_line

par_dir_b = source_bonus/parent
par_files_b = seal_all_p create_pipes parent_action

parse_dir_b = source_bonus/parsing
parse_files_b = parser get_paths get_cmds

main_b = source_bonus/pipex_bonus

#add path and extension to source files for bonus
ch_src_b = $(addprefix $(ch_dir_b)/, $(addsuffix .c, $(ch_files_b)))
cl_src_b = $(addprefix $(cl_dir_b)/, $(addsuffix .c, $(cl_files_b)))
ext_src_b = $(addprefix $(ext_dir_b)/, $(addsuffix .c, $(ext_files_b)))
hd_src_b = $(addprefix $(hd_dir_b)/, $(addsuffix .c, $(hd_files_b)))
par_src_b = $(addprefix $(par_dir_b)/, $(addsuffix .c, $(par_files_b)))
parse_src_b = $(addprefix $(parse_dir_b)/, $(addsuffix .c, $(parse_files_b)))
main_src_b = $(addsuffix .c, $(main_b))


# source files and object files for mandatory
src = $(main_src) $(ch_src) $(cl_src) $(ext_src) $(par_src) $(parse_src)
obj = $(patsubst %.c, $(obj_dir)/%.o, $(notdir $(src)))

#source files and object files for bonus
src_b = $(main_src_b) $(ch_src_b) $(cl_src_b) $(ext_src_b) $(hd_src_b) $(par_src_b) $(parse_src_b)
obj_b = $(patsubst %.c, $(obj_dir_b)/%.o, $(notdir $(src_b)))


#include header
INC= -I ./includes

#debuging
ifeq ($(DEBUG), YES)
   GDB = -g
endif

.PHONY: all clean fclean re clear bonus
.SECONDARY: $(obj) $(obj_b)

all: $(NAME)


$(NAME): $(obj)
		@$(CCF)  $^ -o $@
		@echo  -n "$(RETURN)$(BOLD_GREEN)Building the program... $(RESET)$(CLEAR)"
		@sleep 0.68
		@echo -n "$(RETURN)$(CLEAR)"
		@echo "$(BOLD_UNDER_GREEN)>>>$(NAME) PROGRAM IS READY<<<$(RESET)\n$(YELLOW)Usage: ./pipex infile cmd1 cmd2 outfile $(RESET)"

$(obj_dir)/%.o: $(src)
		@mkdir -p $(obj_dir)
		@echo -n "$(RETURN)$(YELLOW)Compiling:  $(notdir $(filter %/$*.c, $(src)))....$(CLEAR)$(RESET)"
		@$(CCF) $(GDB) $(INC) -c $(filter %/$*.c, $(src)) -o $@
		@sleep 0.062

#MANDATORY BUILD
##########################################
#BONUS BUILD

bonus: $(obj_b)
		@$(CCF) $(INC) $^ -o $(NAME_B)
		@echo  -n "$(RETURN)$(BOLD_GREEN)Building the program... $(RESET)$(CLEAR)"
		@sleep 0.68
		@echo -n "$(RETURN)$(CLEAR)"
		@echo "$(BOLD_UNDER_GREEN)>>>$(NAME_B) PROGRAM IS READY<<<$(RESET)\n$(YELLOW)Usage: ./pipex infile cmd1 cmd2... cmd_n outfile $(RESET)"

$(obj_dir_b)/%.o: $(src_b)
		@mkdir -p $(obj_dir_b)
		@echo -n "$(RETURN)$(YELLOW)Compiling:  $(notdir $(filter %/$*.c, $(src_b)))....$(CLEAR)$(RESET)"
		@$(CCF) $(GDB) $(INC) -c $(filter %/$*.c, $(src_b)) -o $@
		@sleep 0.062


clean:
		@echo  -n "$(YELLOW)Cleaning up...$(RESET)$(CLEAR)$(RETURN)"
		@rm -rf $(obj_dir) $(obj_dir_b)
		@rm -f $(obj) $(obj_b)
		@sleep 0.60


fclean: clean
		@rm -f $(NAME) $(NAME_B)
		@echo "$(YELLOW)Cleaning up the program...$(RESET)"
		@sleep 0.2


re: fclean all

bre: fclean bonus

clear: all bonus clear
		@rm -rf $(obj_dir) $(obj_dir_b)

norm:
		@norminette $(src)
		@echo "----------------"
		@norminette $(src_b)
		@echo "----------------"
		@norminette includes/

show:
	@echo $(src_b)
	@echo "------------"
	@echo $(obj_b)

