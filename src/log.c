/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 01:42:18 by svogrig           #+#    #+#             */
/*   Updated: 2023/11/15 21:50:48 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test_stephane.h"

void	log_tested_title(int fd)
{
	write(fd, "tested value = ", 15);
}

void	log_expected_title(int fd)
{
	write(fd, " : expected ", 12);
}

void	log_obtained_title(int fd)
{
	write(fd, " : obtained ", 12);
}

void	log_separator(int fd)
{
	write(fd, ",", 1);
}

void	log_endline(int fd)
{
	write(fd, "\n", 1);
}

void	log_test_str(char *str, int fd)
{
	log_tested_title(fd);
	put_str(str, fd);
}

void	log_test_ptr(void *ptr, int fd)
{
	log_tested_title(fd);
	put_ptr(ptr, fd);
}

void	log_test_int(int n, int fd)
{
	log_tested_title(fd);
	put_int(n, fd);
}

void	log_test_int_int(int n1, int n2, int fd)
{
	log_test_int(n1, fd);
	log_separator(fd);
	put_int(n2, fd);
}

void	log_test_str_str(char *s1, char *s2, int fd)
{
	log_test_str(s1, fd);
	put_str(s2, fd);
}

void	log_test_str_int(char *str, int n, int fd)
{
	log_test_str(str, fd);
	log_separator(fd);
	put_int(n, fd);
}

void	log_test_str_int_int(char *str, int n1, int n2, int fd)
{
	log_test_str_int(str, n1, fd);
	log_separator(fd);
	put_int(n2, fd);
}

void	log_test_str_str_int(char *str1, char *str2, int n, int fd)
{
	log_test_str(str1, fd);
	put_str(str2, fd);
	put_int(n, fd);
}

void	log_result_str(char *expected, char *user, int fd)
{
	log_expected_title(fd);
	put_str(expected, fd);
	log_obtained_title(fd);
	put_str(user, fd);
	log_endline(fd);
}
void	log_result_int(int expected, int user, int fd)
{
	log_expected_title(fd);
	put_int(expected, fd);
	log_obtained_title(fd);
	put_int(user, fd);
	log_endline(fd);
}

void	log_result_int_str(int int_expected, char *str_expected, int int_user, char *str_user, int fd)
{
	log_expected_title(fd);
	put_int(int_expected, fd);
	log_separator(fd);
	put_str(str_expected, fd);
	log_obtained_title(fd);
	put_int(int_user, fd);
	log_separator(fd);
	put_str(str_user, fd);
	log_endline(fd);
}

void	log_result_str_str(char *str_expected, void *str_user, int fd)
{
	log_expected_title(fd);
	put_str(str_expected, fd);
	log_obtained_title(fd);
	put_str(str_user, fd);
	log_endline(fd);
}

void	log_result_str_ptr(char *str_expected, void *ptr_user, int fd)
{
	log_expected_title(fd);
	put_str(str_expected, fd);
	log_obtained_title(fd);
	put_ptr(ptr_user, fd);
	log_endline(fd);
}

void	log_result_ptr_ptr(void *ptr_expected, void *ptr_user, int fd)
{
	log_expected_title(fd);
	put_ptr(ptr_expected, fd);
	log_obtained_title(fd);
	put_ptr(ptr_user, fd);
	log_endline(fd);
}
