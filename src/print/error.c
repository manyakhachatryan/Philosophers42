/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manykhac <manykhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:55:45 by manykhac          #+#    #+#             */
/*   Updated: 2022/12/09 15:13:18 by manykhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	error(char *str)
{
	printf("%s\n", str);
	return (1);
}

void	ft_printf(char *str, t_philo *philo)
{
	pthread_mutex_lock(philo->write);
	if (str[0] == 'O' && str[1] == 'K')
	{
		printf("OK\n");
	}
	else
	{
		printf("time -> %lld\t", ft_time() - philo->start_time);
		printf("%d\t", philo->id);
		printf("%s\n", str);
		pthread_mutex_unlock(philo->write);
	}
}
