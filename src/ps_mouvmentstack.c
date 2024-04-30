/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_mouvmentstack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycheroua <ycheroua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 00:31:44 by ycheroua          #+#    #+#             */
/*   Updated: 2024/04/30 23:43:53 by ycheroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void ps_reverse_rotate(t_stack *stack)
{
	t_node *temp_node;
	t_node *parse_node;
	
	if (stack->head == NULL || stack->head->next == NULL)
		return ;
	parse_node = stack->head;
	while (parse_node->next->next != NULL && parse_node->next != NULL)
		parse_node = parse_node->next;
	
	temp_node = parse_node->next;
	parse_node->next = NULL;
	temp_node->next = stack->head;
	stack->head = temp_node;
	ps_print_mouv(stack->rotate_reverse,stack->name);
}

void ps_rotate(t_stack *stack)
{
	t_node *temp_node;
	t_node *parse_node;
	
	if (stack->head == NULL || stack->head->next == NULL)
		return ;
	temp_node = stack->head;
	parse_node = stack->head;
	while (parse_node->next != NULL)
		parse_node = parse_node->next;
	stack->head = temp_node->next;
	parse_node->next = temp_node;
	temp_node->next = NULL;
	ps_print_mouv(stack->rotate,stack->name);
}
	
void ps_swap(t_stack *stack)
{
	t_node	*temp_node;
	t_node	*temp_next;
	
	if (stack->head == NULL || stack->head->next == NULL)
		return;
	temp_node = stack->head;
	temp_next = stack->head->next->next;
	stack->head = stack->head->next;
	stack->head->next = temp_node;
	temp_node->next = temp_next;
	ps_print_mouv(stack->swap, stack->name);
}

void ps_pop(t_stack *stack)
{
	t_node *temp_node;
	
	if (stack == NULL)
		return ;
	if (stack->head == NULL)
		return ;
	temp_node = stack->head;
	stack->head = stack->head->next;
	free(temp_node);
	stack->size--;
}



void	ps_push(t_stack *stack_src, t_stack *stack_des)
{
	int value;
	int	index;
	t_node *new_node;
	
	if (stack_src->head == NULL)
		return;
	value = stack_src->head->value;
	index = stack_src->head->index;
	ps_pop(stack_src);
	new_node = ps_create_push_node(value,  stack_des, index);
	stack_des->size++;
	ps_print_mouv(stack_des->push, stack_des->name);
}

t_node	*ps_create_push_node(int value, t_stack *stack, int index)
{
	t_node *new_node;
	
	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node) 
		return (NULL);
	new_node->value = value;		
	new_node->index = index;
	new_node->next = stack->head;
	stack->head = new_node;
	return (new_node);
}

void	ps_init_stacks(t_stack *stack_a, t_stack *stack_b, int *values, int count)
{
	t_node	*new_node;
	int		i;
	
	i = 1;
	stack_a->head = NULL;
	stack_a->size = 0;
	stack_a->name = "a";
	stack_a->swap = "s";
	stack_a->push = "p";
	stack_a->rotate = "r";
	stack_a->rotate_reverse = "rr";
	stack_b->head = NULL;
	stack_b->head = 0;
	stack_b->name = "b";
	stack_b->swap = "s";
	stack_b->push = "p";
	stack_b->rotate = "r";
	stack_b->rotate_reverse = "rr";
	while(i <= count)
	{
		new_node = ps_create_push_node(values[count - i], stack_a, 0);
		if (!new_node)
			return ;
		stack_a->head = new_node; 
		stack_a->size += 1;
		i++;
	}
}
