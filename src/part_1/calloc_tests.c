/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:11:19 by svogrig           #+#    #+#             */
/*   Updated: 2023/11/06 22:02:13 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test_stephane.h"

static void	test(size_t nmemb, size_t size, int fd_mesg_error)
{
	int		error;
	char	*ptr_user;
	char	*ptr_expected;

	error = 0;
	ptr_user = ft_calloc(nmemb, size);
	ptr_expected = calloc(nmemb, size);
	if(ptr_user == NULL && ptr_expected != NULL)
	{
		free(ptr_expected);
		error = 1;
	}
	if(ptr_user != NULL && ptr_expected == NULL)
	{
		free(ptr_user);
		error = 1;
	}
	print_succes(error == 0);
	if (error)
	{
		log_test_int_int(nmemb, size, fd_mesg_error);
		log_result_ptr_ptr(ptr_expected, ptr_user, fd_mesg_error);
	}
}

void	calloc_tests(void)
{
	int	file_msg_error;
	//char	ref[] = {0, 0, 0, 0};

	file_msg_error = open_file_msgs_error();

	print_fct_name("ft_calloc");

	//test(2, 2, ref, file_msg_error);
	test(0, 0, file_msg_error);
	test(0, 5, file_msg_error);
	test(5, 0, file_msg_error);
	test(-5, -5, file_msg_error);
	test(0, -5, file_msg_error);
	test(-5, 0, file_msg_error);

	printf("\n");

	print_message_error(file_msg_error);

	close(file_msg_error);
}