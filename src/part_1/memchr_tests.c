/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:04:27 by svogrig           #+#    #+#             */
/*   Updated: 2023/11/06 01:20:26 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test_stephane.h"

void	memchr_tests(void)
{
	int	fd;

	fd = open_file_msgs_error();


	print_fct_name("ft_memchr");

	printf("\n");

	print_message_error(fd);

	close(fd);
}