/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycheroua <ycheroua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 16:36:17 by ycheroua          #+#    #+#             */
/*   Updated: 2024/05/01 21:46:36 by ycheroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	ps_valid_input(int argc, char **argv)
{
	int		i;
	int		j;
	char	c;
	char	next_c;	
	int		count;

	i = 0;
	count = 0;
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
		{
			c = argv[i][j];
			next_c = argv[i][j + 1];
			if (!ps_check_strdigit(argc, argv))
				return (-1);
			if (ft_isdigit(c) && \
				(!ft_isdigit(next_c) && next_c != ' ' && next_c != '\0'))
				return (0);
			if (ft_isdigit(c) && (next_c == ' ' || next_c == '\0'))
				count++;
		}
	}
	return (count);
}

int	*ps_parse_input(int argc, char **argv, int count)
{
	int			*values;
	long int	temp_value;
	char		**string_numbers;
	int			j;
	int			i;

	j = -1;
	i = 0;
	values = (int *)malloc (sizeof(int) * count);
	while (++i < argc)
	{
		count = -1;
		string_numbers = ft_split(argv[i], ' ');
		while (string_numbers[++count])
		{
			temp_value = ft_latoi(string_numbers[count]);
			if (!ps_check_longint(temp_value))
				return (ps_free_objects(1, values), NULL);
			values[++j] = (int)temp_value;
		}
		ps_free_str_split(string_numbers);
	}
	return (values);
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
	else if (count <= 5)
		ps_sort_u_5(stack_a, stack_b, count);
	else
	{
		ps_ksort_a_to_b(stack_a, stack_b, count);
		ps_ksort_b_to_a(stack_b, stack_a, count);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int		count;
	int		*values;
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc > 1 && !argv[1][0])
		return (ps_promp_er_return());
	count = ps_valid_input(argc, argv);
	if (count == -1)
		return (ps_promp_er_return());
	if (count < 1)
		return (0);
	values = ps_parse_input(argc, argv, count);
	if (values == 0)
		return (ps_promp_er_return());
	if (!ps_check_double_input(values, count))
		return (ps_promp_er_return());
	ps_init_stacks(&stack_a, &stack_b, values, count);
	ps_sort_values_array(values, count);
	ps_get_index(values, &stack_a, count);
	ps_free_objects(1, values);
	ps_sortstack(&stack_a, &stack_b, count);
	ps_free_stacks(1, &stack_a);
	return (0);
}
