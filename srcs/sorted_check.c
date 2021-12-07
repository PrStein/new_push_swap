#include "../include/push_swap.h"

int		check_pile_sorted(t_pile *stack)
{
	t_element	*current;
	int			previous_nb;

	if (stack == NULL || stack->first == NULL)
		return (0);
	current = stack->first;
	previous_nb = current->nb;
	while (current->next)
	{
		current = current->next;
		if (previous_nb > current->nb)
			return (0);
		previous_nb = current->nb;
	}
	return (1);
}

void	sorted_check(t_pile *a, t_pile *b)
{
	if (pile_length(b) == 0)
	{
		if (check_pile_sorted(a))
			printf("OK\n");
		else
			printf("KO\n");
	}
	else
		printf("KO\n");
	return ;
}

int		sorted_check_ps(t_pile *a, t_pile *b)
{
	if (pile_length(b) == 0)
	{
		if (check_pile_sorted(a))
			return (1);
		else
			return (0);
	}
	else
		return (0);
}
