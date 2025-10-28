/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryatan <ryatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 12:46:55 by ryatan            #+#    #+#             */
/*   Updated: 2025/10/29 03:45:36 by ryatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_coord
{
	int	x;
	int	y;
	int	len;
}	t_coord;

typedef struct s_map_input
{
	char	empty;
	char	block;
	char	fill;
}	t_map_input;

// helpers
void	ft_putchar(char c);
void	ft_putstr(char *s);
int		ft_strlen(char *s);
int		ft_strlen2(char *str);
char	*ft_strdup(char	*str);
char **ft_duplicate_map(char **map);
void	free_inner_and_outer(char **arr);
int	ft_get_row_count(const char *str);

// parsing
void	ft_read_into_array(char ***array, char *str, int row, int buffer);
char	**ft_read_txt_file(const char *file_path, char **map);
int		ft_filebuffer(const char *file_path);
t_map_input	ft_input(char **map);
char	**ft_make_mask_map(char **mask, int cols, t_map_input input);

// solving
int	ft_get_rows(char **map);
void	ft_process_cell(char **map, int **cache, int i, int j);
void	ft_update_coord(int **cache, int i, int j, t_coord *coord);
int		**ft_prepare_cache(char **map, int *rows, int *cols);
t_coord	ft_find_square(char **map);
void	free_cache(int **cache, int cols);
void	ft_init_cache(int **cache, int rows, int cols);
void	ft_cache(int **cache, int row_value, int col_value, int biggest_length);
int		**ft_create_cache(int rows, int cols);
int		ft_min_of_three(int i, int j, int k);
char	**ft_make_solution(char ***map, t_map_input input, t_coord result);
#endif
