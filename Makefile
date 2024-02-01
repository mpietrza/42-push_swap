# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpietrza <mpietrza@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/18 14:21:04 by mpietrza          #+#    #+#              #
#    Updated: 2024/02/01 12:57:33 by mpietrza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long
DIR_LIBFT	= ./libft/
DIR_SRCS	= ./srcs/
DIR_OBJS	= ./objs/
DIR_INCL	= ./include/
LIBFT		= $(DIR_LIBFT)libft.a
INCLUDE		= so_long.h
CC			= cc
CFLAGS		= -Wall -Wextra -Werror #-fsanitize=address -g
RM			= rm -f

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

#SOURCES

SRC			= cleanup.c \
			  exit.c \
			  initialize.c \
			  push_swap.c \
			  utils.c
			 
SRCS		= $(addprefix $(DIR_SRCS), $(SRC))

OBJS		= $(addprefix $(DIR_OBJS), $(SRC:.c=.o))

DEPS		= $(OBJS:.o=.d)

all:	$(DIR_OBJS) $(NAME)

-include $(DEPS)

$(DIR_OBJS)%.o : $(DIR_SRCS)%.c
	@echo $(B)Compiling [$<]... $(DEF_COLOR)
	$(CC) $(CFLAGS) -MMD -MP -Imlx -c -o $@ $<

utils:
	@echo $(B)
	make -C $(DIR_LIBFT)
	@echo $(DEF_COLOR)

$(DIR_OBJS):
	@echo Creating directory: $(DIR_OBJS)
	mkdir -p $(DIR_OBJS)

$(NAME): $(OBJS) Makefile
	$(MAKE) utils
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo $(G)Push_swap compiled successfully! $(DEF_COLOR)

clean:
	make -C $(DIR_LIBFT) clean 
	$(RM) -rf $(OBJS) $(DEPS) $(DIR_OBJS)
	@echo $(GRAY)Push_swap object files erased succesfully! $(DEF_COLOR)

fclean: clean
	make -C $(DIR_LIBFT) fclean
	$(RM) $(NAME)
	@echo $(GRAY)Push_swap executable files erased succesfully! $(DEF_COLOR)
	
re:		fclean all
	@echo $(G)Erased and recompiled every file of push_swap successfully!	$(DEF_COLOR)

debug:
	@echo "Source files: $(SRCS)"
	@echo "Object files: $(OBJS)"
	@echo "Dependency files: $(DEPS)"

.PHONY: all clean fclean re debug
