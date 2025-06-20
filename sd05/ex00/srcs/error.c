/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 09:59:15 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/20 10:02:47 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	error(t_data *data, int err_type)
{
	fd_printf(2, "Error %d\n");
	free_memory(data);
	exit(err_type);
}
