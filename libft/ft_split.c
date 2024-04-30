/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycheroua <ycheroua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 02:17:40 by ycheroua          #+#    #+#             */
/*   Updated: 2024/04/19 08:09:19 by ycheroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

static char	**ft_free_if_error(char **array, size_t i)
{
	while (i > 0)
		free(array[--i]);
	free(array);
	return (NULL);
}

static int	ft_word_len(const char *str, char charset)
{
	int	i;

	i = 0;
	while (str[i] && !(*(str + i) == charset))
		i++;
	return (i);
}

static int	ft_count_words(const char *str, char c)
{
	int	i;
	int	w;

	w = 0;
	while (*str)
	{
		while (*str && (*str == c))
			str++;
		i = ft_word_len(str, c);
		str += i;
		if (i)
			w++;
	}
	return (w);
}

static char	*ft_create_word_copy(const char *src, size_t n)
{
	char	*dest;

	dest = malloc((n + 1) * sizeof(char));
	if (!(dest))
		return (NULL);
	ft_strlcpy(dest, src, n + 1);
	return (dest);
}

char	**ft_split(char const *str, char charset)
{
	char	**array;
	int		size;
	int		i;
	int		n;
	char	*temp_word;

	size = ft_count_words(str, charset);
	array = malloc ((size + 1) * sizeof(char *));
	if (!(array))
		return (NULL);
	i = -1;
	while (++i < size)
	{
		while (*str && (*str == charset))
			str++;
		n = ft_word_len(str, charset);
		temp_word = ft_create_word_copy(str, n);
		array[i] = temp_word;
		if (!array[i])
			return (ft_free_if_error(array, i));
		str += n;
	}
	array[size] = 0;
	return (array);
}
