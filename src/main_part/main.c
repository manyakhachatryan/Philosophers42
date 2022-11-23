#include "philosophers.h"

int	main(int arg_nb, char **arg_str)
{
t_philo_gen	*philo_gen;

	philo_gen = malloc(sizeof(t_philo_gen));
	if (arg_nb == 5 || arg_nb == 6)
	{
		if (check_arg(arg_str)) //parsing
			error("CHECK_ARG_ERROR");
		if(initialize(philo_gen, arg_str, arg_nb))
			return (0);
		if (check_argv_rul(philo_gen))
			return(0);
		if (init_all(philo_gen))
			error("INIT_PARAMS_ERROR");
	}
	else
		error("main_ERROR");
	return (0);
}
