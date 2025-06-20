/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 18:34:03 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/20 14:21:13 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include "../header.h"
# include <fcntl.h>

# define TO_TRIM ' '
# define SEPARATOR ','
# define SEPARATOR_S ",\n"
# define D_NAME "lib.csv"
# define NAMES "id", "author", "book"
# define FILES "id_"D_NAME, "author_"D_NAME, "book_"D_NAME

typedef struct s_data	t_data;
typedef struct s_entry	t_entry;

enum e_entries
{
	ID,
	AUTHOR_NAME,
	BOOK_NAME,
	TOTAL_ENTRIES,
};

enum e_errors
{
	ER_NOERR,
	ER_MALLOC,
	ER_OPEN,
	ER_PARSING,
	ER_MISSING_DATABASE,
	ER_MISSING_NAME_HEADER,
};

enum	Alphabet
{
	LETTER_A,
	LETTER_B,
	LETTER_C,
	LETTER_D,
	LETTER_E,
	LETTER_F,
	LETTER_G,
	LETTER_H,
	LETTER_I,
	LETTER_J,
	LETTER_K,
	LETTER_L,
	LETTER_M,
	LETTER_N,
	LETTER_O,
	LETTER_P,
	LETTER_Q,
	LETTER_R,
	LETTER_S,
	LETTER_T,
	LETTER_U,
	LETTER_V,
	LETTER_W,
	LETTER_X,
	LETTER_Y,
	LETTER_Z,
	ALPHABET_SIZE,
};

enum e_perms
{
	P_CREATE = O_RDWR | O_CREAT,
	P_EXIST = O_RDWR | O_EXCL,
};

struct s_entry
{
	char	*name;
	char	*filename;
	int		offsets[ALPHABET_SIZE];
	int		first_entry;
	int		last_element;
	int		size;
};

struct s_data
{
	t_entry	entry[TOTAL_ENTRIES];
	char	**entries[TOTAL_ENTRIES];
	char	*filename;
	int		*offsets;
	int		last_error;
};


#endif