/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 21:48:32 by svogrig           #+#    #+#             */
/*   Updated: 2023/11/15 22:22:54 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test_stephane.h"

void	put_str(char *str, int fd)
{
	write(fd, "\"", 1);
	write(fd, str, strlen(str));
	write(fd, "\"", 1);
}

void	put_int(int n, int fd)
{
	char	digit;

	if (n < 0)
	{
		if (n == -2147483648)
		{
			write(fd, "-2147483648", 11);
			return ;
		}
		n = -n;
		write (fd, "-", 1);
	}
	if (n > 9)
	{
		put_int(n / 10, fd);
		n = n % 10;
	}
	digit = '0' + n;
	write (fd, &digit, 1);
}

void	put_ptr(void *ptr, int fd)
{
	char				adr_hex[18];
	int					i;
	unsigned long long	adr_ull;

	if (ptr == NULL)
	{
		write(fd, "NULL", 4);
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
	write(fd, &adr_hex[i], 18 - i);
}
