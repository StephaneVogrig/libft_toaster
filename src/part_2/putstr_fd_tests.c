/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr_fd_tests.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:21:07 by svogrig           #+#    #+#             */
/*   Updated: 2023/11/06 04:14:17 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test_stephane.h"

void	putstr_fd_tests(void)
{
	int		file_msg_error;
	void	(*ft_user)(char *str, int fd_mesg_error);

	ft_user = ft_putstr_fd;

	file_msg_error = open_file_msgs_error();

	generic_test_putstr(ft_user, "test", "test", file_msg_error);
	generic_test_putstr(ft_user, "", "", file_msg_error);

	print_fct_name("ft_putstr_fd");

	printf("\n");

	print_message_error(file_msg_error);

	close(file_msg_error);
}