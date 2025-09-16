/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_dp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarino <lemarino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 19:34:40 by lemarino          #+#    #+#             */
/*   Updated: 2025/07/08 18:57:17 by lemarino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

// Frees a char matrix
void	**free_dpc(char **double_pointer_char)
{
	int	i;

	i = 0;
	while (double_pointer_char[i])
	{
		free(double_pointer_char[i]);
		i++;
	}
	free(double_pointer_char);
	return (NULL);
}
