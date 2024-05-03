# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/03 17:24:21 by mpietrza          #+#    #+#              #
#    Updated: 2024/05/03 17:24:25 by mpietrza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC  = cc

CFLAGS = -Wall -Wextra -Werror

#COLORS
DEF_COLOR = "\033[39m"
GRAY = "\033[30m"
R = "\033[31m"
G = "\033[32m"
Y = "\033[33m"
B = "\033[34m"
M = "\033[35m"
C = "\033[36m"
W = "\033[37m"

SRC = ft_atoi.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_itoa.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_split.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strmapi.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strtrim.c \
	ft_substr.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_printf.c \
	ft_print_char.c \
	ft_print_perc.c	\
	ft_print_unsigned.c \
	ft_print_hex.c \
	ft_print_ptr.c \
	ft_print_int.c \
	ft_print_str.c \
	get_next_line.c \
	get_next_line_utils.c \

SRC_BONUS = ft_lstadd_back.c \
			ft_lstadd_front.c \
			ft_lstclear.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstlast.c \
			ft_lstmap.c \
			ft_lstnew.c \
			ft_lstsize.c \

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) libft.h Makefile 
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	@echo $(G)Libft compiled successfully! $(DEF_COLOR)

bonus: $(OBJ_BONUS) libft.h Makefile
	ar rc $(NAME) $(OBJ_BONUS)
	ranlib $(NAME)

%.o: %.c
	@echo $(B)Compiling [$<]... $(DEF_COLOR)	
	@printf $(Y) 
	$(CC) -c $(CFLAGS) $^
	@echo $(DEF_COLOR)

clean:
	@echo $(GRAY)
	rm -f $(OBJ) #$(OBJ_BONUS)
	@echo $(G)Libft object files erased successfully! $(DEF_COLOR)

fclean: clean
	@echo $(GRAY)
	rm -f $(NAME)
	@echo $(G)Libft executable files erased successfully! $(DEF_COLOR)

re: fclean all
	@echo $(G)Erased and recompiled every file of libft successfully! $(DEF_COLOR)

.PHONY: all clean fclean re bonus
