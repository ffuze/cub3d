/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <adegl-in@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 18:22:57 by adegl-in          #+#    #+#             */
/*   Updated: 2025/11/24 10:28:15 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	nlen(unsigned int nbr)
{
	int	l;

	l = 0;
	while (nbr)
	{
		nbr /= 16;
		l++;
	}
	return (l);
}

static void	fd_putnbr_hex(int fd, unsigned int nbr, const char format)
{
	if (nbr >= 16)
	{
		fd_putnbr_hex(fd, (nbr / 16), format);
		fd_putnbr_hex(fd, (nbr % 16), format);
	}
	else
	{
		if (nbr <= 9)
			ft_putchar_fd((nbr + '0'), fd);
		else
		{
			if (format == 'x')
				ft_putchar_fd((nbr - 10 + 'a'), fd);
			else if (format == 'X')
				ft_putchar_fd((nbr - 10 + 'A'), fd);
		}
	}
}

int	fd_print_hex(int fd, unsigned int nbr, const char format)
{
	if (nbr == 0)
		return (write(fd, "0", 1));
	else
		fd_putnbr_hex(fd, nbr, format);
	return (nlen(nbr));
}
