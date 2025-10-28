/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cache.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryatan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 20:38:45 by ryatan            #+#    #+#             */
/*   Updated: 2025/10/29 00:10:26 by ryatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

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
