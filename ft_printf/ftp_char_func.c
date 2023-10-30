/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_char_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athekkan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 20:12:12 by athekkan          #+#    #+#             */
/*   Updated: 2023/03/09 17:08:25 by athekkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(va_list param)
{
	char	buffer;

	buffer = va_arg(param, int);
	ft_putchar(buffer);
	return (1);
}
