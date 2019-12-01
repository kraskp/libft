# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkraszew <kkraszew@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/17 13:56:16 by kkraszew          #+#    #+#              #
#    Updated: 2019/12/01 14:31:50 by kkraszew         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

INC = -I ./includes/

FLAGS = -Wall -Wextra -Werror

SRCS_NAME	= ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memccpy.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strlen.c \
			ft_strlen.c \
			ft_strdup.c \
			ft_strcpy.c \
			ft_strncpy.c \
			ft_strcat.c \
			ft_strncat.c \
			ft_strlcat.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strstr.c \
			ft_strnstr.c \
			ft_strcmp.c \
			ft_strncmp.c \
			ft_atoi.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_memalloc.c \
			ft_memdel.c \
			ft_strnew.c \
			ft_strdel.c \
			ft_strclr.c \
			ft_strmap.c \
			ft_putchar.c \
			ft_putstr.c \
			ft_putnbr.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strmapi.c \
			ft_strequ.c \
			ft_strnequ.c \
			ft_strsub.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_strsplit.c \
			ft_putstr_fd.c \
			ft_putchar_fd.c \
			ft_itoa.c \
			ft_putendl_fd.c \
			ft_putendl.c \
			ft_putnbr_fd.c \
			ft_lstnew.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_lstaddfront.c \
			ft_lstaddend.c \
			ft_lstpush.c \
			ft_lstdel.c \
			ft_lstprint.c \
			ft_lstaddnext.c \
			ft_isupper.c \
			ft_islower.c \
			ft_iswspace.c \
			ft_xint.c \
			ft_isblank.c \
			ft_print_bits.c \
			ft_swap_bits.c \
			ft_reverse_bits.c \
			ft_print_hex.c \
			ft_get_next_line.c \
			ft_array_new.c \
			ft_array_pop.c \
			ft_array_print.c \
			ft_array_max_value.c \
			ft_array_copy.c \
			ft_array_rotate_left.c \
			ft_array_rotate_right.c \
			ft_widelen.c \
			ft_itoa_base.c \
			ft_puthex.c \
			ft_putull.c \
			ft_putoct.c \
			ft_putunbr.c \
			ft_putadr.c \
			ft_putlong.c \
			ft_sqrt.c \
			ft_putwstrf.c \
			ft_putstrf.c \
			ft_numlen.c \
			ft_numulen.c \
			ft_numullen.c \
			ft_putnbrf.c \
			ft_ustrlen.c \
			ft_ustrnlen.c \
			ft_strudup.c \
			ft_ustrdup.c \
			ft_countwchar.c \
			ft_printtab.c \
			ft_max.c \
			ft_abs.c \
			ft_printf.c \
			pf_conv_int.c \
			pf_conv_char.c \
			pf_conv_double.c \
			pf_conv_string.c \
			pf_conv_other.c \
			pf_lst_init.c \
			pf_lst_putdouble.c \
			pf_lst_putoption.c \
			pf_buff_man.c \
			pf_utils.c \
			pf_put_string.c \
			pf_put_color.c

SRCS_PATH = srcs/
OBJ_PATH  = obj/

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(SRCS_NAME:.c=.o))

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[32mBinary \033[1;32m$(NAME)\033[1;0m\033[32m created!\033[0m"

$(OBJ_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p obj
	@gcc -c $(FLAGS) $(INC) $< -o $@
	@echo "\033[0;34m\033[1mCompiling \033[1m\033[36m$(notdir $<)\033[1m\033[34m done.\033[0m"

clean:
	@/bin/rm -rf $(OBJ_PATH)
	@echo "\033[31mObject files\033[1;31m$(OBJS_LIST)\033[1;0m\033[31m removed.\033[0m"

fclean: clean
	@/bin/rm -rf $(NAME)
	@echo "\033[31mBinary \033[1;31m$(NAME)\033[1;0m\033[31m removed.\033[0m"

re: fclean all

.PHONY: all, clean, fclean, re