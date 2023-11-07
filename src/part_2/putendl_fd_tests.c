/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putendl_fd_tests.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:20:25 by svogrig           #+#    #+#             */
/*   Updated: 2023/11/06 04:09:35 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test_stephane.h"

void	putendl_fd_tests(void)
{
	int	file_msg_error;
	void	(*ft_user)(char *str, int fd_mesg_error);

	ft_user = ft_putendl_fd;

	file_msg_error = open_file_msgs_error();

	print_fct_name("ft_putendl_fd");

	generic_test_putstr(ft_user, "test", "test\n", file_msg_error);
	generic_test_putstr(ft_user, "", "\n", file_msg_error);

	printf("\n");

	print_message_error(file_msg_error);

	close(file_msg_error);
}