/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_matrix2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 10:55:26 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/20 12:47:11 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	offset_matrix(t_data *data, int entry)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i != ALPHABET_SIZE)
	{
		if (!data->entries[entry][j] || \
			 unsensitive_check(data->entries[entry][j][0], 'a' + 1) == false)
		{
			data->entry[entry].offsets[i] = -1;
			++i;
		}
		else if (data->entries[entry][j])
			++j;
	}
}

static void	copy_entries(t_data *data, int entry, int n_elem, char *line)
{
	int	i;
	int	j;

	j = move_str(data->entries[entry][n_elem], SEPARATOR, data->entry[entry].first_entry);
	sub_strcpy(line, data->entries[entry][n_elem] + j, SEPARATOR_S, EXCLUDE);
	j = move_str(data->entries[entry][n_elem], SEPARATOR, data->entry[entry].first_entry + 1);
	line[j - 1] = SEPARATOR;
	i = 0;
	while (i != TOTAL_ENTRIES)
	{
		if (i != data->entry[entry].first_entry)
		{
			j = move_str(data->entries[entry][n_elem], SEPARATOR, i);
			sub_strcpy(line + j, data->entries[entry][n_elem] + j, SEPARATOR_S, EXCLUDE);
			j = move_str(data->entries[entry][n_elem], SEPARATOR, i + 1);
			line[j - 1] = SEPARATOR;
		}
		++i;
	}
	line[j - 1] = '\n';
}

void	prioritize_main_entry(t_data *data, int entry)
{
	char	*line;
	int		i;

	i = 0;
	while (data->entries[entry][i])
	{
		line = ft_calloc(ft_strlen(data->entries[entry][i]), sizeof(char));
		if (!line)
			error(data, ER_MALLOC);
		copy_entries(data, entry, i, line);
		free(data->entries[entry][i]);
		data->entries[entry][i] = line;
		++i;
	}
}
