/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycheroua <ycheroua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 23:09:36 by ycheroua          #+#    #+#             */
/*   Updated: 2024/04/19 08:09:32 by ycheroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

size_t	ft_strlcat(char *dest, char *src, unsigned int size)
{
	size_t	dest_l;
	size_t	src_l;
	size_t	i;
	size_t	result;

	i = 0;
	dest_l = ft_strlen(dest);
	src_l = ft_strlen(src);
	if (dest_l < size)
		result = dest_l + src_l;
	else
		result = src_l + size;
	if (size == 0)
		return (result);
	while (src[i] && dest_l + i < size - 1)
	{
		dest[dest_l + i] = src[i];
		i++;
	}
	dest[dest_l + i] = '\0';
	return (result);
}
