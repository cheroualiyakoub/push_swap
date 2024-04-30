/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycheroua <ycheroua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 06:47:17 by ycheroua          #+#    #+#             */
/*   Updated: 2024/04/19 08:09:52 by ycheroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

static int	is_char_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	end;
	size_t	start;
	char	*str;

	i = 0;
	end = ft_strlen(s1);
	if (!s1 || !set)
		return (NULL);
	while (is_char_set(s1[i], set))
		i++;
	start = i;
	if (start < end)
	{
		while (is_char_set(s1[end - 1], set))
			end--;
	}
	str = malloc((end - start + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1 + start, (end - start + 1));
	return (str);
}
