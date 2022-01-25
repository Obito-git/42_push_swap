/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 12:07:43 by amyroshn          #+#    #+#             */
/*   Updated: 2022/01/24 10:37:43 by amyroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

typedef struct s_elem
{
	int				value;
	struct s_elem	*next;
}				t_elem;

typedef struct s_stack {
	char			name;
	int				size;
	int				min;
	int				max;
	int				last_value;
	struct s_elem	*head;
}				t_stack;

//UTILS
int		ft_atoi_pushswap(char *numb);

//STACK
t_stack	*create_stack(char name);
int		add_element(t_stack **st, int value);
void	free_stack(t_stack *a, t_stack *b);
void	set_minmax(t_stack *st);
//operations
void	push(t_stack *from, t_stack *to);
void	swap(t_stack *st);
void	rotate(t_stack *st);
void	revrotate(t_stack *st);
//sort
int		issorted(t_stack *st);
void	scroll_to_val(t_stack *st, int val);
void	scroll_push(t_stack *from, t_stack *to);
void	rev_scroll_push(t_stack *from, t_stack *to);
void	stack_sort(t_stack *a, t_stack *b);
void	insert_sort(t_stack *a, t_stack *b, int steps);
//insert sort utils
void	insert_asc(t_stack *a, t_stack *b, int max_sorted);
void	insert_des(t_stack *a, t_stack *b, int sorted);
void	set_minmax_sorted(t_stack *st, int *min, int *max);
void	scroll_push_asc(t_stack *a, t_stack *b, int op_count, int sorted);
void	scroll_push_des(t_stack *a, t_stack *b, int op_count, int sorted);
#endif
