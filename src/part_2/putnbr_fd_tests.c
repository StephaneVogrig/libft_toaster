/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_fd_tests.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:20:56 by svogrig           #+#    #+#             */
/*   Updated: 2023/11/06 04:23:29 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test_stephane.h"

void	ft_putnbr_fd_test(int nbr, char *expected, int file_msg_error)
{
	char	*user;
	int		error;
	int		file_result;

	file_result = open_file_test_result();

	ft_putnbr_fd(nbr, file_result);

	user = load_file_content(file_result);

	error = strcmp(user, expected);

	print_succes(error == 0);

	if (error)
	{
		log_test_int(nbr, file_msg_error);
		log_result_str(expected, user, file_msg_error);
	}

	free(user);
	close(file_result);
}

void	putnbr_fd_tests(void)
{
	int	file_msg_error;

	file_msg_error = open_file_msgs_error();

	print_fct_name("ft_putnbr_fd");

	ft_putnbr_fd_test(0, "0", file_msg_error);
	ft_putnbr_fd_test(-2147483648, "-2147483648", file_msg_error);
	ft_putnbr_fd_test(2147483647, "2147483647", file_msg_error);
	ft_putnbr_fd_test(123, "123", file_msg_error);
	ft_putnbr_fd_test(-123, "-123", file_msg_error);

	printf("\n");

	print_message_error(file_msg_error);

	close(file_msg_error);
}