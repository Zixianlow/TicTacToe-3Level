# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/19 17:17:14 by lzi-xian          #+#    #+#              #
#    Updated: 2023/08/17 20:04:01 by lzi-xian         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	tictactoe
SRC_DIR     =   srcs/
OBJS_DIR    =   objs/
MAN_FILES	=	ft_render			\
				ft_utils			\
				ft_fill				\
				ft_itoa				\
				main			
OBJS 		=	$(SRCS:.c=.o)
SRCS        =	$(addprefix $(SRC_DIR), $(addsuffix .c, $(MAN_FILES)))
OBJS        =	$(addprefix $(OBJS_DIR), $(addsuffix .o, $(MAN_FILES)))
ARCR		= 	ar cr 
RMRF		=	rm -rf
CFLAGS		=	-Wall -Wextra -Werror -fsanitize=address -g3
GCC			=	gcc

all:
	@mkdir -p $(OBJS_DIR)
	@make $(NAME)

$(OBJS_DIR)%.o:	$(SRC_DIR)%.c
	@$(GCC) ${RLINC} -c $< -o $@

$(NAME):	${OBJS}
	${GCC} ${CFLAGS} ${OBJS} -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	
clean:
	${RMRF} ${OBJS} ${OBJS_DIR}

fclean:	clean
	${RMRF}	$(NAME)

re:	fclean all