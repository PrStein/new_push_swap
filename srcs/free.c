/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadjigui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 16:35:34 by sadjigui          #+#    #+#             */
/*   Updated: 2021/12/04 16:35:37 by sadjigui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_pile(t_pile *stack)
{
	t_element	*current;
	t_element	*element;

	current = stack->first;
	while (current)
	{
		element = current;
		current = current->next;
		free(element);
	}
	free(current);
	free(stack);
	return ;
}

void	free_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return ;
}
