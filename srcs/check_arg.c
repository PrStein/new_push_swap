/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadjigui <sadjigui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 16:34:09 by sadjigui          #+#    #+#             */
/*   Updated: 2021/12/08 21:33:19 by sadjigui         ###   ########.fr       */
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
		if (ft_atoi(tab[i]) == ft_atoi(tab[j]))
			return (-1);
		j++;
	}
	return (0);
}

void	check_arg(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		if (check_isnum(tab[i]) == -1
			|| isinteger(tab[i]) == -1
			|| check_double(tab, i) == -1)
		{
			free_tab(tab);
			ft_putstr("Error: arguments\n");
			exit(1);
		}
		i++;
	}
	return ;
}
