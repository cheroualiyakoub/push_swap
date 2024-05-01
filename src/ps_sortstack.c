/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sortstack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycheroua <ycheroua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 03:25:24 by ycheroua          #+#    #+#             */
/*   Updated: 2024/05/01 21:20:13 by ycheroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

/*
	sort under 3 values
*/
void	ps_sort_u_3(t_stack *stack)
{
	int	indx_max;

	if (ps_check_sorted(stack))
		return ;
	indx_max = ps_get_max_index(stack);
	if (stack->head->index == indx_max)
		ps_rotate(stack);
	else if (stack->head->next->index == indx_max)
		ps_reverse_rotate(stack);
	if (stack->head->index > stack->head->next->index)
		ps_swap(stack);
}

void	ps_sort_u_5(t_stack *stack_a, t_stack *stack_b, int count)
{
	int	min_index;
	int	i;

	i = count - 3;
	while (i > 0)
	{
		min_index = ps_get_min_index(stack_a);
		if (ps_top_is_cheapest(stack_a, min_index))
			while (stack_a->head->index != min_index)
				ps_rotate(stack_a);
		else
			while (stack_a->head->index != min_index)
				ps_reverse_rotate(stack_a);
		i--;
		ps_push(stack_a, stack_b);
	}
	ps_sort_u_3(stack_a);
	while (i++ < count - 3)
		ps_push(stack_b, stack_a);
	return ;
}

void	ps_ksort_a_to_b(t_stack *stack_a, t_stack *stack_b, int count)
{
	int		range_value;
	int		i;
	t_node	*temp_head;

	range_value = ps_calculte_range(count);
	i = 0;
	while (stack_a->head)
	{
		temp_head = stack_a->head;
		if (temp_head->index <= i)
		{
			ps_push(stack_a, stack_b);
			ps_rotate(stack_b);
			i++;
		}
		else if (temp_head->index <= i + range_value)
		{
			ps_push(stack_a, stack_b);
			i++;
		}
		else
			ps_rotate(stack_a);
	}
}

void	ps_ksort_b_to_a(t_stack *stack_b, t_stack *stack_a, int count)
{
	int		n;
	int		rotate_steps;

	n = count - 1;
	while (n >= 0)
	{
		rotate_steps = ps_count_mouvement_top(stack_b, n);
		if (rotate_steps <= n - rotate_steps)
		{
			while (stack_b->head->index != n)
				ps_rotate(stack_b);
			ps_push(stack_b, stack_a);
		}
		else
		{
			while (stack_b->head->index != n)
				ps_reverse_rotate(stack_b);
			ps_push(stack_b, stack_a);
		}
		n--;
	}
}
