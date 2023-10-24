/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgiovana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:25:03 by mgiovana          #+#    #+#             */
/*   Updated: 2023/09/14 15:18:19 by mgiovana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str++;
	}
	return (res * sign);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	char	*str;
	size_t	i;

	i = -1;
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	str = (char *)ptr;
	while (++i < (nmemb * size))
		str[i] = '\0';
	return (ptr);
}
