/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 12:01:30 by amyroshn          #+#    #+#             */
/*   Updated: 2022/01/22 12:06:18 by amyroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

int	issorted(t_stack *st)
{
	t_elem	*tmp;

	if (!st || !st->head)
		return (1);
	tmp = st->head;
	while (tmp->value != st->min)
		tmp = tmp->next;
	while (tmp->next && tmp->value < tmp->next->value)
		tmp = tmp->next;
	if (tmp->next)
		return (0);
	if (st->head->value == st->min)
		return (1);
	if (tmp->value > st->head->value)
		return (0);
	tmp = st->head;
	while (tmp->next->value != st->min && tmp->value < tmp->next->value)
		tmp = tmp->next;
	if (tmp->next->value != st->min)
		return (0);
	scroll_to_val(st, st->min);
	return (1);
}

void	three_sort(t_stack *st)
{
	int	a;
	int	b;
	int	c;

	if (!st || st->size < 3)
		return ;
	a = st->head->value;
	b = st->head->next->value;
	c = st->head->next->next->value;
	if (a < b && a < c)
	{
		revrotate(st);
		swap(st);
	}
	else if (b < a && b < c)
		swap(st);
	else
	{
		swap(st);
		revrotate(st);
	}
}

void	five_sort(t_stack *a, t_stack *b)
{
	while (a->size > 3)
		push(a, b);
	if (!issorted(a))
		three_sort(a);
	if (b->size > 1 && b->head->value != b->min)
		swap(b);
	while (b->size > 0)
		scroll_push(b, a);
	scroll_to_val(a, a->min);
}

void	insert_sort(t_stack *a, t_stack *b, int steps)
{
	int	min_sorted;
	int	max_sorted;
	int	sorted;
	int	op_count;
	int	a_max_sorted;

	sorted = 0;
	min_sorted = 2147483647;
	max_sorted = -2147483648;
	op_count = a->size / steps;
	while (sorted < a->size)
	{
		scroll_push_des(a, b, op_count, sorted);
		set_minmax_sorted(b, &min_sorted, &max_sorted);
		insert_des(a, b, sorted);
		sorted += (op_count);
		scroll_to_val(a, min_sorted);
		scroll_push_asc(a, b, op_count, sorted);
		a_max_sorted = max_sorted;
		set_minmax_sorted(b, &min_sorted, &max_sorted);
		insert_asc(a, b, a_max_sorted);
		sorted += (op_count);
		scroll_to_val(a, max_sorted);
		rotate(a);
	}
}

void	stack_sort(t_stack *a, t_stack *b)
{
	if (a->size == 3)
		three_sort(a);
	else if (a->size <= 5)
		five_sort(a, b);
	else if (a->size <= 20)
		insert_sort(a, b, 1);
	else if (a->size <= 300)
		insert_sort(a, b, 5);
	else
		insert_sort(a, b, 10);
}
