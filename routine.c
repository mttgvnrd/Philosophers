/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgiovana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:53:53 by mgiovana          #+#    #+#             */
/*   Updated: 2023/10/20 12:41:31 by mgiovana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_args	*args;

	args = (t_args *)arg;
	if (args->n_philo == 1)
		print_action(ft_time(args->time_sec, args->time_usec),
			args->id, args->print, 'F');
	else
	{
		if (args->id % 2 == 0)
			usleep(10000);
		while (1)
		{
			ft_pick_forks(&args);
			print_action(ft_time(args->time_sec, args->time_usec),
				args->id, args->print, 'S');
			ft_sleep(&args, args->time_to_sleep);
			print_action(ft_time(args->time_sec, args->time_usec),
				args->id, args->print, 'T');
			if (!ft_all_ate(&args))
				break ;
		}
	}
	return (0);
}
