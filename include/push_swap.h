/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadjigui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 18:20:27 by sadjigui          #+#    #+#             */
/*   Updated: 2021/12/04 18:20:30 by sadjigui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"

# define GREEN "\033[0;32m"
# define RED "\033[0;31m"
# define YELLOW "\033[0;33m"
# define SET "\033[0m"

typedef enum e_bool
{
	FALSE,
	TRUE
}						t_bool;

typedef struct s_element
{
	int					nb;
	struct s_element	*next;
}						t_element;

typedef struct s_pile
{
	t_element			*first;
}								t_pile;

typedef struct s_sort
{
	int		move_in_a;
	int		move_in_b;
	int		move_in_both;
	t_bool	rotate_r_in_a;
	t_bool	rotate_r_in_b;
	int		total_move;
}						t_move;

t_pile	*init_pile(void);

int		ft_tablen(char **tab);
int		main(int ac, char **av);
int		check_isnum(char *arg);
int		isinteger(char *arg);
int		check_double(char **tab, int i);
int		depiler(t_pile *stack);
int		pile_length(t_pile *stack);

void	check_arg(char **tab);
void	free_pile(t_pile *stack);
void	free_tab(char **tab);
void	swap_nb(t_pile *stack);
void	push_nb(t_pile *from, t_pile *to);
void	rotate_nb(t_pile *stack, int len);
void	reverse_rotate_nb(t_pile *stack, int len);
void	sort_3(t_pile *a, t_pile *b);
void	sort_5(t_pile *a, t_pile *b);
void	optimizer_push(t_pile *a, t_pile *b);
void	sort_all(t_pile *a, t_pile *b);
void	sort_pile(t_pile *a, t_pile *b);
void	empiler(t_pile *stack, int nb);
void	display_pile(t_pile *stack);

char	**ft_join_tab(char **tab, char **tmp_tab);
char	**parse_arg(char **av);

#endif
