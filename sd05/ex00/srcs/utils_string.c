/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 10:15:57 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/20 11:49:48 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

bool	unsensitive_check(char c1, char c2);

int	sub_strcmp(const char *s1, const char *s2, char *charset)
{
	if (!s1 || !s2)
		return (0);
	while (!ft_strchr(charset, *s1) && !ft_strchr(charset, *s2) && \
	 unsensitive_check(*s1, *s2) == true)
	{
		++s1;
		++s2;
	}
	return ((unsigned char)(*s1) - (unsigned char)(*s2));
}

bool	unsensitive_check(char c1, char c2)
{
	if (c1 == c2)
		return (true);
	else if (c1 >= 'A' && c1 <= 'Z')
		c1 += 32;
	else if (c1 >= 'a' && c1 <= 'z')
		c1 -= 32;
	if (c1 == c2)
		return (true);
	return (false);
}

int	move_str(char *s, char c, int moves)
{
	int	i;
	int	count;

	if (!s)
		return (0);
	i = 0;
	count = 0;
	while (s[i] && count != moves)
	{
		if (s[i] == c)
			++count;
		++i;
	}
	return (i);
}
