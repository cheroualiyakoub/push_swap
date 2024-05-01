/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_intit_stacks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycheroua <ycheroua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 01:01:18 by ycheroua          #+#    #+#             */
/*   Updated: 2024/05/01 21:45:23 by ycheroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

t_node	*ps_create_push_node(int value, t_stack *stack, int index)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = index;
	new_node->next = stack->head;
	stack->head = new_node;
	return (new_node);
}

void	ps_inti_mouveement(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->name = "a";
	stack_a->swap = "s";
	stack_a->push = "p";
	stack_a->rotate = "r";
	stack_a->rotate_reverse = "rr";
	stack_b->name = "b";
	stack_b->swap = "s";
	stack_b->push = "p";
	stack_b->rotate = "r";
	stack_b->rotate_reverse = "rr";
}

void	ps_init_stacks(t_stack *stack_a, t_stack *stack_b, int *values, int c)
{
	t_node	*new_node;
	int		i;

	i = 1;
	stack_a->head = NULL;
	stack_a->size = 0;
	stack_b->head = NULL;
	stack_b->head = 0;
	ps_inti_mouveement(stack_a, stack_b);
	while (i <= c)
	{
		new_node = ps_create_push_node(values[c - i], stack_a, 0);
		if (!new_node)
			return ;
		stack_a->head = new_node;
		stack_a->size += 1;
		i++;
	}
}
