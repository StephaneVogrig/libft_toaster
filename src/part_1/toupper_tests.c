/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toupper_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:06:22 by svogrig           #+#    #+#             */
/*   Updated: 2023/11/06 02:37:25 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test_stephane.h"
/*
void	toupper_test(int start, int end, int fd)
{
	int	errors;
	int	ref;
	int	user;
	int	i;

	errors = 0;
	i = start;
	while (i <= end)
	{
		ref = toupper(i);
		user = ft_toupper(i);
	
		if (user != ref)
		{
			errors++;
		}
		++i;
	}
	print_succes(errors);		
}
*/
void	toupper_tests(void)
{
	int	fd;
	int	(*ft_user)(int);
	int	(*ft_ref)(int);

	ft_user = ft_toupper;
	ft_ref = toupper;

	fd = open_file_msgs_error();

	print_fct_name("ft_toupper");

	gen_test_int_ref_int_to_int(ft_ref, ft_user,-128, -2, fd);
	gen_test_int_ref_int_to_int(ft_ref, ft_user,-1, 'A' - 1, fd);
	gen_test_int_ref_int_to_int(ft_ref, ft_user,'A', 'Z', fd);
	gen_test_int_ref_int_to_int(ft_ref, ft_user,'Z' - 1, 127,fd);
	gen_test_int_ref_int_to_int(ft_ref, ft_user,128, 255, fd);

	printf("\n");

	print_message_error(fd);

	close(fd);
}