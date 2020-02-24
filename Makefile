# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wvenita <wvenita@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/24 01:21:19 by wvenita           #+#    #+#              #
#    Updated: 2020/02/24 12:28:08 by wvenita          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=			libftprintf.a
C				= 		gcc
CFLAGS 	= 		-I includes/ -Wall -Werror -Wextra -O2
OBJ 		= 		$(SRC:.c=.o)

SRC =	src/ft_printf.c						\
		src/print/ft_print_c.c			\
		src/print/ft_print_d.c			\
		src/print/ft_print_d_h.c		\
		src/print/ft_print_d_hh.c		\
		src/print/ft_print_e.c			\
		src/print/ft_print_e_l.c		\
		src/print/ft_print_e_ll.c	\
		src/print/ft_print_f.c			\
		src/print/ft_print_f_l.c		\
		src/print/ft_print_f_ll.c	\
		src/print/ft_print_nb.c			\
		src/print/ft_print_p.c			\
		src/print/ft_print_s.c			\
		src/print/ft_print_arg.c		\
		src/other/ft_add_char.c				\
		src/other/ft_apply_e.c				\
		src/other/ft_condition_fill.c		\
		src/other/ft_condition_flag.c		\
		src/other/ft_convert_output.c		\
		src/other/ft_flaglen.c				\
		src/other/ft_format_is_valid.c		\
		src/other/ft_get_binary.c			\
		src/other/ft_get_color.c				\
		src/other/ft_itoa_e.c				\
		src/other/ft_itoa_f.c				\
		src/other/ft_itoa_f_l.c				\
		src/other/ft_nblen_ull.c				\
		src/other/ft_print_null.c			\
		src/other/ft_size_to_allocate.c		\
		src/other/ft_str_join.c				\
		src/other/ft_str_join_r.c			\
		src/other/ft_str_precision_count.c	\
		src/other/ft_strcat_char.c			\
		src/other/ft_strdup_alloc.c			\
		src/other/ft_ulltoa_offset.c			\
		src/padding/ft_padding_e.c		\
		src/padding/ft_padding_nb.c		\
		src/padding/ft_padding_p.c		\
		src/padding/ft_padding_str.c		\
		src/parser/ft_create_flag.c			\
		src/parser/ft_flag_mzpkh.c			\
		src/parser/ft_flag_pr_width.c		\
		src/precision/ft_precision.c		

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@make -C libft/
	@cp libft/libft.a ./$(NAME)
	@ar rc $@ $^
	@ranlib $@

clean:
	@make clean -C libft/
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)
	@make fclean -C libft/

re: fclean all

.PHONY: all clean fclean re