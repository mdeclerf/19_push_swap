NAME_PS		=	push_swap
NAME_CHK	=	checker

CC	=	gcc

CFLAGS	=	-Wall -Wextra -Werror

INCLUDE = -I./includes

SRCS_PS	=	errors.c					\
			ft_atoi.c					\
			libft.c						\
			list_utils.c				\
			list_utils_bis.c			\
			push.c						\
			rotate.c					\
			rotateR.c					\
			swap.c						\
			main.c						\
			struct_init_free.c			\
			get_next_line.c				\
			two_three.c					\
			four_five.c					\
			stack_utils.c				\
			sort_big.c					\
			sort_big_mute_sort.c		\
			sort_big_binary.c			\

SRCS_CHK =	errors.c					\
			ft_atoi.c					\
			libft.c						\
			list_utils.c				\
			list_utils_bis.c			\
			push.c						\
			rotate.c					\
			rotateR.c					\
			swap.c						\
			struct_init_free.c			\
			checker.c					\
			get_next_line.c				\
			stack_utils.c				\


OBJS_PS		=	$(SRCS_PS:.c=.o)
OBJS_CHK	=	$(SRCS_CHK:.c=.o)

$(NAME_PS):		$(OBJS_PS)
				@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS_PS) -o $(NAME_PS)

$(NAME_CHK):	$(OBJS_CHK)
				@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS_CHK) -o $(NAME_CHK)

all :		$(NAME_CHK) $(NAME_PS)

clean:		
			@rm -f $(OBJS_CHK)
			@rm -f $(OBJS_PS)
			
fclean:		clean
			@rm -f $(NAME_PS)
			@rm -f $(NAME_CHK)

re:			fclean all