/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgiovana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 15:31:39 by mgiovana          #+#    #+#             */
/*   Updated: 2023/10/20 12:41:45 by mgiovana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_all_ate(t_args **args)
//controlla se ha finito di mangiare
{
	int	done;

	pthread_mutex_lock((*args)->death);
	done = 1;
	if ((*args)->max_time_eat && ++(*args)->times_ate == (*args)->max_time_eat)
	{
		*((*args)->status) = 0;
		done = 0;
	}
	else if (!(*args)->max_time_eat && *((*args)->status) == 0)
		done = 0;
	pthread_mutex_unlock((*args)->death);
	return (done);
}

int	philos_thread(t_philo **philo)
//crea i thread, fa il join e poi distrugge i mutex
{
	int	i;

	i = -1;
	while (++i < (*philo)->nphilo)
		if (pthread_create(&(*philo)->thread[i],
				NULL, &routine, &(*philo)->args[i]))
			return (printf("Thread Error\n"));
	philo_is_death(philo);
	i = -1;
	while (++i < (*philo)->nphilo)
		pthread_join((*philo)->thread[i], NULL);
	i = -1;
	while (++i < (*philo)->nphilo)
		pthread_mutex_destroy(&(*philo)->forks[i]);
	pthread_mutex_destroy(&(*philo)->print);
	pthread_mutex_destroy(&(*philo)->death);
	return (0);
}
