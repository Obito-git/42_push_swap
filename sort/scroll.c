/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scroll.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 12:01:24 by amyroshn          #+#    #+#             */
/*   Updated: 2022/01/22 12:04:24 by amyroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

void	scroll(t_stack *st, int index)
{
	while (index != 0)
	{
		if (index < 0)
		{
			revrotate(st);
			index++;
		}	
		else
		{
			rotate(st);
			index--;
		}
	}
}

void	scroll_to_val(t_stack *st, int val)
{
	int		i;
	t_elem	*tmp;

	i = 0;
	tmp = st->head;
	while (tmp)
	{
		if (tmp->value == val)
			break ;
		tmp = tmp->next;
		i++;
	}
	if (st->size - i < i)
		i = (st->size - i) * -1;
	scroll(st, i);
}

void	rev_scroll_push(t_stack *from, t_stack *to)
{
	t_elem	*temp;
	int		prev;

	if (to->size < 2)
		push(from, to);
	else if (from->head->value < to->min || from->head->value > to->max)
	{
		scroll_to_val(to, to->max);
		push(from, to);
	}
	else if (to->size != 1)
	{
		temp = to->head;
		prev = to->last_value;
		while (temp)
		{
			if (from->head->value < prev && from->head->value > temp->value)
				break ;
			prev = temp->value;
			temp = temp->next;
		}
		scroll_to_val(to, temp->value);
		push(from, to);
	}
}

void	scroll_push(t_stack *from, t_stack *to)
{
	t_elem	*temp;
	int		prev;

	if (to->size < 2)
		push(from, to);
	else if (from->head->value < to->min || from->head->value > to->max)
	{
		scroll_to_val(to, to->min);
		push(from, to);
	}
	else if (to->size != 1)
	{
		temp = to->head;
		prev = to->last_value;
		while (temp)
		{
			if (from->head->value > prev && from->head->value < temp->value)
				break ;
			prev = temp->value;
			temp = temp->next;
		}
		scroll_to_val(to, temp->value);
		push(from, to);
	}
}
