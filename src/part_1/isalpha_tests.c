/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isalpha_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:35:51 by svogrig           #+#    #+#             */
/*   Updated: 2023/11/06 01:20:38 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test_stephane.h"

void isalpha_test(int c)
{
    print_result_char_int_int((char)c, isalpha(c), ft_isalpha(c));
}

void isalpha_tests(void)
{
	int	fd;

	fd = open_file_msgs_error();

    print_fct_name("ft_isalpha");

    isalpha_test('a');
    isalpha_test('z');
    isalpha_test('a' - 1);
    isalpha_test('z' + 1);
    isalpha_test('A');
    isalpha_test('Z');
    isalpha_test('A' - 1);
    isalpha_test('Z' + 1);
    isalpha_test('\0');
    isalpha_test(128);
    isalpha_test(-128);
    isalpha_test(-129);

    printf("\n");

	print_message_error(fd);

	close(fd);
}
