/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycheroua <ycheroua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 22:24:48 by ycheroua          #+#    #+#             */
/*   Updated: 2024/04/19 08:08:53 by ycheroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	void	*rtrn;

	if (!dest && !src)
		return (0);
	rtrn = dest;
	if (src < dest)
	{
		src += n - 1;
		dest += n - 1;
		while (n-- > 0)
			*(char *)dest-- = *(char *)src--;
	}
	else
		while (n-- > 0)
			*(char *)dest++ = *(char *)src++;
	return (rtrn);
}
