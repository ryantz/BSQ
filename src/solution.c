/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryatan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 23:40:40 by ryatan            #+#    #+#             */
/*   Updated: 2025/10/29 01:37:49 by ryatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h" 

char	**ft_make_solution(char ***map, t_map_input input, t_coord result)
{
	int	i;
	int	j;

	i = result.x;
	while (i > (result.x - result.len))
	{
		j = result.y;
		while (j > (result.y - result.len))
		{
			(*map)[i][j] = input.fill;
			j--;
		}
		i--;
	}
	return (*map);
}


