/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 12:13:40 by amyroshn          #+#    #+#             */
/*   Updated: 2022/01/24 10:26:46 by amyroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	swap(t_stack *st)
{
	int	tmp;

	if (!st || st->size < 2)
		return ;
	tmp = st->head->value;
	st->head->value = st->head->next->value;
	st->head->next->value = tmp;
	if (st->size == 2)
		st->last_value = tmp;
	ft_printf("s%c\n", st->name);
}

void	push(t_stack *from, t_stack *to)
{
	t_elem	*new_head;

	if (!from || !from->head || !to)
		return ;
	new_head = from->head;
	from->size--;
	from->head = from->head->next;
	new_head->next = to->head;
	to->head = new_head;
	to->size++;
	if (to->size == 1)
		to->last_value = new_head->value;
	set_minmax(from);
	set_minmax(to);
	ft_printf("p%c\n", to->name);
}

void	rotate(t_stack *st)
{
	t_elem	*tmp;
	t_elem	*last;

	if (!st || !st->head || !st->head->next)
		return ;
	tmp = st->head;
	st->head = st->head->next;
	tmp->next = NULL;
	st->last_value = tmp->value;
	last = st->head;
	while (last->next)
		last = last->next;
	last->next = tmp;
	ft_printf("r%c\n", st->name);
}

void	revrotate(t_stack *st)
{
	t_elem	*tmp;

	if (!st || !st->head || !st->head->next)
		return ;
	tmp = st->head;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = st->head;
	st->head = tmp->next;
	tmp->next = NULL;
	st->last_value = tmp->value;
	ft_printf("rr%c\n", st->name);
}
