/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgiovana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:02:44 by mgiovana          #+#    #+#             */
/*   Updated: 2023/10/19 12:07:45 by mgiovana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args(char **argv)
{
	int	x;
	int	i;

	i = 0;
	while (argv[++i])
	{
		x = ft_atoi(argv[i]);
		if (x <= 0)
			return (printf("Error on input\n"));
	}
	return (0);
}

void	fork_assing(t_philo **philo, int i)
{
	if ((*philo)->args[i].id == (*philo)->nphilo)
	{
		(*philo)->args[i].left_f = &(*philo)->forks[0];
		(*philo)->args[i].right_f = &(*philo)->forks[i];
	}
	else
	{
		(*philo)->args[i].left_f = &(*philo)->forks[i];
		(*philo)->args[i].right_f = &(*philo)->forks[i + 1];
	}
}
/* funzione che riempie le strutture dei filosofi
passando tutta la struttura data*/

void	fill_struct(t_philo **philo, int ac, char **av)
{
	int				i;

	i = -1;
	while (++i < (*philo)->nphilo)
	{
		(*philo)->args[i].id = i + 1;
		(*philo)->args[i].n_philo = (*philo)->nphilo;
		(*philo)->args[i].time_to_die = ft_atoi(av[2]);
		(*philo)->args[i].time_to_eat = ft_atoi(av[3]);
		(*philo)->args[i].time_to_sleep = ft_atoi(av[4]);
		(*philo)->args[i].time_sec = (*philo)->time_start.tv_sec;
		(*philo)->args[i].time_usec = (*philo)->time_start.tv_usec;
		(*philo)->args[i].print = &(*philo)->print;
		(*philo)->args[i].death = &(*philo)->death;
		(*philo)->args[i].status = &(*philo)->status;
		(*philo)->args[i].max_time_eat = 0;
		(*philo)->args[i].times_ate = 0;
		(*philo)->args[i].last_arr = (*philo)->last;
		if (ac == 6)
			(*philo)->args[i].max_time_eat = ft_atoi(av[5]);
		fork_assing(philo, i);
	}
}

int	ft_args_manage(t_philo **philo, int argc, char **argv)
{
	int	i;

	if (check_args(argv))
		return (1);
	gettimeofday(&(*philo)->time_start, NULL);
	(*philo)->nphilo = ft_atoi(argv[1]);
	(*philo)->time_to_die = ft_atoi(argv[2]);
	(*philo)->time_sec = (*philo)->time_start.tv_sec;
	(*philo)->time_usec = (*philo)->time_start.tv_usec;
	(*philo)->last = ft_calloc(sizeof(long int), (*philo)->nphilo);
	(*philo)->thread = ft_calloc(sizeof(pthread_t), (*philo)->nphilo);
	(*philo)->forks = ft_calloc(sizeof(pthread_mutex_t), ((*philo)->nphilo));
	(*philo)->args = ft_calloc(sizeof(t_args), (*philo)->nphilo);
	(*philo)->status = ALIVE;
	i = -1;
	while (++i < (*philo)->nphilo)
		pthread_mutex_init(&(*philo)->forks[i], NULL);
	pthread_mutex_init(&(*philo)->print, NULL);
	pthread_mutex_init(&(*philo)->death, NULL);
	fill_struct(philo, argc, argv);
	return (0);
}
