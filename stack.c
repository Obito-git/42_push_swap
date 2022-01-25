/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 12:10:57 by amyroshn          #+#    #+#             */
/*   Updated: 2022/01/22 12:11:02 by amyroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_stack	*create_stack(char name)
{
	t_stack	*st;

	st = (t_stack *) malloc(sizeof(struct s_stack));
	if (!st)
		return (NULL);
	st->name = name;
	st->max = -2147483648;
	st->min = 2147483647;
	st->size = 0;
	st->head = NULL;
	return (st);
}

int	add_element(t_stack **st, int value)
{
	t_elem	*elem;
	t_elem	*temp;

	elem = (t_elem *) malloc(sizeof(struct s_elem));
	if (!st || !elem)
		return (0);
	elem->value = value;
	(*st)->size++;
	elem->next = NULL;
	(*st)->last_value = value;
	if (!(*st)->head)
	{
		(*st)->head = elem;
		return (1);
	}
	temp = (*st)->head;
	while (temp->next)
		temp = temp->next;
	temp->next = elem;
	return (1);
}

static void	free_all(t_stack *st)
{
	t_elem	*tmp;

	while (st && st->head)
	{
		tmp = st->head;
		st->head = st->head->next;
		free(tmp);
	}
	free(st);
}

void	free_stack(t_stack *a, t_stack *b)
{
	free_all(a);
	free_all(b);
}

void	set_minmax(t_stack *st)
{
	t_elem	*tmp;

	st->min = 2147483647;
	st->max = -2147483648;
	if (!st->head)
		return ;
	tmp = st->head;
	while (tmp)
	{
		if (tmp->value < st->min)
			st->min = tmp->value;
		if (tmp->value > st->max)
			st->max = tmp->value;
		tmp = tmp->next;
	}
}
