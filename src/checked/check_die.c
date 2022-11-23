#include "philosophers.h"

int	check_die(t_philo_gen *philo_gen, t_philo *philo)
{
  
	int					i;
	i = 0;
	
	while (1)
	{
		i = 0;
		while (i < philo_gen->num_of_philo)
		{
			if (ft_time() - philo[i].fix_time > philo_gen->time_to_die)
			{
				ft_printf("has DIED", &philo_gen->philo[i]);
				return(1) ;
			}
			i++;
		}
	}
	return (0);
}
