/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qkherzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:46:08 by qkherzi           #+#    #+#             */
/*   Updated: 2021/12/06 17:47:23 by qkherzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

size_t	ft_strlen(const char *s)

{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if ((char)c == '\0')
		return ((char *)s + ft_strlen(s));
	while (s[i])
	{
		if ((char)c == s[i])
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

void	ft_freedouble(char **ptr)
{
	int a;

	a = 0;
	if (ptr)
	{
		while (ptr[a])
		{
			free(ptr[a]);
			ptr[a] = 0;
			a++;
		}
		free(ptr);
		ptr = 0;
	}
}

char	*ft_strdup(const char *src)
{
	char	*s1;
	int		len;
	int		i;

	i = 0;
	len = 0;
	len = ft_strlen(src);
	s1 = malloc(sizeof(char) * len + 1);
	if (!s1)
		return (0);
	while (src[i])
	{
		s1[i] = src[i];
		i++;
	}	
	s1[i] = '\0';
	return (s1);
}

void	print_map(t_game *game)
{
	int i;
	
	i = 0;
	while (game->map[i])
	{
		printf("%s\n", game->map[i]);
		i++;
	}
}

void	ft_init_struc(t_game *maps)
{
	maps->line.y = 1;
	maps->line.x = 0;
	maps->p = 0;
	maps->c = 0;
	maps->e = 0;
}