/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 18:46:54 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/20 11:59:54 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

//	cd Libft, make all, cp libft.a ../
//	comp: cc -Wall -Wextra -Werror -g main.c srcs/*.c libft.a
int	main()
{
	t_data	data;

	data = (t_data){0};
	set_entries(&data);
	alloc_memory(&data);
	parsing(&data);
	//loop(&data);
	free_memory(&data);
	return (0);
}
