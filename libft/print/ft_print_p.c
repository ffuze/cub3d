/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <adegl-in@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 17:25:36 by adegl-in          #+#    #+#             */
/*   Updated: 2025/11/24 10:28:15 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_putnbr_p(unsigned long nbr)
{
	int	l;

	l = 0;
	if (nbr >= 16)
	{
		l += ft_putnbr_p((nbr / 16));
		l += ft_putnbr_p((nbr % 16));
	}
	else
	{
		if (nbr <= 9)
			l += ft_putchar_fd((nbr + '0'), 1);
		else
			l += ft_putchar_fd((nbr - 10 + 'a'), 1);
	}
	return (l);
}

int	ft_print_p(intptr_t *p)
{
	int	l;

	l = 0;
	if (!p)
		return (write(1, "(nil)", 5));
	l += write(1, "0x", 2);
	l += ft_putnbr_p((unsigned long)p);
	return (l);
}
