/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_entires.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 08:48:31 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/20 11:31:54 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	valid_entry(char *line)
{
	int	count_entries;
	int	i;

	if (!line)
		return (false);
	count_entries = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == SEPARATOR)
			count_entries++;
		++i;
	}
	if (count_entries != TOTAL_ENTRIES - 1)
		return (false);
	return (true);
}

void	trim_spaces(char *line)
{
	int		i;
	bool	inside_entry;

	if (!line)
		return ;
	i = 0;
	inside_entry = false;
	while (line[i])
	{
		if (line[i] == SEPARATOR)
			inside_entry = false;
		else if (line[i] == TO_TRIM && inside_entry == false)
		{
			cut_string(line, i, i);
			--i;
		}
		else if (line[i] != TO_TRIM)
			inside_entry = true;
		++i;
	}
}
