/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryatan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 20:38:45 by ryatan            #+#    #+#             */
/*   Updated: 2025/10/27 21:54:28 by ryatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
//#include <stdio.h>
/*
int	ft_strlen(char *s)
{
	int	i = 0;
	while (s[i])
		i++;
	return(i);
}

typedef struct s_coord
{
	int x;
	int y;
	int len;
}	t_coord;
*/
void	free_cache(int **cache, int cols)
{
	int	i;

	i = 0;
	while (i < cols)
	{
		free(cache[i]);
		i++;
	}
	free(cache);
}

int	ft_min_of_three(int i, int j, int k)
{
	int	min;

	min = i;
	if (j < min)
		min = j;
	if (k < min)
		min = k;
	return (min);
}

int	**ft_create_cache(int rows, int cols)
{
	int	**cache;
	int	c;

	c = 0;
	cache = malloc(sizeof(int *) * rows);
	if (!cache)
		return (NULL);
	while (c < rows)
	{
		cache[c] = malloc(sizeof(int) * cols);
		if (!cache[c])
		{
			free_cache(cache, c);
			return (NULL);
		}
		c++;
	}
	return (cache);
}

void	ft_init_cache(int **cache, int rows, int cols)
{
	int	r_index;
	int	c_index;

	r_index = 0;
	while (r_index < rows)
	{
		c_index = 0;
		while (c_index < cols)
		{
			cache[r_index][c_index] = 0;
			c_index++;
		}
		r_index++;
	}
}

// stores (r, c) -> len of biggest sq
void	ft_cache(int **cache, int row_value, int col_value, int biggest_length)
{
	cache[row_value][col_value] = biggest_length;
}

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

/*
#include <stdio.h>
int	main(void) {

	t_coord	coords;
	char *map[] = {
    "11011",
    "11111",
    "11111",
    "11111",
    "11111",
    NULL
};
	coords = ft_find_square(map);
	printf("x: %d\ny: %d\nlen: %d\n", coords.x, coords.y, coords.len);
}
*/
