NAME := push_swap

OBJS := control.o main.o reverse_rotate.o rotate.o split.o swap_push.o utils.o position.o merge_sort.o algoritm.o algoritm2.o  init.o node_with_less_move.o push_the_node_founded.o utils_2.o

FLAGS := -Wall -Werror -Wextra

RED = \033[1;31m
LIGHT_BLUE = \033[1;94m
PURPLE = \033[1;35m
ORANGE = \033[0;33m
DEFAULT = \033[0m

all: $(NAME)
%.o : %.c
	@gcc $(FLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	@gcc $(FLAGS) -o $(NAME) $(OBJS)
	@echo "$(PURPLE)$(NAME) created!$(DEFAULT)"


clean:
	@rm -f $(OBJS)
	@echo "$(RED)object files deleted!$(DEFAULT)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(ORANGE) all deleted!$(DEFAULT)"

re: fclean all
