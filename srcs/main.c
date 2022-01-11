/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qkherzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:37:43 by qkherzi           #+#    #+#             */
/*   Updated: 2021/12/06 17:38:39 by qkherzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
    int fd;
	t_game map;

	ft_init_struc(&map);
    fd = ft_checkfd(av[1]);
	if (fd)
	{
		ft_checkname(ac, av);
		ft_get_map(av[1], fd, &map);
		ft_parse_map(&map);
		ft_error_map(&map);
		print_map(&map);
	}
}