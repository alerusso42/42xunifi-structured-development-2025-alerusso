/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grade_mapping.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 11:33:27 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/12 17:16:11 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PASSWORD_VALIDATION_H
# define PASSWORD_VALIDATION_H

# include <sys/time.h>
# include <sys/wait.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>

//Qui definisci mappa e numero di voti (generati a caso)
#define MAP PASSFAIL
#define SIZE 100

#define F_s "F"
#define DM_s "D-"
#define D_s "D"
#define DP_s "D+"
#define CM_s "C-"
#define C_s "C"
#define CP_s "C+"
#define BM_s "B-"
#define B_s "B"
#define BP_s "B+"
#define AM_s "A-"
#define A_s "A"
#define AP_s "A+"
#define P_s "P"

char	*grade_p = P_s;
char	*grade_ap = AP_s;
char	*grade_a = A_s;
char	*grade_am = AM_s;
char	*grade_bp = BP_s;
char	*grade_b = B_s;
char	*grade_bm = BM_s;
char	*grade_cp = CP_s;
char	*grade_c = C_s;
char	*grade_cm = CM_s;
char	*grade_dp = DP_s;
char	*grade_d = D_s;
char	*grade_dm = DM_s;
char	*grade_f = F_s;

enum e_plusminus
{
	F = 59,
	DM = 62,
	D = 66,
	DP = 69,
	CM = 72,
	C = 76,
	CP = 79,
	BM = 82,
	B = 86,
	BP = 89,
	AM = 92,
	A = 96,
	AP = 100,
	PLUSMINUS_SIZE = 13,
	PASSFAIL_SIZE = 2,
	STANDARD_SIZE = 5,
};

enum	e_bool
{
	TRUE,
	FALSE,
};

typedef enum s_GradeMapper
{
	PLUSMINUS = PLUSMINUS_SIZE,
	STANDARD = PASSFAIL_SIZE,
	PASSFAIL = STANDARD_SIZE,
}GradeMapper;

void map_scores(const int *scores, int size, GradeMapper mapper, const char **mapped_grades);

#endif