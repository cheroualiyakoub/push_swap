/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_check_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycheroua <ycheroua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 21:32:53 by ycheroua          #+#    #+#             */
/*   Updated: 2024/05/01 21:38:55 by ycheroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	ps_is_sign(char c)
{
	if (c != '+' && c != '-')
		return (0);
	return (1);
}

int	ps_check_digit(char c)
{
	if (!ft_isdigit(c) && c != ' ' && !ps_is_sign(c))
		return (0);
	return (1);
}

int	ps_check_strdigit(int argc, char **argv)
{
	int		i;
	int		j;

	i = 0;
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
		{
			if (ps_is_sign(argv[i][j]))
			{
				if (j > 0)
					if (argv[i][j - 1] != ' ')
						return (0);
				if (!ft_isdigit(argv[i][j + 1]))
					return (0);
			}
			if (!ps_check_digit(argv[i][j]))
				return (0);
		}
	}
	return (1);
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
		{
			if (values[i] == values[j])
			{
				ps_free_objects(1, values);
				return (0);
			}
		}
	}
	return (1);
}
