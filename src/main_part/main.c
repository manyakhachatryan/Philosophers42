/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manykhac <manykhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:55:19 by manykhac          #+#    #+#             */
/*   Updated: 2022/11/28 15:55:21 by manykhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int arg_nb, char **arg_str)
{
	t_philo_gen	*philo_gen;

	philo_gen = malloc(sizeof(t_philo_gen));
	if (arg_nb == 5 || arg_nb == 6)
	{
		if (check_arg(arg_str))
			error("CHECK_ARG_ERROR");
		else if (initialize(philo_gen, arg_str, arg_nb))
			return (0);
		else if (check_argv_rul(philo_gen))
			return (0);
		else if (init_all(philo_gen))
			error("INIT_PARAMS_ERROR");
	}
	else
		error("TOO MANY ARGUMENTS");
	return (0);
}
