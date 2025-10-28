/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:25:30 by stelim            #+#    #+#             */
/*   Updated: 2025/10/29 05:14:16 by ryatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	ft_read_into_array(char ***arr, char *str, int row, int buff)
{
	int	idx_y;
	int	idy;
	int	row_cnt;
	int	npar;

	*arr = malloc ((row + 1) * sizeof(char *));
	idx_y = 0;
	idy = 0;
	row_cnt = 0;
	npar = ft_strlen2(str);
	(*arr)[row_cnt] = malloc ((npar + 1) * sizeof(char));
	while (idy < buff)
	{
		if (str[idy] == '\n' || str[idy] == '\0')
		{
			(*arr)[row_cnt][idx_y] = '\0';
			row_cnt++;
			(*arr)[row_cnt] = malloc ((buff - npar) / (row - 1) * sizeof(char));
			idx_y = 0;
		}
		else
			(*arr)[row_cnt][idx_y++] = str[idy];
		idy++;
	}
	(*arr)[row_cnt] = NULL;
}

int	ft_filebuffer(const char *file_path)
{
	int		fd;
	int		len;
	char	holder[999999];

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		write(1, "File Error: File not found", 26);
	len = read(fd, &holder, 999999);
	close(fd);
	return (len);
}

char	**ft_read_txt_file(const char *file_path, char **map)
{
	int		fd;
	int		file_buffer;
	char	*map_fp;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		write(1, "File Error: File not found", 26);
	file_buffer = ft_filebuffer(file_path);
	map_fp = (char *) malloc (file_buffer * sizeof(char));
	read (fd, map_fp, file_buffer);
	close(fd);
	ft_read_into_array(&map, map_fp, (map_fp[0] - '0' + 2), file_buffer);
	return (map);
}

t_map_input	ft_input(char **map)
{
	t_map_input	output;
	char		*input;
	int			idx;

	input = map[0];
	idx = ft_strlen(input);
	output.empty = input[idx - 3];
	output.block = input[idx - 2];
	output.fill = input[idx - 1];
	return (output);
}

char	**ft_make_mask_map(char **mask, int cols, t_map_input input)
{
	int	i;
	int	j;

	i = 1;
	while (mask[i])
	{
		j = 0;
		while(j < cols)
		{
			if (mask[i][j] == input.empty)
				mask[i][j] = '1';
			else if (mask[i][j] == input.block)
				mask[i][j] = '0';
			j++;
		}
		i++;
	}
	return (mask);
}

/*
int	main(void)
{
	char	**map;
	map_input input;

	map = ft_read_txt_file("../test.txt", map);
	
	int idx = 0;

	while (idx < 11)
	{
		printf ("%s\n", map[idx]);
		idx++;
	}

	input = ft_input(map);
	free(map);
}
*/
