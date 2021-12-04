/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadjigui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 16:41:50 by sadjigui          #+#    #+#             */
/*   Updated: 2021/12/04 16:41:52 by sadjigui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap_nb(t_pile *stack)
{
	int		tmp[2];

	if (pile_length(stack) < 2)
		return ;
	tmp[0] = depiler(stack);
	tmp[1] = depiler(stack);
	empiler(stack, tmp[0]);
	empiler(stack, tmp[1]);
}

void	push_nb(t_pile *from, t_pile *to)
{
	int		nb;

	if (pile_length(from) < 1)
		return ;
	nb = depiler(from);
	empiler(to, nb);
	return ;
}

void	rotate_nb(t_pile *stack, int len)
{
	int	*tmp;
	int	i;

	if (len < 2)
		return ;
	i = 0;
	tmp = malloc(sizeof(int) * len);
	if (!tmp)
	{
		free(tmp);
		return ;
	}
	while (i < len)
		tmp[i++] = depiler(stack);
	empiler(stack, tmp[0]);
	i--;
	while (i > 0)
		empiler(stack, tmp[i--]);
	free(tmp);
	return ;
}

void	reverse_rotate_nb(t_pile *stack, int len)
{
	int		*tmp;
	int		i;

	if (len < 2)
		return ;
	i = 0;
	tmp = malloc(sizeof(int) * len);
	if (!tmp)
	{
		free(tmp);
		return ;
	}
	while (i < len)
		tmp[i++] = depiler(stack);
	i -= 2;
	while (i >= 0)
		empiler(stack, tmp[i--]);
	empiler(stack, tmp[len - 1]);
	free(tmp);
	return ;
}
