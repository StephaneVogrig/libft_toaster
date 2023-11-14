/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 01:42:18 by svogrig           #+#    #+#             */
/*   Updated: 2023/11/14 11:55:08 by svogrig          ###   ########.fr       */
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

void	log_test_str(char *str, int fd)
{
	log_tested_title(fd);
	ft_putstr_fd(str, fd);
	ft_putstr_fd("\"", fd);
}

void	log_test_ptr(void *ptr, int fd)
{
	log_tested_title(fd);
	ft_putptr_fd(ptr, fd);
}

void	log_test_int(int n, int fd)
{
	log_tested_title(fd);
	ft_putnbr_fd(n, fd);
}

void	log_test_int_int(int n1, int n2, int fd)
{
	log_test_int(n1, fd);
	ft_putstr_fd(", ", fd);
	ft_putnbr_fd(n2, fd);
}

void	log_test_str_str(char *s1, char *s2, int fd)
{
	log_test_str(s1, fd);
	ft_putstr_fd(", \"", fd);
	ft_putstr_fd(s2, fd);
	ft_putstr_fd("\"", fd);
}

void	log_test_str_int(char *str, int n, int fd)
{
	log_test_str(str, fd);
	ft_putstr_fd(", ", fd);
	ft_putnbr_fd(n, fd);
}

void	log_test_str_int_int(char *str, int n1, int n2, int fd)
{
	log_test_str_int(str, n1, fd);
	ft_putstr_fd(", ", fd);
	ft_putnbr_fd(n2, fd);
}

void	log_test_str_str_int(char *str1, char *str2, int n, int fd)
{
	log_test_str(str1, fd);
	ft_putstr_fd(", \"", fd);
	ft_putstr_fd(str2, fd);
	ft_putstr_fd("\", ", fd);
	ft_putnbr_fd(n, fd);
}

void	log_result_str(char *expected, char *user, int fd)
{
	ft_putstr_fd(" : expected ", fd);
	ft_putstr_fd(expected, fd);
	ft_putstr_fd(", obtained ", fd);
	ft_putstr_fd(user, fd);
	ft_putstr_fd("\n", fd);
}
void	log_result_int(int expected, int user, int fd)
{
	ft_putstr_fd(" : expected ", fd);
	ft_putnbr_fd(expected, fd);
	ft_putstr_fd(", obtained ", fd);
	ft_putnbr_fd(user, fd);
	ft_putstr_fd("\n", fd);
}

void	log_result_int_str(int int_expected, char *str_expected, int int_user, char *str_user, int fd)
{
	ft_putstr_fd(" : expected ", fd);
	ft_putnbr_fd(int_expected, fd);
	ft_putstr_fd(", \"", fd);
	ft_putstr_fd(str_expected, fd);
	ft_putstr_fd("\", obtained ", fd);
	ft_putnbr_fd(int_user, fd);
	ft_putstr_fd(", \"", fd);
	ft_putstr_fd(str_user, fd);
	ft_putstr_fd("\"\n", fd);
}

void	log_result_str_str(char *str_expected, void *str_user, int fd)
{
	ft_putstr_fd(" : expected ", fd);
	ft_putstr_fd(str_expected, fd);
	ft_putstr_fd(", obtained ", fd);
	ft_putstr_fd(str_user, fd);
	ft_putstr_fd("\n", fd);
}

void	log_result_str_ptr(char *str_expected, void *ptr_user, int fd)
{
	ft_putstr_fd(" : expected ", fd);
	ft_putstr_fd(str_expected, fd);
	ft_putstr_fd(", obtained ", fd);
	ft_putptr_fd(ptr_user, fd);
	ft_putstr_fd("\n", fd);
}

void	log_result_ptr_ptr(void *ptr_expected, void *ptr_user, int fd)
{
	ft_putstr_fd(" : expected ", fd);
	ft_putptr_fd(ptr_expected, fd);
	ft_putstr_fd(", obtained ", fd);
	ft_putptr_fd(ptr_user, fd);
	ft_putstr_fd("\n", fd);
}
