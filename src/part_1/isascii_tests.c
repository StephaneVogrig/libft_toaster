/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isascii_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:22:06 by svogrig           #+#    #+#             */
/*   Updated: 2023/11/06 01:20:35 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test_stephane.h"

void isascii_test(int c)
{
    print_result_char_int_int((char)c, isascii(c), ft_isascii(c));
}

void isascii_tests(void)
{
	int	fd;

	fd = open_file_msgs_error();

    print_fct_name("ft_isascii");

    isascii_test(-1);
    isascii_test('\0');
    isascii_test(127);
    isascii_test(128);

    printf("\n");

	print_message_error(fd);

	close(fd);
}