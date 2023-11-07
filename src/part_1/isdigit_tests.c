/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isdigit_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:44:50 by svogrig           #+#    #+#             */
/*   Updated: 2023/11/06 01:20:32 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test_stephane.h"


void	isdigit_test(int c)
{
	print_result_char_int_int((char)c, isdigit(c), ft_isdigit(c));
}
void	isdigit_tests()
{
	int	fd;

	fd = open_file_msgs_error();

	print_fct_name("ft_isdigit");

	isdigit_test('0');
	isdigit_test('9');
	isdigit_test('0' - 1);
	isdigit_test('9' + 1);
    isdigit_test('\0');

    printf("\n");

	print_message_error(fd);

	close(fd);

}
