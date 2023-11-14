/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:22:01 by svogrig           #+#    #+#             */
/*   Updated: 2023/11/14 22:27:00 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test_stephane.h"

static void	test(char const *s1, char const *s2, char const *s3, int fd)
{
	char	*res_user;
	int		error;
	
	res_user = ft_strjoin(s1, s2);
	error = strcmp(s3, res_user);
	print_succes(error == 0);
	if (error)
	{
		log_tested_title(fd);
		dprintf(fd, "%s, %s\n", s1, s2);
		log_expected_title(fd);
		dprintf(fd, "%s\n", s3);
		log_obtained_title(fd);
		dprintf(fd, "%s\n", res_user);
	}
	free(res_user);
	
}

void	strjoin_tests(void)
{
	int	fd;

	fd = open_file_msgs_error();

	print_fct_name("ft_strjoin");

	test("Bonjour", " le monde!", "Bonjour le monde!", fd);
	test("Bonjour", "", "Bonjour", fd);
	test("", "", "", fd);
	test("", "Bonjour", "Bonjour", fd);

	printf("\n");

	print_message_error(fd);

	close(fd);
}