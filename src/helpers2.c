/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryatan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 02:00:51 by ryatan            #+#    #+#             */
/*   Updated: 2025/10/29 03:54:04 by ryatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char **ft_duplicate_map(char **map)
{
	int	rows;
	char	**dup;
	int	i;
	int	j;
	
	rows = 0;
	while (map[rows])
	    rows++;
	dup = malloc(sizeof(char *) * (rows + 1));
	if (!dup)
	    return NULL;
	i = 0;
	while (i < rows)
	{
	    dup[i] = ft_strdup(map[i]);
	    if (!dup[i])
	    {
		    j = 0;
		    while (j < i)
			    free(dup[j]);
		    free(dup);
		    return NULL;
	    }
	    i++;
	}
	dup[rows] = NULL;
	return dup;
}

void	free_inner_and_outer(char **arr)
{
	int	i;
	
	i = 0;
	if (!arr)
		return ;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

int ft_get_row_count(const char *str)
{
    int count = 0;
    int i = 0;
    while (str[i] && str[i] >= '0' && str[i] <= '9')
    {
        count = count * 10 + (str[i] - '0');
        i++;
    }
    return count;
}
