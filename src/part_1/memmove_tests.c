/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:06:05 by svogrig           #+#    #+#             */
/*   Updated: 2023/11/07 21:36:31 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test_stephane.h"

static void	test(void *dest, void *src, size_t n)
{
	ft_memmove(dest, src, n);
	print_succes(SUCCES);
}
/*
#include <string.h>

void *memmove(void *dest, const void *src, size_t n);

*/
void	memmove_tests(void)
{
	int	fd;
	//char *dest[0xdeadbeef];
	char *dest[42];

	bzero(dest,42);
	fd = open_file_msgs_error();

	print_fct_name("ft_memmove");

	test(NULL, "src", 0);
	test(NULL, NULL, 0);
	test(dest, NULL, 0);
	test(NULL, "src", 5);
	test(NULL, NULL, 5);
	test(dest, NULL, 5);

	printf("\n");

	print_message_error(fd);

	close(fd);
}