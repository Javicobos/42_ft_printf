# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcobos-d <jcobos-d@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/04 18:44:02 by jcobos-d          #+#    #+#              #
#    Updated: 2022/02/04 18:47:45 by jcobos-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_printf.c

B_SRC	=	ft_printf.c 

OBJS	=	${SRCS:.c=.o}

B_OBJS	=	${B_SRC:.c=.o}

NAME	=	libftprintf.a

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

# COLORS

BLACK				=	\033[0;30m
RED					=	\033[0;31m
GREEN				=	\033[0;32m
YELLOW				=	\033[0;33m
BLUE				=	\033[0;34m
MAGENTA				=	\033[0;35m
CYAN				=	\033[0;36m
RESET				=	\033[0m

.c.o:
			@echo "${BLUE}Building $@${RESET}"
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			@echo "${CYAN}Making $@${RESET}"
			ar rcs ${NAME} ${OBJS}
			@echo "${GREEN}✨ Complete! $@ created ✨${RESET}"


all:		${NAME}

clean:
			@rm -f ${OBJS} ${B_OBJS}
			@echo "${GREEN}Objects cleaned${RESET}"

fclean:		clean
			@rm -f ${NAME}
			@echo "${GREEN}Binary cleaned${RESET}"


re:			fclean all

bonus:		${B_OBJS}
			@make OBJS="${B_OBJS}" all

.PHONY:		all clean fclean re bonus