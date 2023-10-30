/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athekkan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:18:54 by athekkan          #+#    #+#             */
/*   Updated: 2023/02/14 15:10:05 by athekkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	i;

	i = count * size;
	ptr = malloc(i);
	if (i / size != count)
		return (0);
	if (!ptr)
		return (NULL);
	while (i--)
		((char *)ptr)[i] = 0;
	return (ptr);
}
