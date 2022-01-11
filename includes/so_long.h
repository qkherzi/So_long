/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qkherzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:47:36 by qkherzi           #+#    #+#             */
/*   Updated: 2021/12/06 17:51:37 by qkherzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

typedef	struct	s_pos
{
	int x;
	int y;
}				t_pos;

typedef struct	s_game
{
	char **map;
	t_pos line;
	int	e;
	int	p;
	int	c;
}				t_game;

char	*ft_strchr(const char *s, int c);
int	    ft_strcmp(char *s1, char *s2);
size_t	ft_strlen(const char *s);
void	ft_freedouble(char **ptr);
char	*ft_substr(char *s, unsigned int start, size_t len);
void	print_map(t_game *game);
void	ft_init_struc(t_game *maps);

int	    ft_checkfd(char *str);
int	    ft_checkname(int ac, char **av);
void	ft_checkrec(char **str);
int		ft_strrlen(char *str);
void	ft_strncpy(char *dst, char *src, int n);
int		ft_strrchr(char *str, int *c);
char	*ft_strjoin(char const *s1, char const *s2);
int		get_next_line(int fd, char **line);
char	*ft_strdup(const char *src);
void	ft_get_map(char *str, int fd, t_game *maps);
void	ft_parse_map(t_game	*maps);
void	ft_error_map(t_game *maps);

#endif
