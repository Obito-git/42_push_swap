/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 12:04:25 by amyroshn          #+#    #+#             */
/*   Updated: 2022/01/24 12:52:08 by amyroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	is_dublicate(t_stack *st, int nmb)
{
	t_elem	*tmp;

	tmp = st->head;
	if (!tmp)
		return (0);
	while (tmp && nmb != tmp->value)
		tmp = tmp->next;
	return (tmp != NULL);
}

static int	parse_args(int ac, char **av, t_stack **st)
{
	int	i;
	int	parsed_nmb;

	i = 0;
	*st = create_stack('a');
	while (i < ac - 1)
	{
		parsed_nmb = ft_atoi_pushswap(av[i + 1]);
		if ((parsed_nmb == 0 && (ft_strlen(av[i + 1]) > 1
					|| av[i + 1][0] != '0')) || !(*st)
					|| is_dublicate(*st, parsed_nmb))
			return (0);
		if (!add_element(st, parsed_nmb))
			return (0);
		i++;
	}
	set_minmax(*st);
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = create_stack('b');
	if (ac == 1)
		ft_printf("Where are numbers for the sort my friend?\n");
	else if (!parse_args(ac, av, &a) || !b)
		ft_putstr_fd("Error\n", 2);
	else if (!issorted(a))
		stack_sort(a, b);
	free_stack(a, b);
	return (0);
}
