/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:45:40 by ryatan            #+#    #+#             */
/*   Updated: 2025/10/29 04:02:28 by ryatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	char	**map = NULL;
	char	**mask = NULL;
	int	cols;
	t_map_input	input;
	t_coord	result;
	int	idx;
	int	i;

	if (argc == 1)
	{
		ft_putstr("use stdin");
		return (0);
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			map = ft_read_txt_file(argv[i], map);
			cols = ft_strlen(map[1]);
			input = ft_input(map);
			mask = ft_duplicate_map(map);
			mask = ft_make_mask_map(mask, cols, input);
			result = ft_find_square(mask);
			ft_make_solution(&map, input, result);
			idx = 0;
			while (idx < 10)
			{
				printf("%s\n", map[idx]);
				idx++;
			}
			free_inner_and_outer(mask);
			free_inner_and_outer(map);
			i++;
		}
	}
	return (0);
}
