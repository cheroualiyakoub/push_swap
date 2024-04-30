/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycheroua <ycheroua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 16:36:17 by ycheroua          #+#    #+#             */
/*   Updated: 2024/04/30 23:40:06 by ycheroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	main(int argc, char **argv)
{
	int		count;
	int		*values;
	t_stack stack_a;
	t_stack stack_b;
	
	count = ps_valid_input(argc, argv);
	if (count <= 1)
		return (ps_promp_er_return());

	values = ps_parse_input(argc, argv, count);
	if (values == 0 )
		return (ps_promp_er_return());
	if (!ps_check_double_input(values, count))
		return (ps_promp_er_return());
	ps_init_stacks(&stack_a, &stack_b, values, count);
	ps_sort_values_array(values, count);
	ps_get_index(values, &stack_a, count);
	ps_free_objects(1 ,values);
	ps_sortstack(&stack_a, &stack_b, count);
	ps_free_stacks(1, &stack_a);
	return (0);	
}
