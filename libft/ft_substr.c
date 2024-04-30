/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycheroua <ycheroua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 01:56:13 by ycheroua          #+#    #+#             */
/*   Updated: 2024/04/19 08:09:56 by ycheroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub_str;
	int		j;
	size_t	new_len;

	j = start;
	i = 0;
	if (start > ft_strlen(s))
	{
		sub_str = ft_calloc(1, sizeof(char));
		if (!sub_str)
			return (NULL);
		return (sub_str);
	}
	new_len = ft_strlen(s + start);
	if (!(new_len < len))
		new_len = len;
	sub_str = (char *)malloc(sizeof(char) *(new_len + 1));
	if (!sub_str)
		return (NULL);
	while (i < new_len)
		sub_str[i++] = s[j++];
	sub_str[i] = '\0';
	return (sub_str);
}
