/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgiovana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 14:01:26 by mgiovana          #+#    #+#             */
/*   Updated: 2023/10/20 12:07:08 by mgiovana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* usleep funziona in microsecondi e visto che 
noi passiamo valori in millisecondi il valore 
va moltiplicato per 1000*/

void	print_action(long int time, int id, pthread_mutex_t *print, char flag)
{
	static int	stop = 0;

	pthread_mutex_lock(print);
	if (flag == 'D' && stop == 0)
	{
		printf("%ld %d died\n", time, id);
		stop = 1;
	}
	else if (flag == 'T' && stop == 0)
		printf("%ld %d is thinking\n", time, id);
	else if (flag == 'E' && stop == 0)
		printf("%ld %d is eating\n", time, (id));
	else if (flag == 'F' && stop == 0)
		printf("%ld %d has taken a fork\n", time, id);
	else if (flag == 'S' && stop == 0)
		printf("%ld %d is sleeping\n", time, id);
	pthread_mutex_unlock(print);
}

void	philo_is_death(t_philo **philo)
{
	int			i;
	long int	time;

	while (1)
	{
		i = -1;
		pthread_mutex_lock(&(*philo)->death);
		time = ft_time((*philo)->time_sec, (*philo)->time_usec);
		if ((*philo)->status == DEATH)
			break ;
		while (++i < (*philo)->nphilo)
		{
			if ((*philo)->time_to_die < (time - (*philo)->last[i]))
			{
				(*philo)->status = DEATH;
				print_action(time, (i + 1), &(*philo)->print, 'D');
				break ;
			}
		}
		pthread_mutex_unlock(&(*philo)->death);
		usleep(5000);
	}
	pthread_mutex_unlock(&(*philo)->death);
}

void	ft_pick_forks(t_args **args)
{
	pthread_mutex_lock((*args)->left_f);
	print_action(ft_time((*args)->time_sec, (*args)->time_usec),
		(*args)->id, (*args)->print, 'F');
	pthread_mutex_lock((*args)->right_f);
	print_action(ft_time((*args)->time_sec, (*args)->time_usec),
		(*args)->id, (*args)->print, 'F');
	ft_eat(args);
	pthread_mutex_unlock((*args)->right_f);
	pthread_mutex_unlock((*args)->left_f);
}

void	ft_sleep(t_args **args, int type)
{
	long int	now;

	now = ft_time((*args)->time_sec, (*args)->time_usec);
	while (ft_time((*args)->time_sec, (*args)->time_usec) - now < (long)type)
		usleep(50);
}

void	ft_eat(t_args **args)
{
	pthread_mutex_lock((*args)->death);
	(*args)->last_arr[(*args)->id - 1] = ft_time((*args)->time_sec,
			(*args)->time_usec);
	pthread_mutex_unlock((*args)->death);
	print_action(ft_time((*args)->time_sec, (*args)->time_usec),
		(*args)->id, (*args)->print, 'E');
	ft_sleep(args, (*args)->time_to_eat);
}
