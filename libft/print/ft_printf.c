/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <adegl-in@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:17:12 by adegl-in          #+#    #+#             */
/*   Updated: 2025/11/24 10:28:15 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_convert(va_list arg, const char format)
{
	int		printed;

	printed = 0;
	if (format == 'c')
		return (ft_putchar_fd(va_arg(arg, int), 1));
	else if (format == 's')
		return (ft_putstr_fd((va_arg(arg, char *)), 1));
	else if (format == 'd' || format == 'i')
		printed += ft_putnbr_fd(va_arg(arg, int), 1);
	else if (format == 'p')
		printed += ft_print_p(va_arg(arg, intptr_t *));
	else if (format == 'x' || format == 'X')
		printed += ft_print_hex(va_arg(arg, unsigned int), format);
	else if (format == 'u')
		printed += ft_print_u(va_arg(arg, unsigned int));
	else if (format == '%')
		printed += ft_putchar_fd(37, 1);
	return (printed);
}

int	ft_printf(const char *input, ...)
{
	int		i;
	int		printed;
	va_list	arg;

	i = 0;
	printed = 0;
	va_start(arg, input);
	if (!input)
		return (-1);
	while (input[i])
	{
		if (input[i] == '%')
		{
			printed += ft_convert(arg, input[i + 1]);
			i++;
		}
		else
		{
			write(1, &input[i], 1);
			printed ++;
		}
		i++;
	}
	va_end(arg);
	return (printed);
}
