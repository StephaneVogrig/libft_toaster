/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_tests.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:21:32 by svogrig           #+#    #+#             */
/*   Updated: 2023/11/06 01:19:09 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test_stephane.h"

void	split_tests(void)
{
	int	fd;

	fd = open_file_msgs_error();


	print_fct_name("ft_split");

	printf("\n");

	print_message_error(fd);

	close(fd);
}