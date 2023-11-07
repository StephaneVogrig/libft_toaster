/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 19:15:39 by svogrig           #+#    #+#             */
/*   Updated: 2023/11/06 01:19:48 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test_stephane.h"

void	strlen_test(char *str)
{
	print_result_str_int_int(str, strlen(str), ft_strlen(str));
}

void	strlen_tests(void)
{
	int	fd;

	fd = open_file_msgs_error();


	print_fct_name("ft_strlen");
	strlen_test("test");
	strlen_test("");
	strlen_test("01234567, AAAAAA, abc\xba e, ......, end of string !");
	strlen_test("HAHAHAHA \0 TA FAIL XD");
	//strlen_test(NULL);
	printf("\n");

	print_message_error(fd);

	close(fd);
}