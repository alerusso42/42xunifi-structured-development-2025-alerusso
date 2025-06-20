/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_entries.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 09:19:26 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/20 10:27:29 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	set_entries(t_data *data)
{
	char	*names[TOTAL_ENTRIES + 1] = {NAMES};
	char	*files[TOTAL_ENTRIES + 1] = {FILES};
	int		i;

	data->filename = D_NAME;
	i = 0;
	while (names[i] && files[i] && i < TOTAL_ENTRIES)
	{
		data->entry[i].first_entry = i;
		data->entry[i].name = names[i];
		data->entry[i].filename = files[i];
		++i;
	}
	if (i != TOTAL_ENTRIES)
		error(data, ER_MISSING_NAME_HEADER);
}
