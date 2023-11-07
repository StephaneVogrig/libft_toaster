/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:05:34 by svogrig           #+#    #+#             */
/*   Updated: 2023/11/07 21:46:20 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test_stephane.h"

static void	test(void *dest, const void *src, size_t n)
{
	ft_memcpy(dest, src, n);
	print_succes(SUCCES);
}
/*
#include <string.h>

    void *memcpy(void *dest, const void *src, size_t n);

*/

void	memcpy_tests(void)
{
	int	fd;

	fd = open_file_msgs_error();


	print_fct_name("ft_memcpy");

	test(NULL, "src", 0);
	test(NULL, NULL, 0);
/*	test(dest, NULL, 0);
	test(NULL, "src", 5);
	test(NULL, NULL, 5);
	test(dest, NULL, 5);
*/
	printf("\n");

	print_message_error(fd);

	close(fd);
}