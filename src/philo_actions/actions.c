#include "philosophers.h"


int	go_take_fork(t_philo *philo)
{
	pthread_mutex_lock(&(philo->philo_forks[philo->right_fork]));
	printf("time -> %lld ,%d has taken a right fork\n", ft_time() - philo->start_time, philo->id);
	pthread_mutex_lock(&(philo->philo_forks[philo->left_fork]));
	printf("time -> %lld ,%d has taken a left fork\n", ft_time() - philo->start_time, philo->id);
	//go_to_eat(philo);
	printf("time -> %lld ,%d thinking\n", ft_time() - philo->start_time, philo->id);
	pthread_mutex_unlock(&(philo->philo_forks[philo->right_fork]));
	pthread_mutex_unlock(&(philo->philo_forks[philo->left_fork]));
	return (0);
}