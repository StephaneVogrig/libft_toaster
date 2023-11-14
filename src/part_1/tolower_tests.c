/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tolower_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:10:20 by svogrig           #+#    #+#             */
/*   Updated: 2023/11/14 19:10:34 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test_stephane.h"

void	tolower_tests(void)
{
	int	fd;
	int	(*ft_user)(int);
	int	(*ft_ref)(int);

	ft_user = ft_tolower;
	ft_ref = tolower;

	fd = open_file_msgs_error();


	print_fct_name("ft_tolower");

	//gen_test_int_ref_int_to_int(ft_ref, ft_user,-128, -2, fd);
	gen_test_int_ref_int_to_int(ft_ref, ft_user,-1, 'A' - 1, fd);
	gen_test_int_ref_int_to_int(ft_ref, ft_user,'A', 'Z', fd);
	gen_test_int_ref_int_to_int(ft_ref, ft_user,'Z' - 1, 127,fd);
	gen_test_int_ref_int_to_int(ft_ref, ft_user,128, 255, fd);

	printf("\n");

	print_message_error(fd);

	close(fd);
}