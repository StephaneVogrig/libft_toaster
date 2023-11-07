/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcmp_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:05:05 by svogrig           #+#    #+#             */
/*   Updated: 2023/11/06 01:22:24 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test_stephane.h"

void	memcmp_tests(void)
{
	int	fd;

	fd = open_file_msgs_error();

	print_fct_name("ft_memcmp");

	printf("\n");

	print_message_error(fd);

	close(fd);
}