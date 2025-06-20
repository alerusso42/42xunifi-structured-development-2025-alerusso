/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 10:26:02 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/20 12:24:48 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static void	add_line(t_data *data, char *line, int fd);

void	parsing(t_data *data)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(data->filename, P_EXIST, 0777);
	if (fd < 0)
		error(data, ER_MISSING_DATABASE);
	line = get_next_line(fd, false);
	while (line)
	{
		if (valid_entry(line) == true)
			add_line(data, line, fd);
		free(line);
		line = get_next_line(fd, false);
	}
	i = 0;
	close(fd);
	while (i != TOTAL_ENTRIES)
	{
		prioritize_main_entry(data, i);
		sort_matrix(data->entries[i]);
		print_matrix(data, data->entries[i], data->entry[i].filename);
		offset_matrix(data, i);
		++i;
	}
	unlink(data->filename);
	rewrite_file(data, data->filename, data->entry[ID].filename);
	free_all_matrix(data);
}

static void	add_line(t_data *data, char *line, int fd)
{
	int	i;

	trim_spaces(line);
	i = 0;
	while (i != TOTAL_ENTRIES)
	{
		if (data->entry[i].last_element >= data->entry[i].size)
		{
			if (resize_matr(&data->entries[i], &data->entry[i].size) == 1)
			{
				close(fd);
				error(data, ER_MALLOC);
			}
		}
		data->entries[i][data->entry[i].last_element] = ft_strdup(line);
		if (!data->entries[i][data->entry[i].last_element])
		{
			close(fd);
			error(data, ER_MALLOC);
		}
		data->entry[i].last_element++;
		++i;
	}
}
