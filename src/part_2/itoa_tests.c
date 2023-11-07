/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:19:23 by svogrig           #+#    #+#             */
/*   Updated: 2023/11/06 04:35:02 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test_stephane.h"

void	itoa_test(int nbr, char *expected, int file_msg_error)
{
	char	*user;
	int		error;

	user = ft_itoa(nbr);
	if (!user)
		return ;
	error = strcmp(user, expected);
	
	print_succes(error == 0);

	if (error)
	{
		log_test_int(nbr, file_msg_error);
		log_result_str(expected, user, file_msg_error);
	}

	free(user);
	
}

void	itoa_tests(void)
{
	int	file_msg_error;

	file_msg_error = open_file_msgs_error();

	print_fct_name("ft_itoa");
	itoa_test(0, "0", file_msg_error);
	itoa_test(123, "123", file_msg_error);
	itoa_test(-123, "-123", file_msg_error);
	itoa_test(-2147483648, "-2147483648", file_msg_error);
	printf("\n");

	print_message_error(file_msg_error);

	close(file_msg_error);
}