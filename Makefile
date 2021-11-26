# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecruz-go <ecruz-go@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/22 19:47:07 by ecruz-go          #+#    #+#              #
#    Updated: 2021/11/26 12:15:51 by ecruz-go         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= pipex
PROG	= pipex

SRCS 	= pipex.c utils.c
SRCS_F 	= sources/
OBJS 	= ${SRCS:.c=.o}
OBJS_F	= _objFiles/
MAIN	= sources/pipex.c

# --- BONUS ---
SRCS_B	= sources/pipex_bonus.c sources/utils.c sources/utils_bonus.c
OBJS_B	= ${SRCS_B:.c=.o}
MAIN_B	= sources/pipex_bonus.c

# --- LIBFT ---
LIBFT_A = libft.a
LIBF_DIR = Libft/
LIBFT  = $(addprefix $(LIBF_DIR), $(LIBFT_A))

HEADER	= -I./includes/

CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror -g

# --- COLORS ---
NONE='\033[0m'
GREEN='\033[32m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'

# --- RULES ---
all:		$(NAME)

$(NAME):

					@echo $(CURSIVE)$(GRAY) "     - Creating object directory..." $(NONE)
					@mkdir -p $(OBJS_F)
					@echo $(CURSIVE)$(GRAY) "     - Making object files..." $(NONE)
					@gcc $(CFLAGS) -c $(addprefix $(SRCS_F), $(SRCS))
					@echo $(CURSIVE)$(GRAY) "     - Moving object files to $(OBJS_F)..." $(NONE)	
					@mv $(OBJS) $(OBJS_F)
					@echo $(CURSIVE)$(GRAY) "     - Compiling Libft..." $(NONE)
					@make -C $(LIBF_DIR)
					@echo $(CURSIVE)$(GRAY) "     - Compiling $(NAME)..." $(NONE)
					@gcc $(FLAGS) $(LIBFT) $(addprefix $(OBJS_F), $(OBJS)) -o $(NAME)
					@echo $(GREEN)"- Pipex Compiled -"$(NONE)

bonus:		${OBJS_B}
					@echo $(CURSIVE)$(GRAY) "     - Compiling Libft..." $(NONE)
					@make re -C ./libft
					@cp Libft/libft.a ./$(NAME)
					@ar -rcs ${NAME} ${OBJS_B}
					@$(CC) $(NAME) ${MAIN_B} -o ${PROG}
					@echo $(GREEN)"Pipex Bonus Compiled!\n"

clean:
					@make clean -C ./libft
					@rm -rf $(OBJS_F)
					@rm -f ${OBJS} ${OBJS_B}

fclean: 	clean
					@make -C $(LIBF_DIR) fclean
					@rm -f $(NAME)
					@rm -f ${PROG}
					@echo "\n\033[31mDeleting EVERYTHING!\n"

re:			fclean all

.PHONY: all clean fclean re bonus