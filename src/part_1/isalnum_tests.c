/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isalnum_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:55:09 by svogrig           #+#    #+#             */
/*   Updated: 2023/11/06 01:15:46 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test_stephane.h"

void isalnum_test(int c)
{
	print_result_char_int_int((char)c, isalnum(c), ft_isalnum(c));
}

void	isalnum_tests(void)
{
	int	fd;

	fd = open_file_msgs_error();

    print_fct_name("ft_isalnum");

    isalnum_test('a');
    isalnum_test('z');
    isalnum_test('a' - 1);
    isalnum_test('z' + 1);
    isalnum_test('A');
    isalnum_test('Z');
    isalnum_test('A' - 1);
    isalnum_test('Z' + 1);
	isalnum_test('0');
	isalnum_test('9');
	isalnum_test('0' - 1);
	isalnum_test('9' + 1);
    isalnum_test('\0');

    printf("\n");

	print_message_error(fd);

	close(fd);
}
