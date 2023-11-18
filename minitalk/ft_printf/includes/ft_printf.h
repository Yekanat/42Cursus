/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athekkan <athekkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:48:04 by athekkan          #+#    #+#             */
/*   Updated: 2023/10/21 01:26:44 by athekkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int	ft_print_char(int c);
int	ft_print_str(char *str);
int	ft_print_num(int nb);
int	ft_convert_add(unsigned long nb, char *s);
int	ft_print_point(unsigned long nb, char *s);
int	ft_print_unsign(unsigned int nb);
int	ft_print_hex(unsigned int nb, char *s);
int	ft_print_only(int c);
int	ft_check_type(va_list args, const char str);
int	ft_printf(const char *str, ...);

#endif
