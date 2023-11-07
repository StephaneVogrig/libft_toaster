/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 22:33:41 by svogrig           #+#    #+#             */
/*   Updated: 2023/11/06 01:21:01 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test_stephane.h"

void	atoi_test(char *str, int fd)
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
		log_test_str(str, fd);
		log_result_int(result_ref, result_user, fd);
	}
}

void	atoi_tests(void)
{
	int	fd;

	fd = open_file_msgs_error();

	print_fct_name("ft_atoi");

	atoi_test("-2147483648", fd);
	atoi_test("0", fd);
	atoi_test("2147483647", fd);
	atoi_test("-21474a83648", fd);
	atoi_test("  \f \n \r \t \v   -2147483648", fd);
	atoi_test("  fd -2147483648", fd);
	atoi_test("-21474836480000", fd);
	atoi_test("999999999999999", fd);

	printf("\n");

	print_message_error(fd);

	close(fd);
}
