#program name
NAME= pipex

#bonus program name
NAME_B= pipex_bonus

#cc compiler with all flags
CCF= cc -Wall -Wextra -Werror

#object directory for mandatory
obj_dir = objects

#source files and directorys of mandatory
ch_dir = source/child
ch_files = child_action dup2fd exec_cmd getting_cmd in_out seal_unused_p

cl_dir = source/clear
cl_files = malloc_v1e2 peexit destroy delete_1cmd 

ext_dir = source/external
ext_files = ft_lstadd_back ft_lstclear get_next_line_utils_bonus ft_lstnew_cmd ft_strncmp ft_lstdelone \
ft_split get_next_line_bonus is_all_spaces ft_strdup puterr ft_strchr ft_strjoin 

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
ch_files_b = getting_cmd child_action seal_unused_p exec_cmd dup2fd in_out

cl_dir_b = source_bonus/clear
cl_files_b = malloc_V1e5 peexit destroy delete_1cmd

ext_dir_b = source_bonus/external
ext_files_b = get_next_line_utils ft_lstadd_back get_next_line ft_lstclear ft_lstnew_cmd ft_strncmp \
ft_lstdelone ft_split is_all_spaces ft_strdup puterr ft_strchr ft_itoa ft_strjoin

hd_files_b = source_bonus/here_doc/here_doc

hd_ch_dir_b = source_bonus/here_doc/child
hd_ch_files_b = child_cmd1 print_null_err

hd_par_dir_b = source_bonus/here_doc/parent
hd_par_files_b = close_pipes read_line parent_cmd2

par_dir_b = source_bonus/parent
par_files_b = seal_all_p create_pipes parent_action

parse_dir_b = source_bonus/parsing
parse_files_b = parser get_paths get_cmds

main_b = source_bonus/pipex_bonus

#add path and extension to source files for bonus
ch_src_b = $(addprefix $(ch_dir_b)/, $(addsuffix .c, $(ch_files_b)))
cl_src_b = $(addprefix $(cl_dir_b)/, $(addsuffix .c, $(cl_files_b)))
ext_src_b = $(addprefix $(ext_dir_b)/, $(addsuffix .c, $(ext_files_b)))
hd_src_b = $(addsuffix .c, $(hd_files_b))
hd_ch_src_b = $(addprefix $(hd_ch_dir_b)/, $(addsuffix .c, $(hd_ch_files_b)))
hd_par_src_b = $(addprefix $(hd_par_dir_b)/, $(addsuffix .c, $(hd_par_files_b)))
par_src_b = $(addprefix $(par_dir_b)/, $(addsuffix .c, $(par_files_b)))
parse_src_b = $(addprefix $(parse_dir_b)/, $(addsuffix .c, $(parse_files_b)))
main_src_b = $(addsuffix .c, $(main_b))


# source files and object files for mandatory
src = $(main_src) $(ch_src) $(cl_src) $(ext_src) $(par_src) $(parse_src)
obj = $(patsubst %.c, $(obj_dir)/%.o, $(notdir $(src)))

#source files and object files for bonus
src_b = $(main_src_b) $(ch_src_b) $(cl_src_b) $(ext_src_b) $(hd_src_b) $(hd_ch_src_b) $(hd_par_src_b) $(par_src_b) $(parse_src_b)
obj_b = $(patsubst %.c, $(obj_dir_b)/%.o, $(notdir $(src_b)))


#include header
INC= -I ./includes

#debuging
ifeq ($(DEBUG), YES)
   GDB = -g
endif

.PHONY: all clean fclean re clear bonus

all: $(NAME)


$(NAME): $(obj)
		@$(CCF)  $^ -o $@
		@echo "compiling"
		@sleep 0.5
		@echo "$(NAME) is ready"

$(obj_dir)/%.o: $(src)
		@mkdir -p $(obj_dir)
		@$(CCF) $(GDB) $(INC) -c $(filter %/$*.c, $(src)) -o $@

#MANDATORY BUILD
##########################################
#BONUS BUILD

bonus: $(obj_b)
		@$(CCF) $(INC) $^ -o $(NAME_B)
		@echo "compiling"
		@sleep 0.5
		@echo "$(NAME_B) is ready"

$(obj_dir_b)/%.o: $(src_b)
		@mkdir -p $(obj_dir_b)
		@$(CCF) $(GDB) $(INC) -c $(filter %/$*.c, $(src_b)) -o $@


clean:
		@rm -rf $(obj_dir) $(obj_dir_b)
		@rm -f $(obj) $(obj_b)
		@echo "cleaning..."


fclean: clean
		@rm -f $(NAME) $(NAME_B)
		@echo "cleaning program..."


re: fclean all

bre: fclean bonus

clear: all bonus clear
		@rm -rf $(obj_dir) $(obj_dir_b)

norm:
		@norminette $(src) $(src_b) includes/

show:
	@echo $(src_b)
	@echo "------------"
	@echo $(obj_b)
