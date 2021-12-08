/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadjigui <sadjigui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 19:26:01 by sadjigui          #+#    #+#             */
/*   Updated: 2021/12/08 20:52:08 by sadjigui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate_n_times(t_pile *a, t_pile *b, int pos)
{
	int		len;

	len = pile_length(a);
	if (pos <= len / 2)
	{
		while (pos != 0)
		{
			sort_exec("ra", a, b);
			pos--;
		}
	}
	else if (pos > len / 2)
	{
		while (pos != len)
		{
			sort_exec("rra", a, b);
			pos++;
		}
	}
	return ;
}

int	find_biggest_nb_pos(t_pile *stack)
{
	t_element	*current;
	int			i;
	int			pos;
	int			nb;

	current = stack->first;
	nb = current->nb;
	i = 0;
	pos = 0;
	current = current->next;
	while (current)
	{
		i++;
		if (current->nb > nb)
		{
			nb = current->nb;
			pos = i;
		}
		current = current->next;
	}
	return (pos);
}

int	find_smallest_nb_pos(t_pile *stack)
{
	t_element	*current;
	int			i;
	int			pos;
	int			nb;

	current = stack->first;
	nb = current->nb;
	i = 0;
	pos = 0;
	current = current->next;
	while (current)
	{
		i++;
		if (current->nb < nb)
		{
			nb = current->nb;
			pos = i;
		}
		current = current->next;
	}
	return (pos);
}

int	find_min_nb(t_pile *stack)
{
	t_element	*current;
	int			nb;

	current = stack->first;
	nb = current->nb;
	while (current)
	{
		if (current->nb < nb)
			nb = current->nb;
		current = current->next;
	}
	return (nb);
}

int	find_max_nb(t_pile *stack)
{
	t_element	*current;
	int			nb;

	current = stack->first;
	nb = current->nb;
	while (current)
	{
		if (current->nb > nb)
			nb = current->nb;
		current = current->next;
	}
	return (nb);
}
