/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgiovana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 14:11:26 by mgiovana          #+#    #+#             */
/*   Updated: 2023/10/20 12:41:56 by mgiovana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
/* gettimeofday ti ritorna un valore di tempo in millisecondi
tv_sec restituisce questo stesso valore in secondi, va quindi moltiplicato
per 1000, invece tv_usec ti restituisce il valore in microsecondi e va quindi
diviso per 1000*/
long int	ft_time(time_t start, suseconds_t ustart)
{
	struct timeval	t1;

	gettimeofday(&t1, NULL);
	return (((t1.tv_sec - start) * 1000 + (t1.tv_usec - ustart) / 1000));
}
