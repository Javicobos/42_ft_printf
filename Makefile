# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcobos-d <jcobos-d@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/04 18:44:02 by jcobos-d          #+#    #+#              #
#    Updated: 2022/02/07 15:54:35 by jcobos-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	ft_printf.c

B_SRC		=	ft_printf.c 

OBJS		=	${SRCS:.c=.o}

B_OBJS		=	${B_SRC:.c=.o}

NAME		=	libftprintf.a

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror -I ./libft

LIBFT_PATH	=	./libft/

LIBFT		=	$(addprefix $(LIBFT_PATH),libft.a)

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

${NAME}:	${OBJS} ${LIBFT}
			@echo "${CYAN}Copying $(LIBFT) as the base for $@${RESET}"
			cp -p $(LIBFT) $(NAME)
			@echo "${CYAN}Making $@${RESET}"
			ar rcs ${NAME} ${OBJS}
			@echo "${GREEN}✨ Complete! $@ created ✨${RESET}"


${LIBFT}:
			@echo "${CYAN}Making $@${RESET}"
			$(MAKE) -C ${LIBFT_PATH} all

all:		${NAME}

clean:
			@rm -f ${OBJS} ${B_OBJS}
			@$(MAKE) -C $(LIBFT_PATH) clean
			@echo "${GREEN}Objects cleaned from $(CURDIR) ${RESET}"

fclean:		clean
			@rm -f ${LIBFT}
			@echo "${GREEN}Binary ${LIBFT} cleaned${RESET}"
			@rm -f ${NAME}
			@echo "${GREEN}Binary ${NAME} cleaned${RESET}"


re:			fclean all

bonus:		${B_OBJS}
			@make OBJS="${B_OBJS}" all

.PHONY:		all clean fclean re bonus