/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putchar_fd_tests.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:19:44 by svogrig           #+#    #+#             */
/*   Updated: 2023/11/06 03:33:40 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test_stephane.h"

void	ft_putchar_fd_test(char c, int file_msg_error)
{
	char		*user;
	int			error;
	int		file_result;
	char	expected[2];

	expected[0] = c;
	expected[1] = '\0';

	file_result = open_file_test_result();

	ft_putchar_fd(c, file_result);

	user = load_file_content(file_result);

	error = strcmp(user, expected);

	print_succes(error == 0);

	if (error)
	{
		log_test_str(expected, file_msg_error);
		log_result_str(expected, user, file_msg_error);
	}

	free(user);
	close(file_result);
}

void	putchar_fd_tests(void)
{
	int	file_msg_error;

	file_msg_error = open_file_msgs_error();

	print_fct_name("ft_putchar_fd");
	
	ft_putchar_fd_test('a', file_msg_error);

	printf("\n");

	print_message_error(file_msg_error);

	close(file_msg_error);
}