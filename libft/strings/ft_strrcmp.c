/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrcmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <adegl-in@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 14:44:58 by adegl-in          #+#    #+#             */
/*   Updated: 2025/11/24 10:28:15 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

// Compares exactly the last n bytes of the two strings s1 and s2.
//  Returns 1 if all bytes are equal, 0 otherwise.
int	ft_strrcmp(const char *s1, const char *s2, size_t n)
{
	int	i;
	int	l1;
	int	l2;

	i = n;
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	while (i >= 0)
	{
		if (s1[l1--] != s2[l2--])
			return (0);
		i--;
	}
	return (1);
}
