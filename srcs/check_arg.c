/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadjigui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 16:34:09 by sadjigui          #+#    #+#             */
/*   Updated: 2021/12/04 16:34:14 by sadjigui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_isnum(char *arg)
{
	int		i;

	i = 0;
	if (arg[i] == '-')
		i++;
	while (arg[i])
	{
		if (!(ft_isdigit(arg[i])))
			return (-1);
		i++;
	}
	return (0);
}

int	check_digit(char **av)
{
	int i;
	int j;

	// if (arg[i] == ' ' && )
	// 	i++;
	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][0] == '-')
				j++;
			if (av[i][j] < '0' || av[i][j] > '9')
				return(-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	isinteger(char *arg)
{
	long	res;

	res = ft_atoi(arg);
	if (res > 2147483647 || res < -2147483648)
		return (-1);
	return (0);
}

int	check_double(char **tab, int i)
{
	int		j;

	j = i + 1;
	while (tab[j])
	{
		if (!(ft_strncmp(tab[i], tab[j], ft_strlen(tab[i]))))
			return (-1);
		j++;
	}
	return (0);
}

void	check_arg(char **tab, char **av)
{
	int		i;

	i = 0;
	// if (check_digit(av) == -1)
	// {
	// 	free_tab(tab);
	// 	printf("Error: arguments\n");
	// 	exit(1);
	// }
	while (tab[i])
	{
		if (check_isnum(tab[i]) == -1
			||isinteger(tab[i]) == -1
			|| check_double(tab, i) == -1)
		{
			free_tab(tab);
			printf("Error: arguments\n");
			exit(1);
		}
		i++;
	}
	return ;
}
