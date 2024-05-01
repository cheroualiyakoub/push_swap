/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_frees.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycheroua <ycheroua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 00:54:05 by ycheroua          #+#    #+#             */
/*   Updated: 2024/05/01 21:38:29 by ycheroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	ps_free_stacks(int num_objects, ...)
{
	va_list	args;
	int		i;
	t_stack	*stack;

	va_start (args, num_objects);
	i = -1;
	while (++i < num_objects)
	{
		stack = va_arg(args, t_stack *);
		while (stack->head)
			ps_pop(stack);
	}
	va_end (args);
}

void	ps_free_objects(int num_objects, ...)
{
	va_list	args;
	int		i;
	void	*ptr;

	va_start (args, num_objects);
	i = -1;
	while (++i < num_objects)
	{
		ptr = va_arg(args, void *);
		if (ptr)
			free(ptr);
	}
	va_end(args);
}

void	ps_free_str_split(char **str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
