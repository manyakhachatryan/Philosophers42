#include "philosophers.h"


void *ft_thread_hendler(void *ph)
{
	t_philo	*philo;
	
	printf("df\n");
	philo =(t_philo*)ph;
	if (philo->id % 2)
		usleep(10000);
while (1)
	 {	
	 	go_take_fork(philo);
	// 	//go_to_sleep();
	// 	//printf("Is thinking")
	}
 return(0);
}


int	create_philo(t_philo_gen	*philo_gen)
{
	int i;

	i = 0;
	while (i < philo_gen->num_of_philo)
	{
	philo_gen->philo[i].start_time = ft_time();
		if (!(pthread_create(&(philo_gen->philo[i].thread_id), NULL,ft_thread_hendler, ((void *)&(philo_gen->philo[i])))))
				i++;
		else
			return (1);
	}
	//if_philo_died(philo_gen,philo_gen->philo );
	return (0);
}

int	init_philo(t_philo_gen *philo_gen)
{
	int index;

	index = 0;

	philo_gen->philo = malloc(sizeof(t_philo) * philo_gen->num_of_philo);
	philo_gen->forks_gen = malloc(sizeof(pthread_mutex_t) * philo_gen->num_of_philo);
	if (!(philo_gen->philo))
		return (1);
	while (index < philo_gen->num_of_philo)
	{
		philo_gen->philo[index].id = index;
		philo_gen->philo[index].left_fork = index;
		philo_gen->philo[index].right_fork = (index + 1) % philo_gen->num_of_philo;
		philo_gen->philo[index].philo_forks = philo_gen->forks_gen; 
		//philo_gen->philo[index].philo_gen = philo_gen;
		index++;
	}
	
	return (0);                                                                                                                                                                                                                
}

int	create_mutex(t_philo_gen	*philo_gen)
{
	int	index;

	index = 0;
	// if(pthread_mutex_init(&philo_gen->eating, NULL))
	// 		return (1);
	philo_gen->forks_gen = malloc(sizeof(pthread_mutex_t) * philo_gen->num_of_philo);
	if (!(philo_gen->forks_gen))
		return (1);
	while (index < philo_gen->num_of_philo)
	{ 
		if(pthread_mutex_init(&philo_gen->forks_gen[index], NULL))
			return (1);
		index++;			
	}
	return (0);
}