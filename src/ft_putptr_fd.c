/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:00:31 by svogrig           #+#    #+#             */
/*   Updated: 2023/11/08 01:03:22 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test_stephane.h"

size_t	ft_putptr_fd(void *ptr, int fd)
{
	char				adr_hex[18];
	int					i;
	unsigned long long	adr_ull;

	if (ptr == NULL)
	{
		write(fd, "NULL", 4);
		return (4);
	}
	adr_ull = (unsigned long long)ptr;
	i = 17;
	while (adr_ull > 0)
	{
		adr_hex[i] = adr_ull & 0xfULL;
		if (adr_hex[i] < 10)
			adr_hex[i] += '0';
		else
			adr_hex[i] += 'W';
		adr_ull = adr_ull >> 4;
		i--;
	}
	adr_hex[i--] = 'x';
	adr_hex[i] = '0';
	return (write(fd, &adr_hex[i], 18 - i));
}