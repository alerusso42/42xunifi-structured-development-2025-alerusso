/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_matrix2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 10:55:26 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/20 11:56:54 by alerusso         ###   ########.fr       */
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

/*
void	copy_entries(t_data *data, int entry, char *line)
{
	int	i;
	int	j;
	int	k;

	j = move_str(data->entries[entry], SEPARATOR, data->entry[entry].first_entry);
	sub_strcpy(line, data->entries[entry], SEPARATOR_S, EXCLUDE);
	i = 0;
	while (i != TOTAL_ENTRIES)
	{
		++i;
	}
}*/

/*
void	prioritize_item(t_data *data, int entry)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	while (i != data->entry[entry].last_element + 1)
	{
		line = ft_calloc(ft_strlen(data->entries[entry]), sizeof(char));
		if (!line)
			error(data, ER_MALLOC);
		copy_entries(data, entry, line);
		
	}
}*/
