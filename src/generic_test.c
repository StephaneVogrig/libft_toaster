/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 02:06:08 by svogrig           #+#    #+#             */
/*   Updated: 2023/11/08 01:04:24 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test_stephane.h"

void	gen_test_int_ref_int_to_int(int (*ft_user)(int), int (*fref)(int), int start,int end, int fd)
{
    int	error;
	int	result_ref;
	int	result_user;
	int	i;

	error = 0;
	i = start;
	while (i <= end)
	{
		result_ref = fref(i);
		result_user = ft_user(i);
		if (result_user != result_ref)
		{
			error++;
			log_test_int(i, fd);
			log_result_int(result_ref, result_user, fd);
		}
		++i;
	}
	print_succes(error == 0);
}

void	generic_test_putstr(void (*ft_user)(char *, int), char* str_test, char *expected, int file_msg_error)
{
	char		*user;
	int			error;
	int		file_result;

	file_result = open_file_test_result();

	ft_user(str_test, file_result);

	user = load_file_content(file_result);

	error = strcmp(user, expected);

	print_succes(error == 0);

	if (error)
	{
		log_test_str(expected, file_msg_error);
		log_result_str(expected, user, file_msg_error);
	}

	free(user);
	close(file_result);
}
