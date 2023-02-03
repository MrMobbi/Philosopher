/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjulliat <mjulliat@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:35:13 by mjulliat          #+#    #+#             */
/*   Updated: 2023/02/03 11:25:18 by mjulliat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/wait.h>
# include <sys/time.h>
# include <semaphore.h>
# include <signal.h>

# define MAX_INT "2147483647"

typedef struct s_philo {
	int				name;
	long			debut;
	long			now;
	long			curent;
	long			last_meal;
	struct s_rules	*rules;
}					t_philo;

typedef struct s_rules {
	int			nbr_philo;
	int			t_die;
	int			t_eat;
	int			t_sleep;
	int			n_meal;
	long		start;
	int			*pid_philo;
	t_philo		*philo;
	sem_t		*fork;
	sem_t		*write;
	sem_t		*exit;
	sem_t		*dead;
	sem_t		*begin;
}				t_rules;

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
int		ft_init_sem(t_rules *rules);

//		##### Ft_Launcher.c #####
int		ft_launcher(t_rules *rules);
void	ft_routine(t_rules *rules, int name);
void	ft_one_philo(t_philo *philo);

//		##### Ft_Philo_Status.c #####
void	ft_think(t_philo *philo);
void	ft_eat(t_philo *philo);
void	ft_sleep(t_philo *philo);
void	ft_fork_taken(t_philo *philo);
void	ft_dead_or_no(t_philo *philo, long time_action);

//		##### Ft_Time.c #####
long	ft_get_timestamp(void);
void	ft_usleep(long time);

//		##### Main.c #####
void	ft_wait_finish(t_rules *rules);
void	ft_kill_process(t_rules *rules);
int		ft_parent_checker(t_rules *rules);

//		##### Utils.c #####
int		ft_atoi(char *str);
int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);
void	ft_putstr(char *str);

#endif
