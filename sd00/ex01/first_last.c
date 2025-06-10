/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_last.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 11:33:30 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/10 12:27:54 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "first_last.h"

int	main(void)
{
	struct timeval	time;
	int				nums[SIZE];
	int				i;
	int				frst_lst[2];
	int				target;

	i = 0;
	gettimeofday(&time, 0);
	target = time.tv_usec % SIZE;
	while (i != SIZE)
	{
		gettimeofday(&time, 0);
		nums[i] = time.tv_usec % SIZE;
		printf("%d:\t%d\n", i, nums[i]);
		++i;
	}
	first_last(nums, SIZE, target, &frst_lst[0], &frst_lst[1]);
	printf("\nTarget:\t%d\n", target);
	printf("\nFirst:\t%d\nLast:\t%d\n", frst_lst[0], frst_lst[1]);
}

void first_last(int arr[], int size, int target, int *first, int *last)
{
	int		i;
	
	if (first)
		*first = -1;
	if (last)
		*last = -1;
	if (!first || !last || size <= 0)
		return ;
	i = 0;
	while (i != size)
	{
		if (arr[i] == target)
		{
			if (*first == -1)
				*first = i;
			*last = i;
		}
		++i;
	}
}
