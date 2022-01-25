/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sort_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 12:01:15 by amyroshn          #+#    #+#             */
/*   Updated: 2022/01/24 14:25:17 by amyroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

void	insert_asc(t_stack *a, t_stack *b, int max_sorted)
{
	while (b->size > 0 && b->min == b->head->value)
	{
		while (b->head->value > a->head->value && a->head->value != max_sorted)
			rotate(a);
		if (a->head->value == max_sorted)
		{
			while (b->size > 0 && b->head->value < a->head->value)
			{
				push(b, a);
				rotate(a);
			}
			rotate(a);
			while (b->size > 0)
			{
				revrotate(b);
				push(b, a);
			}
		}
		push(b, a);
		if (b->size > 0 && b->head->value > a->head->next->value)
			rotate(a);
	}
}

void	insert_des(t_stack *a, t_stack *b, int sorted)
{
	int	i;

	i = 0;
	while (sorted == 0 && b->size > 0)
		push(b, a);
	while (b->size > 0)
	{
		while (b->head->value < a->last_value && i++ < sorted)
			revrotate(a);
		push(b, a);
	}
}

void	set_minmax_sorted(t_stack *st, int *min, int *max)
{
	if (!st->head)
		return ;
	if (st->min < *min)
		*min = st->min;
	if (st->max > *max)
		*max = st->max;
}

void	scroll_push_asc(t_stack *a, t_stack *b, int op_count, int sorted)
{
	while (b->size < op_count && b->size + sorted < a->size + b->size)
	{
		revrotate(a);
		scroll_push(a, b);
	}
	scroll_to_val(b, b->min);
}

void	scroll_push_des(t_stack *a, t_stack *b, int op_count, int sorted)
{
	while (b->size < op_count && b->size + sorted < b->size + a->size)
		rev_scroll_push(a, b);
	scroll_to_val(b, b->max);
}
