/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryatan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 22:20:50 by ryatan            #+#    #+#             */
/*   Updated: 2025/10/27 22:21:20 by ryatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

// returns max area of square if that point is the top left
t_coord	ft_find_square(char **map)
{
	int		**cache;
	int		rows;
	int		cols;
	int		i;
	int		j;
	int		max_len;
	t_coord	coord;

	rows = 0;
	cols = 0;
	max_len = 0;
	i = 0;
	while (map[rows])
		rows++;
	cols = ft_strlen(map[0]);
	cache = ft_create_cache(rows, cols);
	ft_init_cache(cache, rows, cols);
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			if (map[i][j] == '1')
			{
				if (i == 0 || j == 0)
					cache[i][j] = 1;
				else
					ft_cache(cache, i, j, (1 + ft_min_of_three(cache[i - 1][j],
							cache[i][j - 1], cache[i - 1][j - 1])));
				if (cache[i][j] > max_len)
				{
					max_len = cache[i][j];
					coord.x = i;
					coord.y = j;
					coord.len = max_len;
				}
			}
			else
				cache[i][j] = 0;
			j++;
		}
		i++;
	}
	int k = 0;
	while (k < rows)
	{
		int z = 0;
		while (z < cols)
		{
			printf("%d", cache[k][z]);
			z++;
		}
		printf("\n");
		k++;
	}
	free_cache(cache, cols);
	return (coord);
}
