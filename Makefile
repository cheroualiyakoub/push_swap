NAME = push_swap
BNAME = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

HFILES = ./headers/push_swap.h
LIBFT = ./libft/libft.a
ODIR = ./odir/
SRCDIR = ./src/

SRC = \
    $(SRCDIR)ps_intit_stacks.c \
	$(SRCDIR)ps_check_digit.c \
	$(SRCDIR)ps_utils.c \
    $(SRCDIR)push_swap.c \
    $(SRCDIR)ps_movement_stack.c \
    $(SRCDIR)ps_sortstack.c \
    $(SRCDIR)ps_frees.c \
    $(SRCDIR)ps_utils_sort.c \
	

OBJ = $(SRC:$(SRCDIR)%.c=$(ODIR)%.o)

all : $(ODIR) $(NAME) 

$(NAME) : $(OBJ)
	@cd libft && make
	@$(CC) $(CFLAGS) $(LIBFT) $(OBJ)  -o $(NAME)

$(ODIR)%.o: $(SRCDIR)%.c
	@mkdir -p $(ODIR)
	@$(CC) $(CFLAGS) -c $< -o $@ 

$(ODIR) :
	@mkdir -p $(ODIR)

clean :
	@cd libft && make clean -silent
	@rm -rf $(ODIR)

fclean : clean
	@cd libft && make fclean -silent
	@rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re leaks
