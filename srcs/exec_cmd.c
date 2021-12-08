/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadjigui <sadjigui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 19:24:08 by sadjigui          #+#    #+#             */
/*   Updated: 2021/12/08 21:32:03 by sadjigui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	exec_cmd2(char *cmd, t_pile *a, t_pile *b)
{
	if (!ft_strncmp(cmd, "ra", ft_strlen(cmd)))
		rotate_nb(a, pile_length(a));
	else if (!ft_strncmp(cmd, "rb", ft_strlen(cmd)))
		rotate_nb(b, pile_length(b));
	else if (!ft_strncmp(cmd, "rr", ft_strlen(cmd)))
	{
		rotate_nb(a, pile_length(a));
		rotate_nb(b, pile_length(b));
	}
	else if (!ft_strncmp(cmd, "rra", ft_strlen(cmd)))
		reverse_rotate_nb(a, pile_length(a));
	else if (!ft_strncmp(cmd, "rrb", ft_strlen(cmd)))
		reverse_rotate_nb(b, pile_length(b));
	else if (!ft_strncmp(cmd, "rrr", ft_strlen(cmd)))
	{
		reverse_rotate_nb(a, pile_length(a));
		reverse_rotate_nb(b, pile_length(b));
	}
	else
		return (-1);
	return (1);
}

int	exec_cmd(char *cmd, t_pile *a, t_pile *b)
{
	if (!ft_strncmp(cmd, "sa", ft_strlen(cmd)))
		swap_nb(a);
	else if (!ft_strncmp(cmd, "sb", ft_strlen(cmd)))
		swap_nb(b);
	else if (!ft_strncmp(cmd, "ss", ft_strlen(cmd)))
	{
		swap_nb(a);
		swap_nb(b);
	}
	else if (!ft_strncmp(cmd, "pa", ft_strlen(cmd)))
		push_nb(b, a);
	else if (!ft_strncmp(cmd, "pb", ft_strlen(cmd)))
		push_nb(a, b);
	else if (exec_cmd2(cmd, a, b) == -1)
		return (-1);
	return (1);
}

void	sort_exec(char *cmd, t_pile *a, t_pile *b)
{
	exec_cmd(cmd, a, b);
	ft_putstr(cmd);
	ft_putstr("\n");
}

void	exec_best_move(t_move *best_move, t_pile *a, t_pile *b)
{
	while (best_move->move_in_both > 0)
	{
		if (best_move->rotate_r_in_a == TRUE
			&& best_move->rotate_r_in_b == TRUE)
			sort_exec("rrr", a, b);
		else
			sort_exec("rr", a, b);
		best_move->move_in_both--;
	}
	while (best_move->move_in_a-- > 0)
	{
		if (best_move->rotate_r_in_a == TRUE)
			sort_exec("rra", a, b);
		else
			sort_exec("ra", a, b);
	}
	while (best_move->move_in_b-- > 0)
	{
		if (best_move->rotate_r_in_b == TRUE)
			sort_exec("rrb", a, b);
		else
			sort_exec("rb", a, b);
	}
	sort_exec("pb", a, b);
}
