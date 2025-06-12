/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grade_mapping.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 11:33:30 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/12 17:16:50 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grade_mapping.h"

int	random(int size)
{
	struct timeval	time;

	gettimeofday(&time, 0);
	usleep(1000);
	return (time.tv_usec % size);
}

void standard(const char **mapped_grades, const int *scores, int size)
{
	int i;

	i = 0;
	while(i < size)
	{
		if(scores[i] <= F)
			mapped_grades[i] = F_s;
		else if (scores[i] <= DP)
			mapped_grades[i] = D_s;
		else if (scores[i] <= CP)
			mapped_grades[i] = C_s;
		else if (scores[i] <= BP)
			mapped_grades[i] = B_s;
		else if (scores[i] <= AP)
			mapped_grades[i] = A_s;
		i++;
	}
}

void passfail(const char **mapped_grades, const int *scores, int size)
{
	int i;

	i = 0;
	while(i < size)
	{
		if(scores[i] <= F)
			mapped_grades[i] = F_s;
		else if (scores[i] <= AP)
			mapped_grades[i] = P_s;
		i++;
	}
}

void plusminus(const char **mapped_grades, const int *scores, int size)
{
	int i;

	i = 0;
	while(i < size)
	{
		if(scores[i] <= F)
			mapped_grades[i] = F_s;
		else if (scores[i] <= DM)
			mapped_grades[i] = DM_s;
		else if (scores[i] <= D)
			mapped_grades[i] = D_s;
		else if (scores[i] <= DP)
			mapped_grades[i] = DP_s;
		else if (scores[i] <= CM)
			mapped_grades[i] = CM_s;
		else if (scores[i] <= C)
			mapped_grades[i] = C_s;
		else if (scores[i] <= CP)
			mapped_grades[i] = CP_s;
		else if (scores[i] <= BM)
			mapped_grades[i] = BM_s;
		else if (scores[i] <= B)
			mapped_grades[i] = B_s;
		else if (scores[i] <= BP)
			mapped_grades[i] = BP_s;
		else if (scores[i] <= AM)
			mapped_grades[i] = AM_s;
		else if (scores[i] <= A)
			mapped_grades[i] = A_s;
		else if (scores[i] <= AP)
			mapped_grades[i] = AP_s;
		i++;
	}
}

void map_scores(const int *scores, int size, GradeMapper mapper, const char **mapped_grades)
{
	if(mapper == STANDARD)
	{
		standard(mapped_grades, scores, size);
	}
	else if(mapper == PLUSMINUS)
	{
		plusminus(mapped_grades, scores, size);
	}
	else if(mapper == PASSFAIL)
	{
		passfail(mapped_grades, scores, size);
	}

}

/*
	Da fare:
	controllo voto < 0 e > 100 (ASSEGNA A NULL)
*/
int	main(void)
{

	int		i;
	char	*grades_conv[SIZE + 1];
	int		grades_int[SIZE + 1];
	GradeMapper map = MAP;

	i = -1;
	while (++i != SIZE)
		grades_int[i] = random(SIZE);
	map_scores(grades_int, SIZE, map, (const char **)grades_conv);
	i = -1;
	while (++i != SIZE)
	{
		printf("Num:\t\t%d\n", grades_int[i]);
		printf("Grade:\t\t%s\n", grades_conv[i]);
	}
	return (0);
}