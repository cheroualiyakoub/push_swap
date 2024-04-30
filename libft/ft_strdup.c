/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycheroua <ycheroua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 02:24:14 by ycheroua          #+#    #+#             */
/*   Updated: 2024/04/19 08:09:24 by ycheroua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dup_string;

	i = 0;
	dup_string = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (dup_string == NULL)
		return (NULL);
	while (s[i])
	{
		dup_string[i] = s[i];
		i++;
	}
	dup_string[i] = '\0';
	return (dup_string);
}
