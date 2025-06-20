/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 09:57:52 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/20 11:26:43 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static int	alloc_matrix(t_data *data, int i);

void	free_memory(t_data *data)
{
	int	i;

	i = 0;
	while (i != TOTAL_ENTRIES)
	{
		unlink(data->entry[i].filename);
		data->entries[i] = free_matrix(data->entries[i]);
		++i;
	}
}

void	alloc_memory(t_data *data)
{
	int	i;

	i = 0;
	while (i != TOTAL_ENTRIES)
	{
		if (alloc_matrix(data, i) == 1)
			error(data, ER_MALLOC);
		++i;
	}
}

static int	alloc_matrix(t_data *data, int i)
{
	data->entries[i] = ft_calloc(2, sizeof(char *));
	if (!data->entries[i])
		return (1);
	data->entry[i].last_element = 0;
	data->entry[i].size = 2;
	return (0);
}

int	free_all_matrix(t_data *data)
{
	int	i;

	i = 0;
	while (i != TOTAL_ENTRIES)
	{
		data->entries[i] = free_matrix(data->entries[i]);
		++i;
	}
	return (0);
}
