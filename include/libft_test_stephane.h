/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_test_stephane.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:50:56 by svogrig           #+#    #+#             */
/*   Updated: 2023/11/07 21:17:44 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_TEST_STEPHANE_H
# define LIBFT_TEST_STEPHANE_H

# include "libft.h"
# include <stdio.h>
# include <stdbool.h>
# include <ctype.h>
# include <string.h>
# include <bsd/string.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <time.h>
# include <stdarg.h>

// couleurs shell : https://stackoverflow.com/questions/4842424/list-of-ansi-color-escape-sequences
# define RESET "\033[0m"
# define BLCK "\033[30m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define WHITE "\033[37m"
# define BRIGHTBLACK "\033[90m"
# define BRIGHTRED "\033[91m"
# define BRIGHTGREEN "\033[92m"
# define BRIGHTYELLOW "\033[93m"
# define BRIGHTBLUE "\033[94m"
# define BRIGHTMAGENTA "\033[95m"
# define BRIGHTCYAN "\033[96m"
# define BRIGHTWHITE "\033[97m"

# define SUCCES 1
# define FAILED 0

typedef struct s_str_list
{
	char	*str;
	t_list	*next;
}	str_list;

void	print_succes(bool succes);
void	print_result_char_int_int(char passed, int expected, int obtained);
void	print_result_str_int_int(char *passed, int expected, int obtained);
void    print_fct_name(const char* name);
void	print_message_error(int fd);

void	log_result_str(char *expected, char *user, int fd);
void	log_result_int(int expected, int user, int fd);
void	log_result_int_str(int int_expected, char *str_expected, int int_user, char *str_user, int fd);
void	log_result_str_str(char *str_expected, void *str_user, int fd);
void	log_result_str_ptr(char *str_expected, void *ptr_user, int fd);
void	log_result_ptr_ptr(void *ptr_expected, void *ptr_user, int fd);

void	log_test_str(char *str, int fd);
void	log_test_str_str(char *s1, char *s2, int fd);
void	log_test_int(int n, int fd);
void	log_test_int_int(int n1, int n2, int fd);
void	log_test_ptr(void *ptr, int fd);
void	log_test_str_int(char *str, int n, int fd);
void	log_test_str_str_int(char *str1, char *str2, int n, int fd);
void	log_test_str_int_int(char *str, int n1, int n2, int fd);

int		open_file_test_result(void);
int		open_file_msgs_error(void);
char	*load_file_content(int fd);

void    gen_test_int_ref_int_to_int(int (*ft_foo)(int), int (*foo)(int), int start,int end, int fd);
void	generic_test_putstr(void (*ft_user)(char *, int), char* str_test, char *expected, int file_msg_error);

size_t	ft_putptr_fd(void *ptr, int fd);

void	isalpha_tests(void);
void	isdigit_tests(void);
void	isalnum_tests(void);
void	isascii_tests(void);
void	isprint_tests(void);
void	strlen_tests(void);
void	memset_tests(void);
void	bzero_tests(void);
void	memcpy_tests(void);
void	memmove_tests(void);
void	strlcpy_tests(void);
void	strlcat_tests(void);
void	toupper_tests(void);
void	tolower_tests(void);
void	strchr_tests(void);
void	strrchr_tests(void);
void	strncmp_tests(void);
void	memchr_tests(void);
void	memcmp_tests(void);
void	strnstr_tests(void);
void	atoi_tests(void);
void	calloc_tests(void);
void	strdup_tests(void);

void	substr_tests(void);
void	strjoin_tests(void);
void	strtrim_tests(void);
void	split_tests(void);
void	itoa_tests(void);
void	strmapi_tests(void);
void	striteri_tests(void);
void	putchar_fd_tests(void);
void	putstr_fd_tests(void);
void	putendl_fd_tests(void);
void	putnbr_fd_tests(void);

void	lstnew_tests(void);
void	lstadd_front_tests(void);
void	lstsize_tests(void);
void	lstlast_tests(void);
void	lstadd_back_tests(void);
void	lstdelone_tests(void);
void	lstclear_tests(void);
void	lstiter_tests(void);
void	lstmap_tests(void);

void	ft_putptr_fd_tests(void);

#endif
