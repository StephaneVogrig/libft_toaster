/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bzero_tests.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:08:21 by svogrig           #+#    #+#             */
/*   Updated: 2023/11/14 11:47:08 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test_stephane.h"

void	bzero_tests(void)
{
	int	fd;

	fd = open_file_msgs_error();


	print_fct_name("ft_bzero");

	
	printf("\n");

	print_message_error(fd);

	close(fd);
}