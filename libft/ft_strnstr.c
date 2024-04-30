/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycheroua <ycheroua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 02:04:43 by ycheroua          #+#    #+#             */
/*   Updated: 2024/04/19 08:09:46 by ycheroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	temp_len;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	temp_len = 1;
	while (haystack[i] != '\0' && temp_len <= len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && temp_len <= len)
		{
			if (needle[j + 1] == '\0')
				return ((char *)&haystack[i]);
			j++;
			temp_len++;
		}
		i++;
		temp_len = i + 1;
	}
	return (0);
}
