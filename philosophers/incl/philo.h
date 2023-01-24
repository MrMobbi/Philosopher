/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:35:13 by mjulliat          #+#    #+#             */
/*   Updated: 2023/01/24 17:05:44 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define MAX_INT "2147483647"

typedef struct s_list {
	int				name;
	int				alive;
	long			start;
	long			curent;
	struct s_list	*next;
	struct s_list	*previous;
	struct s_list	*left;
	pthread_t		thread_id;
	pthread_mutex_t	fork_id;
	struct s_rules	*rules;
}					t_list;

typedef struct s_rules {
	int		nbr_philo;
	int		t_die;
	int		t_eat;
	int		t_sleep;
	int		n_meal;
	t_list	*start;
}			t_rules;

//		##### Ft_Error.c #####
int		ft_error(int ac, char **av);
void	ft_display_error(int code_error, int arg);
void	ft_display_error_launch(int code_error);

//		##### Ft_Check_Error.c #####
int		ft_check_error(char *str);
int		ft_check_if_digit(char *str);
int		ft_check_max_int(char *str);

//		##### Ft_Init_Data.c #####
void	ft_init_data(char **av, t_rules *rules);

//		##### Ft_Launcher.c #####
int		ft_launcher(t_rules *rules);
int		ft_exit(t_rules *rules);
void	*routine(void *arg);

//		##### Ft_Philo_Status.c #####
void	ft_think(t_list *philo);
void	ft_eat(t_list *philo);
void	ft_sleep(t_list *philo);

//		##### Utils.c #####
int		ft_atoi(char *str);
int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);
void	ft_putstr(char *str);
long	ft_get_timestamp(void);

//		##### Utils_List.c #####
t_list	*ft_lstnew(t_rules *rules, int name);
void	ft_lstadd_back(t_list **lst, t_list *nw);
void	ft_add_left_and_right(t_rules *rules);
void	ft_free_lst(t_list *list);

#endif
