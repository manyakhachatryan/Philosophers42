#include "philosophers.h"

int	check_arg(char **arg_str)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (arg_str[i])
	{
		j = 0;
		while (arg_str[i][j])
		{
			if ((arg_str[i][j] >= '0' && arg_str[i][j] <= '9'))
				j++;
			else
				if ((arg_str[i][j] == '+') && (arg_str[i][j + 1] >= '0'
					&& arg_str[i][j + 1] <= '9'))
					j++;
			else
				return (1);
		}
			i++;
	}
	return (0);
}