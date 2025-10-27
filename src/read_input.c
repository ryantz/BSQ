/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:25:30 by stelim            #+#    #+#             */
/*   Updated: 2025/10/27 21:59:05 by stelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_read_into_array(char ***array, char *str, int row, int buffer)
{
	int	idx_y;
	int	idy;
	int	row_count;

	*array = malloc (row * sizeof(char *));
	idx_y = 0;
	idy = 0;
	row_count = 0;
	(*array)[row_count] = malloc (buffer / row * sizeof(char));
	while (idy < buffer)
	{
		if (str[idy] == '\n' || str[idy] == '\0')
		{
			(*array)[row_count][idx_y] = '\0';
			row_count++;
			(*array)[row_count] = malloc (buffer / row * sizeof(char));
			idx_y = 0;
		}
		else
		{
			(*array)[row_count][idx_y] = str[idy];
			idx_y++;
		}
		idy++;
	}
	(*array)[row_count] = NULL;
}

int	ft_firstline(const char *file_path)
{
	int		fd;
	int		len;
	char	holder;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		write (1, "File Error: File not found", 26);
	holder = -1;
	len = 0;
	while (holder != '\n')
	{
		read(fd, &holder, 1);
		len++;
	}
	close(fd);
	return (len);
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
	int		fl;
	int		file_buffer;
	char	*map_fp;
	char	*n_rows;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		write(1, "File Error: File not found", 26);
	fl = ft_firstline(file_path);
	file_buffer = ft_filebuffer(file_path) - fl;
	n_rows = (char *) malloc (fl * sizeof(char));
	read (fd, n_rows, fl);
	map_fp = (char *) malloc (file_buffer * sizeof(char));
	read (fd, map_fp, file_buffer);
	close(fd);
	ft_read_into_array(&map, map_fp, (n_rows[0] - '0' + 1), file_buffer);
	return (map);
}

int	main(void)
{
	char	**map;

	map = ft_read_txt_file("../test.txt", map);
	free(map);
}
