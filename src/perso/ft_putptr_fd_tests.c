/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd_tests.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:09:35 by svogrig           #+#    #+#             */
/*   Updated: 2023/11/06 17:29:28 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft_test_stephane.h"

static void	test(unsigned long long ull, char *expected, int file_msg_error)
{
	char	*user;
	int		error;
	int		file_result;
	void	*ptr;
	
	ptr = (void *)ull;
	file_result = open_file_test_result();

	ft_putptr_fd(ptr, file_result);

	user = load_file_content(file_result);

	error = strcmp(user, expected);

	print_succes(error == 0);

	if (error)
	{
		log_test_ptr(ptr, file_msg_error);
		log_result_str_str(expected, user, file_msg_error);
	}

	free(user);
	close(file_result);
}

void	ft_putptr_fd_tests(void)
{
	int		fd_mesg_error;

	fd_mesg_error = open_file_msgs_error();

	print_fct_name("ft_putptr_fd");

	test(0xfULL, "0xf", fd_mesg_error);
	test(0xffULL, "0xff", fd_mesg_error);
	test(0xffffffffffffffffULL, "0xffffffffffffffff", fd_mesg_error);
	test(0xf000000000000000ULL, "0xf000000000000000", fd_mesg_error);
	test(0x0ULL, "NULL", fd_mesg_error);


	printf("\n");

	print_message_error(fd_mesg_error);

	close(fd_mesg_error);
}
