/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt_approx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycheroua <ycheroua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 23:45:46 by ycheroua          #+#    #+#             */
/*   Updated: 2024/04/29 02:52:03 by ycheroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

int	ft_sqrt_approx(int N)
{
	double	x0;
	double	x;
	double	next_x;

	x0 = N / 2.0;
	x = x0;
	while (1)
	{
		next_x = 0.5 * (x + N / x);
		if (next_x == x)
			break ;
		x = next_x;
	}
	return ((int)(x + 0.5));
}
