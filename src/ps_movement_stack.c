/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_mouvmentstack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycheroua <ycheroua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 00:31:44 by ycheroua          #+#    #+#             */
/*   Updated: 2024/05/01 20:21:02 by ycheroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	ps_reverse_rotate(t_stack *stack)
{
	t_node	*temp_node;
	t_node	*parse_node;

	if (stack->head == NULL || stack->head->next == NULL)
		return ;
	parse_node = stack->head;
	while (parse_node->next->next != NULL && parse_node->next != NULL)
		parse_node = parse_node->next;
	temp_node = parse_node->next;
	parse_node->next = NULL;
	temp_node->next = stack->head;
	stack->head = temp_node;
	ps_print_mouv(stack->rotate_reverse, stack->name);
}

void	ps_rotate(t_stack *stack)
{
	t_node	*temp_node;
	t_node	*parse_node;

	if (stack->head == NULL || stack->head->next == NULL)
		return ;
	temp_node = stack->head;
	parse_node = stack->head;
	while (parse_node->next != NULL)
		parse_node = parse_node->next;
	stack->head = temp_node->next;
	parse_node->next = temp_node;
	temp_node->next = NULL;
	ps_print_mouv(stack->rotate, stack->name);
}

void	ps_swap(t_stack *stack)
{
	t_node	*temp_node;
	t_node	*temp_next;

	if (stack->head == NULL || stack->head->next == NULL)
		return ;
	temp_node = stack->head;
	temp_next = stack->head->next->next;
	stack->head = stack->head->next;
	stack->head->next = temp_node;
	temp_node->next = temp_next;
	ps_print_mouv(stack->swap, stack->name);
}

void	ps_pop(t_stack *stack)
{
	t_node	*temp_node;

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
	int	value;
	int	index;

	if (stack_src->head == NULL)
		return ;
	value = stack_src->head->value;
	index = stack_src->head->index;
	ps_pop(stack_src);
	ps_create_push_node(value, stack_des, index);
	stack_des->size++;
	ps_print_mouv(stack_des->push, stack_des->name);
}
