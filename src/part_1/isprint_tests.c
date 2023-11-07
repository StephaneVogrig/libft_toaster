/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isprint_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:53:02 by svogrig           #+#    #+#             */
/*   Updated: 2023/11/06 01:20:29 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test_stephane.h"

void	isprint_test(int c)
{
	print_result_char_int_int((char)c, isprint(c), ft_isprint(c));
}

void	isprint_tests(void)
{
	int	fd;

	fd = open_file_msgs_error();

	print_fct_name("ft_isprint");

	isprint_test(' ');
	isprint_test(127);
	isprint_test(' ' - 1);
	isprint_test(128);

	printf("\n");

	print_message_error(fd);

	close(fd);

}
