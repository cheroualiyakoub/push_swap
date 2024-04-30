/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycheroua <ycheroua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 05:44:42 by ycheroua          #+#    #+#             */
/*   Updated: 2024/04/19 08:08:01 by ycheroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

static size_t	get_digit_count(int n)
{
	if (n == 0)
		return (0);
	return (1 + get_digit_count(n / 10));
}

static void	convert_to_str(char *str, long long n, size_t index)
{
	if (n == 0)
		return ;
	convert_to_str(str, n / 10, index - 1);
	str[index] = '0' + (n % 10);
}

char	*ft_itoa(int n)
{
	size_t			digit_count;
	char			*result;
	long long		num;
	int				sign_byte;

	num = n;
	if (n == 0)
		return (ft_strdup("0"));
	if (n > 0)
		sign_byte = 0;
	else
		sign_byte = 1;
	digit_count = get_digit_count(num);
	result = (char *)malloc((digit_count + 1 + sign_byte) * sizeof(char));
	if (!result)
		return (NULL);
	if (num < 0)
	{
		result[0] = '-';
		num = num * (-1);
	}
	convert_to_str(result + sign_byte, num, digit_count - 1);
	result[digit_count + sign_byte] = '\0';
	return (result);
}
