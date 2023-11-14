/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 22:33:41 by svogrig           #+#    #+#             */
/*   Updated: 2023/11/14 14:49:19 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test_stephane.h"

static void	test(char *str, int fd)
{
	int	result_user;
	int	result_ref;
	int error;

	result_user = ft_atoi(str);
	result_ref = atoi(str);

	error = (result_user != result_ref);
	print_succes(error == 0);
	if (error)
	{
		log_tested_title(fd);
		log_result_int(result_ref, result_user, fd);
	}
}

void	atoi_tests(void)
{
	int	fd;

	fd = open_file_msgs_error();

	print_fct_name("ft_atoi");

	test("0", fd);
	test("-2147483648", fd);
	test("2147483647", fd);
	test("-21474a83648", fd);
	test("  \f \n \r \t \v   -2147483648", fd);
	test("  fd -2147483648", fd);
	test("-21474836480000", fd);
	test("999999999999999", fd);

	printf("\n");

	print_message_error(fd);

	close(fd);
}
