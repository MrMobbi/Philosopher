# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjulliat <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/01 12:18:20 by mjulliat          #+#    #+#              #
#    Updated: 2023/01/26 17:42:21 by mjulliat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	### COMPILATION ###

CC			= gcc -g -pthread -fsanitize=address
FLAGS		= -Wall -Werror -Wextra

	### EXECUTABLE ###

NAME		= philo
NAME_BONUS	= philo_bonus

	### INCLUDES ###

SRCS_PATH	= philosophers/srcs
OBJS_PATH	= philosophers/objs

HEADERS		= philosophers/incl

	### SOURCE FILE ###

SOURCES		= main.c\
			  utils.c\
			  utils_list.c\
			  ft_error.c\
			  ft_check_error.c\
			  ft_init_data.c\
			  ft_launcher.c\
			  ft_philo_status.c\
			  ft_time.c\
			  ft_mutex_and_exit.c\
			  ft_philo_watcher.c

	### OBJETCTS ###

SRCS		= $(addprefix $(SRCS_PATH)/,$(SOURCES))
OBJS		= $(addprefix $(OBJS_PATH)/,$(SOURCES:.c=.o))

	### COLORS ###

RED			= \033[1;31m
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
BLUE		= \033[1;34m
VIOLET		= \033[1;35m
CYAN		= \033[1;36m
NOC			= \033[0m
WHITE		= \033[1;37m

	### RULES ###

all:		tmp $(NAME)

$(NAME):	$(OBJS)
			@echo "$(BLUE)######## Obect file Created ######### $(WHITE)"
			$(CC) $(FLAGS) -o $@ $^ 
			@echo "$(GREEN)######## Project Compilated ######## $(WHITE)"

tmp:		
			@mkdir -p philosophers/objs

$(OBJS_PATH)/%.o:	$(SRCS_PATH)/%.c
					$(CC) $(FLAGS) -I$(HEADERS) -c $< -o $@

clean:	
			@echo "$(VIOLET)######## Supressing files and library ######## $(YELLOW)"
			@rm -rf $(OBJS_PATH)

fclean:		clean
			@rm -rf $(NAME)

re:			fclean all

.PHONY:		clean, fclean, re, printf, tmp, all, philo
