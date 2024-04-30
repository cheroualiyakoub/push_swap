/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_check_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycheroua <ycheroua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 21:32:53 by ycheroua          #+#    #+#             */
/*   Updated: 2024/04/26 17:18:26 by ycheroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	ps_check_digit(char c)
{
	if (!ft_isdigit(c) && c != ' ' && c != '-')
		return (0);
	return (1);
}

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
			if (!ps_check_digit(c))
				return (0);
			if (ft_isdigit(c) && (!ft_isdigit(next_c) && next_c != ' ' && next_c != '\0'))
				return (0);
			if (c == '-' && !ft_isdigit(next_c))
				return (0);
			if (ft_isdigit(c) && (next_c == ' ' || next_c == '\0'))
				count++;
		}
	}
	return (count);
}

int	ps_check_longint(long int numr)
{
	if (numr < INT_MIN || numr > INT_MAX)
		return (0);
	return (1);
}

int	ps_check_double_input(int *values, int count)
{
	int	i;
	int	j;

	i = -1;
	while (++i < count)
	{
		j = i;
		while (++j < count)
			if (values[i] == values[j])
			{
				ps_free_objects(1, values);				
				return (0);
			}
	}
	return (1);
}
