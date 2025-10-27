/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryatan <ryatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 12:46:55 by ryatan            #+#    #+#             */
/*   Updated: 2025/10/27 22:03:06 by ryatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct	s_coord_len 
{
	int	x;
	int	y;
	int	len;
}	t_coord_len;

// helpers
void	ft_putchar(char c);
void	ft_putstr(char *s);
int	ft_strlen(char *s);

// parsing
void	ft_read_into_array(char ***array, char *str, int row, int buffer);
int	ft_firstline(const char *file_path);
int	ft_filebuffer(const char *file_path);
char	**ft_read_txt_file(const char *file_path, char **map);

// solving
void	free_cache(int **cache, int cols);
int	**ft_create_cache(int rows, int cols);
void	ft_init_cache(int **cache, int rows, int cols);
void	ft_cache(int **cache, int row_value, int col_value, int biggest_length);
int	ft_min_of_three(int i, int j, int k)
t_coord	ft_find_square(char **map);

#endif
