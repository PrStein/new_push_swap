#include "../include/stack.h"

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
