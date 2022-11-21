
#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo		t_philo;
typedef struct s_philo_gen	t_philo_gen;

struct s_philo
{
	int				id;
	int				left_fork;
	int				right_fork;
	pthread_t		thread_id;    
	long long	    start_time;
	long long		last_eat_time;
	pthread_mutex_t	*philo_forks;
	pthread_mutex_t	write;
};

struct s_philo_gen
{
	int				num_of_philo;
	int				time_to_die ;
	int				time_to_eat;
	int				time_to_sleep;
	int				philo_must_eat;
	int				check_die;
	t_philo			*philo;
	pthread_mutex_t	*forks_gen;
};

int			check_arg(char **arg_str);
int			initialize(t_philo_gen *philo_gen, char **argv, int argc);
int			error(char *str);
int			ft_strlen(char *str);
int			ft_atoi(char *str);
int			init_all(t_philo_gen *philo_gen);
int			create_mutex(t_philo_gen	*philo_gen);
int			init_philo(t_philo_gen *philo_gen);
int			create_philo(t_philo_gen *philo_gen);
void		*ft_thread_hendler(void *ph);
int			go_take_fork(t_philo *philo);
long long	ft_time(void);
void	ft_printf(char *str, t_philo *philo);

#endif
