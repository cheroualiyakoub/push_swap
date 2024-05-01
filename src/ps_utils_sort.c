/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycheroua <ycheroua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 01:12:58 by ycheroua          #+#    #+#             */
/*   Updated: 2024/05/01 02:03:54 by ycheroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	ps_get_max_index(t_stack *stack)
{
	int		max_index;
	t_node	*temp_node;

	max_index = stack->head->index;
	temp_node = stack->head->next;
	while (temp_node)
	{
		if (max_index < temp_node->index)
			max_index = temp_node->index;
		temp_node = temp_node->next;
	}
	return (max_index);
}

int	ps_check_sorted(t_stack *stack)
{
	t_node	*temp_node;

	temp_node = stack->head;
	while (temp_node->next)
	{
		if (temp_node->value > temp_node->next->value)
			return (0);
		temp_node = temp_node->next;
	}
	return (1);
}

int	ps_count_mouvement_top(t_stack *stack, int index)
{
	t_node	*temp_node;
	int		steps;

	temp_node = stack->head;
	steps = 0;
	while (temp_node && temp_node->index != index)
	{
		temp_node = temp_node->next;
		steps++;
	}
	return (steps);
}

/*
return 1 if top is the cheapest route
return 0 if bottom is the cheapest route 
*/
int	ps_top_is_cheapest(t_stack *stack, int index)
{
	if (ps_count_mouvement_top(stack, index) <= stack->size / 2)
		return (1);
	return (0);
}

int	ps_calculte_range(int count)
{
	int	range_value;

	range_value = ft_sqrt_approx(count) * 1.5;
	return (range_value);
}
