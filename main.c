/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgiovana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:25:03 by mgiovana          #+#    #+#             */
/*   Updated: 2023/10/20 12:40:43 by mgiovana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free(t_philo **philo)
{
	free((*philo)->args);
	free((*philo)->thread);
	free((*philo)->forks);
	free((*philo)->last);
	free(*philo);
}

int	main(int argc, char **argv)
{
	t_philo	*philo;

	if (argc == 5 || argc == 6)
	{
		philo = ft_calloc(sizeof(t_philo), 1);
		if (ft_args_manage(&philo, argc, argv))
			return (1);
		if (!philos_thread(&philo))
			ft_free(&philo);
	}
	else
		printf("Insert valid arguments\n");
	return (1);
}
