/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qkherzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:33:06 by qkherzi           #+#    #+#             */
/*   Updated: 2022/01/06 17:33:12 by qkherzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		len = 0;
	dest = malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	while (s[i] && i < len)
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		i;
	size_t		len_s2;
	char		*dest;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	dest = malloc(sizeof(char) * (i + len_s2 + 1));
	if (!dest)
		return (NULL);
	i = -1;
	while (s1[++i])
		dest[i] = s1[i];
	len_s2 = -1;
	while (s2[++len_s2])
	{
		dest[i] = s2[len_s2];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
