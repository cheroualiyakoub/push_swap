/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sortstack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycheroua <ycheroua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 03:25:24 by ycheroua          #+#    #+#             */
/*   Updated: 2024/04/30 23:26:37 by ycheroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	ps_get_max_index(t_stack *stack)
{
	int max_index;
	t_node *temp_node;

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
	t_node *temp_node;

	temp_node = stack->head;
	while (temp_node->next)
	{
		if (temp_node->value > temp_node->next->value)
			return (0);
		temp_node = temp_node->next;
	}
	return (1);
}

/*
	sort under 3 values
*/
void	ps_sort_u_3(t_stack *stack)
{
	int indx_max;
	
	if(ps_check_sorted(stack))
		return ;
	indx_max = ps_get_max_index(stack);
	if (stack->head->index == indx_max)
		ps_rotate(stack);
	else if (stack->head->next->index == indx_max )
		ps_reverse_rotate(stack);
	if (stack->head->index > stack->head->next->index)
		ps_swap(stack);
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

void	ps_sort_u_7(t_stack *stack_a, t_stack *stack_b, int count)
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

int	ps_calculte_range(int count)
{
	int	range_value;

	range_value = ft_sqrt_approx(count) * 1.5;
	return (range_value);
}

void	ps_ksort_a_to_b(t_stack *stack_a, t_stack *stack_b, int count)
{
	int	range_value;
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
	int		r_rotate_steps;
	t_node	*temp_node;

	n = count - 1;
	while (n >= 0)
	{
		rotate_steps = ps_count_mouvement_top(stack_b, n);
		r_rotate_steps = n - rotate_steps;
		temp_node = stack_b->head;
		if (rotate_steps <= r_rotate_steps)
		{
			while (temp_node->index != n)
			{
				ps_rotate(stack_b);
				temp_node = stack_b->head;
			}
			ps_push(stack_b, stack_a);
		}
		else
		{
			while (temp_node->index != n)
			{
				ps_reverse_rotate(stack_b);
				temp_node = stack_b->head;
			}
			ps_push(stack_b, stack_a);
		}
		n--;
	}
}

int	ps_sortstack(t_stack *stack_a, t_stack *stack_b, int count)
{
	if (ps_check_sorted(stack_a))
	{
		ps_free_stacks(2, stack_a, stack_b);
		return (0);
	}
	else if (count == 2)
		ps_swap(stack_a);
	else if (count == 3)
		ps_sort_u_3(stack_a);
	else if (count <= 7)
		ps_sort_u_7(stack_a, stack_b, count);
	else
	{
		ps_ksort_a_to_b(stack_a, stack_b, count);
		ps_ksort_b_to_a(stack_b, stack_a, count);
	}
	return (1);
}
