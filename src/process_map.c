/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryatan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 22:20:50 by ryatan            #+#    #+#             */
/*   Updated: 2025/10/29 03:52:14 by ryatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

// returns max area of square if that point is the top left
int	ft_get_rows(char **map)
{
	int	rows;

	rows = 0;
	while (map[rows])
		rows++;
	return (rows);
}

void	ft_process_cell(char **map, int **cache, int i, int j)
{
	if (!map[i] || j >= ft_strlen(map[i]))
		return ;
	if (map[i][j] == '1')
	{
		if (i == 0 || j == 0)
			cache[i][j] = 1;
		else
			cache[i][j] = 1 + ft_min_of_three(
					cache[i - 1][j],
					cache[i][j - 1],
					cache[i - 1][j - 1]);
	}
	else
		cache[i][j] = 0;
}

void	ft_update_coord(int **cache, int i, int j, t_coord *coord)
{
	if (cache[i][j] > coord->len)
	{
		coord->len = cache[i][j];
		coord->x = i;
		coord->y = j;
	}
}

int	**ft_prepare_cache(char **map, int *rows, int *cols)
{
	int	**cache;

	*rows = ft_get_rows(map) - 1;
	*cols = ft_strlen(map[1]);
	cache = ft_create_cache(*rows, *cols);
	ft_init_cache(cache, *rows, *cols);
	return (cache);
}

t_coord	ft_find_square(char **map)
{
	int		**cache;
	t_coord	coord;
	int		size[2];
	int		i;
	int		j;

	cache = ft_prepare_cache(map, &size[0], &size[1]);
	coord.x = 0;
	coord.y = 0;
	coord.len = 0;
	i = 0;
	while (i < size[0])
	{
		j = 0;
		while (j < size[1])
		{
			ft_process_cell(map, cache, i, j);
			ft_update_coord(cache, i, j, &coord);
			j++;
		}
		i++;
	}
	free_cache(cache, size[0]);
	return (coord);
}

/*
#include <stdio.h>
int	main(void)
{
	char *map[] = {
		"11111111111111111111111111111",
		"11111111111111111111111111111",
		NULL
	};

	t_coord result = ft_find_square(map);

	printf("Largest square found:\n");
	printf("  Bottom-right corner: (%d, %d)\n", result.x, result.y);
	printf("  Size: %d\n", result.len);

	return (0);
}
*/
