#include "../include/push_swap.h"

int		ft_tablen(char **tab)
{
	int		i;

	i = 0;
	if (tab == NULL)
		return (i);
	while (tab[i])
		i++;
	return (i);
}

int		main(int ac, char **av)
{
	t_pile	*a;
	t_pile	*b;
	char	**tab;
	int		i;

	if (ac <= 1)
		exit(1);
	tab = parse_arg(av);
	check_arg(tab);

  a = init_pile();
	b = init_pile();
	i = ft_tablen(tab);
	while (i-- > 0)
		empiler(a, ft_atoi(tab[i]));
	free_tab(tab);

	sort_pile(a, b);

	free_pile(a);
	free_pile(b);
	return (0);
}