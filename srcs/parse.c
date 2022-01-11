/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qkherzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:38:51 by qkherzi           #+#    #+#             */
/*   Updated: 2021/12/06 18:02:54 by qkherzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_checkname(int ac, char **av)
{
	char	*str;
	
	if (ac == 2)
	{
		str = ft_strchr(av[1], 46);
		if (str && !ft_strcmp(str, ".ber"))
			return (1);
		else 
		{
			printf("Error:\nNot .ber\n");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		printf("Error:\nInvalid argument\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}

int	ft_checkfd(char *str)
{
	int	fd;

	fd = open(str, O_DIRECTORY);
	if (fd != -1)
	{
		printf("ERROR:\nDIRECTORY\n");
		exit(EXIT_FAILURE);
	}
	close(fd);
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		printf("ERROR:\nINVALID FILE\n");
		exit(EXIT_FAILURE);
	}
	return (fd);
}

void	ft_checkrec(char **str)
{
	int		a;
	size_t	b;

	a = 0;
	b = ft_strlen(str[a]);
	while (str[a])
	{
		if (ft_strlen(str[a]) != 0 && b != ft_strlen(str[a]))
		{
			printf("ERROR:\nMAP NOT RECTANGULAR\n");
			ft_freedouble(str);
			exit(EXIT_FAILURE);
		}
		if (ft_strlen(str[a]) == 0 && str[a + 1] && str[a + 1] == 0)
		{
			printf("ERROR:\nMAP NOT VALID\n");
			ft_freedouble(str);
			exit(EXIT_FAILURE);
		}
		a++;
	}
}

void	ft_get_map(char *av, int fd, t_game *maps)
{
	char	*line;
	int		i;

	line = NULL;
	while (get_next_line(fd, &line) == 1)
	{
		maps->line.y++;
		free(line);
	}
	free(line);
	maps->map = malloc(sizeof(char *) * (maps->line.y + 1));
	fd = open(av, O_RDONLY);
	i = -1;
	while (++i < maps->line.y)
	{
		get_next_line(fd, &line);
		maps->map[i] = ft_strdup(line);
		maps->line.x = ft_strlen(line);
		free(line);
	}
	maps->map[i] = 0;
	close(fd);
	ft_checkrec(maps->map);
}

void	ft_parse_map(t_game	*maps)
{
	int	i;
	int	j;

	i = -1;
	while (maps->map[++i])
	{
		j = -1;
		while (maps->map[i][++j])
		{
			if (maps->map[i][j] != 'E' && maps->map[i][j] != 'C' 
			&& maps->map[i][j] != 'P' && maps->map[i][j] != '0' 
			&& maps->map[i][j] != '1')
			{
				printf("ERROR:\nINVALID CHARACTER\n");
				ft_freedouble(maps->map);
				exit(EXIT_FAILURE);
			}
			if (maps->map[i][j] == 'P')
				maps->p++;
			else if (maps->map[i][j] == 'C')
				maps->c++;
			else if (maps->map[i][j] == 'E')
				maps->e++;
		}
	}
}

void	ft_error_map(t_game *maps)
{
	if (maps->p < 1 || maps->p > 1)
	{
		printf("ERROR:\nPLAYER");
		ft_freedouble(maps->map);
		exit(EXIT_FAILURE);
	}

	else if (maps->e < 1)
	{
		printf("ERROR:\nEXIT");
		ft_freedouble(maps->map);
		exit(EXIT_FAILURE);
	}

	else if (maps->c < 1)
	{
		printf("ERROR:\nCOLLECTIBLE");
		ft_freedouble(maps->map);
		exit(EXIT_FAILURE);
	}
}	