/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycheroua <ycheroua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 22:59:59 by ycheroua          #+#    #+#             */
/*   Updated: 2024/04/24 04:51:26 by ycheroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int *ps_parse_input(int argc, char **argv, int count)
{
	int		*values;
	long int temp_value;
	char 	**string_numbers;
	int		j;
	int		i;
	int		k;
	
	j = -1;
	i = 0;
	k = 0;
	values = (int *)malloc (sizeof(int) * count);
	while (++i < argc)
	{
		k = -1;
		string_numbers = ft_split(argv[i], ' ');
		while (string_numbers[++k])
		{
			temp_value = ft_latoi(string_numbers[k]); 
			if (!ps_check_longint(temp_value))
			{
				ps_free_objects(1, values);
				return (0);
			}
			values[++j] = (int)temp_value;
		}
	}
	return (values);
}
