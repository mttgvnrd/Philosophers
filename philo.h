/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgiovana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:01:10 by mgiovana          #+#    #+#             */
/*   Updated: 2023/10/20 12:41:16 by mgiovana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>

# define SLEEP 1
# define FORK 2
# define EAT 3
# define THINK 4

# define ALIVE 1
# define DEATH 0

typedef struct s_args{
	int						id;
	int						n_philo;
	int						time_to_die;
	int						time_to_eat;
	int						time_to_sleep;
	int						max_time_eat;
	int						times_ate;
	int						*status;
	long int				last_m;
	long int				*last_arr;
	suseconds_t				time_usec;
	time_t					time_sec;
	pthread_mutex_t			*left_f;
	pthread_mutex_t			*right_f;
	pthread_mutex_t			*print;
	pthread_mutex_t			*death;
}				t_args;

typedef struct s_philo{
	t_args					*args;
	int						time_to_die;
	int						status;
	int						nphilo;
	long int				*last;
	pthread_t				*thread;
	pthread_mutex_t			*forks;
	pthread_mutex_t			print;
	pthread_mutex_t			death;
	time_t					time_sec;
	suseconds_t				time_usec;
	struct timeval			time_start;
}				t_philo;
int			ft_args_manage(t_philo **philo, int argc, char **argv);
int			check_args(char **argv);
void		fork_assing(t_philo **philo, int i);
void		fill_struct(t_philo **philo, int ac, char **av);
void		print_action(long int time, int id,
				pthread_mutex_t *print, char flag);
void		*routine(void *arg);
void		ft_pick_forks(t_args **args);
void		ft_sleep(t_args **args, int type);
long int	ft_time(time_t start, suseconds_t ustart);
void		ft_eat(t_args **args);
int			ft_atoi(const char *str);
void		*ft_calloc(size_t nmemb, size_t size);
int			ft_all_ate(t_args **args);
void		philo_is_death(t_philo **philo);
void		ft_free(t_philo **philo);
int			philos_thread(t_philo **philo);

#endif
