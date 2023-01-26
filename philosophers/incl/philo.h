/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:35:13 by mjulliat          #+#    #+#             */
/*   Updated: 2023/01/26 17:58:33 by mjulliat         ###   ########.fr       */
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
	int				rules_t_die;
	int				rules_t_eat;
	int				rules_t_sleep;
	int				rules_n_meal;
	int				alive;
	int				finish;
	long			last_meal;
	long			start;
	long			now;
	long			curent;
	struct s_list	*next;
	struct s_list	*left;
	pthread_t		thread_id;
	pthread_mutex_t	mutex_fork;
	struct s_rules	*rules;
}					t_list;

typedef struct s_rules {
	int				nbr_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				n_meal;
	int				checker;
	int				check_dead;
	int				check_finish;
	long			check_timer;
	pthread_mutex_t	mutex_timestamp;
	pthread_mutex_t	mutex_read_meal;
	pthread_mutex_t	mutex_alive;
	pthread_mutex_t	mutex_finish;
	t_list			*start;
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
void	*routine(void *arg);

//		##### Ft_Philo_Status.c #####
void	ft_think(t_list *philo);
void	ft_eat(t_list *philo);
void	ft_sleep(t_list *philo);
void	ft_take_fork(t_list *philo);

//		##### Ft_Time.c #####
long	ft_get_timestamp(void);
void	ft_usleep(long time, t_list *philo);

//		##### Ft_Philo_Watcher.c #####
void	ft_looking_for_death(t_rules *rules);
void	ft_hugo(t_rules *rules, long last_meal, long *tmp_last_meal);
void	ft_philo_died(t_rules *rules, int name);
int		ft_check_if_finish(t_rules *rules);

//		##### Ft_Mutex.c #####
int		ft_mutex(t_rules *rules);
int		ft_exit(t_rules *rules);

//		##### Utils.c #####
int		ft_atoi(char *str);
int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);
void	ft_putstr(char *str);

//		##### Utils_List.c #####
t_list	*ft_lstnew(t_rules *rules, int name);
void	ft_lstadd_back(t_list **lst, t_list *nw);
void	ft_add_left(t_rules *rules);
void	ft_free_lst(t_list *list);

#endif
