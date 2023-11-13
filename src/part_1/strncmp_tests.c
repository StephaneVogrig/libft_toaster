/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmp_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephane <stephane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:08:49 by svogrig           #+#    #+#             */
/*   Updated: 2023/11/11 12:39:51 by stephane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test_stephane.h"

int	strncmp_subtest(const char *s1, const char *s2, int n, int fd)
{
	int		error;
	int		result_user;
	int		result_expected;

	result_user = ft_strncmp(s1, s2, n);
	result_expected = strncmp(s1, s2, n);

	error = result_user != result_expected;
	if (error)
	{
		log_test_str_str_int((char *)s1, (char *)s2, n, fd);
		log_result_int(result_expected, result_user, fd);
	}
	return (error);
}

void	strncmp_test(const char *s1, const char *s2, int fd)
{
	int 	nbr_error;
	size_t	len1;
	size_t	len2;

	nbr_error = 0;
	len1 = strlen(s1);
	len2 = strlen(s2);

	nbr_error += strncmp_subtest(s1, s2, 0, fd);
	nbr_error += strncmp_subtest(s1, s2, len1 - 1, fd);
	nbr_error += strncmp_subtest(s1, s2, len1, fd);
	nbr_error += strncmp_subtest(s1, s2, len1 + 1, fd);
	nbr_error += strncmp_subtest(s1, s2, len2 - 1, fd);
	nbr_error += strncmp_subtest(s1, s2, len2, fd);
	nbr_error += strncmp_subtest(s1, s2, len2 + 1, fd);
	
	print_succes(nbr_error == 0);	
}

void	strncmp_tests(void)
{
	int	fd;

	fd = open_file_msgs_error();

	print_fct_name("ft_strncmp");

	strncmp_test("password", "password", fd);
	strncmp_test("password", "pass", fd);
	strncmp_test("pass", "password", fd);
	strncmp_test("", "", fd);
	strncmp_test("password", "", fd);
	strncmp_test("", "password", fd);
	strncmp_test("abcdef", "ghijk", fd);
	strncmp_test("abcdef", "ghijklmnopq", fd);
	strncmp_test("test\200", "test\0", fd);

	printf("\n");

	print_message_error(fd);

	close(fd);
}