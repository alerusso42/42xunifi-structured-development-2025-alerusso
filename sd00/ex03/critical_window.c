/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   critical_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 11:33:30 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/11 11:21:48 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "critical_window.h"

static int 		check_segment(const int *arr, int size, int i);
static float	average(const int *arr, int size);

int	random(int size)
{
	struct timeval	time;

	usleep(1000);
	gettimeofday(&time, 0);
	return (time.tv_usec % size);
}

int	main(void)
{
	int				nums[SIZE];
	int				i;

	i = 0;
	while (i != SIZE)
	{
		nums[i] = random(SIZE * 15);
		printf("%d:\t%d\n", i, nums[i]);
		++i;
	}
	int	test[10] = {0, 1, 1, -1};
	printf("\nSegments:\t%d\n", count_critical_windows(nums, SIZE));
}


int count_critical_windows(const int *readings, int size)
{
	int		i;
	int		count;

	if (!readings)
		return (0);
	i = 0;
	count = 0;
	while (i + 5 < size)
	{
		count += check_segment(readings, size, i);
		++i;
	}
	return (count);
}

static int check_segment(const int *arr, int size, int i)
{
	int	bigger_seventy;
	int	count;

	if (average(arr + i, 5) >= (float)90)
		return (1);
	bigger_seventy = 0;
	count = 0;
	while (i != size && count != 5)
	{
		if (arr[i] >= 70)
			bigger_seventy += 1;
		if (arr[i] > 150)
			return (1);
		i++;
		count++;
	}
	if (bigger_seventy > 2)
		return (1);
	return (0);
}

static float	average(const int *arr, int size)
{
	float	av;
	int		i;

	av = 0;
	if (size <= 0 || !arr)
		return (av);
	i = 0;
	while (i != (float)size)
	{
		if (arr[i] > 0 && arr[i] <= 100)
			av += arr[i];
		++i;
	}
	return (av / (float)size);
}
