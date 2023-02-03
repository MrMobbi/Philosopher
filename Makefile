# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjulliat <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/01 12:18:20 by mjulliat          #+#    #+#              #
#    Updated: 2023/02/03 11:55:44 by mjulliat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	### COMPILATION ###

CC			= gcc -pthread -fsanitize=address
FLAGS		= -Wall -Werror -Wextra

	### EXECUTABLE ###

NAME		= philo
N_BONUS		= philo_bonus

	### INCLUDES ###

SRCS_PATH	= philosophers/srcs
OBJS_PATH	= philosophers/objs

HEADERS		= philosophers/incl

	### INCLUDE BONUS ###

SRCB_PATH	= philosophers_bonus/srcs
OBJB_PATH	= philosophers_bonus/objs

HEADERS_B	= philosophers_bonus/incl

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

	### SOURCES BONNUS ###

SOURCES_B	= main_bonus.c\
			  utils_bonus.c\
			  ft_error_bonus.c\
			  ft_check_error_bonus.c\
			  ft_init_data_bonus.c\
			  ft_time_bonus.c\
			  ft_launcher_bonus.c\
			  ft_philo_status_bonus.c

	### OBJECTS ###

SRCS		= $(addprefix $(SRCS_PATH)/,$(SOURCES))
OBJS		= $(addprefix $(OBJS_PATH)/,$(SOURCES:.c=.o))

	### OBJECTS BONUS ###

SRCS_B		= $(addprefix $(SRCB_PATH)/,$(SOURCES_B))
OBJS_B		= $(addprefix $(OBJB_PATH)/,$(SOURCES_B:.c=.o))

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
			@echo "$(BLUE)######## Compiling Project ######### $(WHITE)"
			$(CC) $(FLAGS) -o $@ $^ 
			@echo "$(GREEN)######## Project Compilated ######## $(WHITE)"

tmp:		
			@echo "$(BLUE)######## Compiling SRCS in OBJS ######## $(WHITE)"
			@mkdir -p philosophers/objs

$(OBJS_PATH)/%.o:	$(SRCS_PATH)/%.c
					$(CC) $(FLAGS) -I$(HEADERS) -c $< -o $@

clean:	
			@echo "$(VIOLET)######## Supressing files and library ######## $(YELLOW)"
			rm -rf $(OBJS_PATH)
			rm -rf $(OBJB_PATH)

fclean:		clean
			rm -rf $(NAME)
			rm -rf $(N_BONUS)

re:			fclean all

bonus:		tmp_b $(N_BONUS)

$(N_BONUS):		$(OBJS_B)
			@echo "$(BLUE)######## Compiling Project ######### $(WHITE)"
			$(CC) $(FLAGS) -o $@ $^ 
			@echo "$(GREEN)######## Project Compilated ######## $(WHITE)"

tmp_b:		
			@echo "$(BLUE)######## Compiling SRCS in OBJS ######## $(WHITE)"
			@mkdir -p philosophers_bonus/objs

reb:		fclean bonus

$(OBJB_PATH)/%.o:	$(SRCB_PATH)/%.c
					$(CC) $(FLAGS) -I$(HEADERS_B) -c $< -o $@

.PHONY:		clean, fclean, re, printf, tmp, all, philo
