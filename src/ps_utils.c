/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycheroua <ycheroua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 20:32:00 by ycheroua          #+#    #+#             */
/*   Updated: 2024/05/01 02:28:44 by ycheroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	ps_print_mouv(char *mouv, char *stack)
{
	write (1, mouv, ft_strlen(mouv));
	write (1, stack, ft_strlen(stack));
	write (1, "\n", 1);
}

int	ps_promp_er_return(void)
{
	write(2, "Error\n", 6);
	return (0);
}

void	ps_sort_values_array(int *values, int count)
{
	int	i;
	int	j;
	int	temp;

	i = -1;
	while (++i < count - 1)
	{
		j = -1;
		while (++j < count - i - 1)
		{
			if (values[j] > values[j + 1])
			{
				temp = values[j];
				values[j] = values[j + 1];
				values[j + 1] = temp;
			}
		}
	}
}

void	ps_get_index(int *values, t_stack *stack_a, int count)
{
	t_node	*temp_node;
	int		index;

	temp_node = stack_a->head;
	while (temp_node != NULL)
	{
		index = 0;
		while (index < count)
		{
			if (values[index] == temp_node->value)
			{
				temp_node->index = index;
				break ;
			}
			index++;
		}
		temp_node = temp_node->next;
	}
}

int	ps_get_min_index(t_stack *stack)
{
	t_node	*temp_node;
	int		index;

	temp_node = stack->head;
	index = temp_node->index;
	while (temp_node->next)
	{
		temp_node = temp_node->next;
		if (temp_node->index < index)
			index = temp_node->index;
	}
	return (index);
}
