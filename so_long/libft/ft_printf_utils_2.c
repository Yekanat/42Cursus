/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athekkan <athekkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:39:03 by athekkan          #+#    #+#             */
/*   Updated: 2023/11/21 18:40:15 by athekkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_unsign(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb > 9)
		i += ft_print_num(nb / 10);
	i += ft_print_char(nb % 10 + 48);
	return (i);
}

int	ft_print_hex(unsigned int nb, char *s)
{
	int	i;

	i = 0;
	if (nb >= 16)
		i += ft_print_hex(nb / 16, s);
	i += ft_print_char(s[nb % 16]);
	return (i);
}

int	ft_print_only(int c)
{
	return (ft_print_char(c));
}

int	ft_check_type(va_list args, const char str)
{
	int	cur_val;

	cur_val = 0;
	if (str == 'c')
		cur_val += ft_print_char(va_arg(args, int));
	else if (str == 's')
		cur_val += ft_print_str(va_arg(args, char *));
	else if (str == 'd' || str == 'i')
		cur_val += ft_print_num(va_arg(args, int));
	else if (str == 'p')
		cur_val += ft_print_point(va_arg(args, unsigned long),
				"0123456789abcdef");
	else if (str == 'u')
		cur_val += ft_print_unsign(va_arg(args, unsigned int));
	else if (str == 'x')
		cur_val += ft_print_hex(va_arg(args, unsigned int),
				"0123456789abcdef");
	else if (str == 'X')
		cur_val += ft_print_hex(va_arg(args, unsigned int),
				"0123456789ABCDEF");
	else if (str == '%')
		cur_val += ft_print_only('%');
	return (cur_val);
}
