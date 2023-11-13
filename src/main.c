/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephane <stephane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 02:36:31 by svogrig           #+#    #+#             */
/*   Updated: 2023/11/12 18:26:43 by stephane         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft_test_stephane.h"

void	print_result_str_int_int(char *passed, int expected, int obtained)
{
	bool	succes;

	succes = expected == obtained;
	print_succes(succes);
	if (!succes)
		printf("passed \"%s\" expected \"%d\" obtained \"%d\"", passed, expected, obtained);
}

void print_result_char_int_int(char passed, int expected, int obtained)
{
	char    str[2];

	str[0] = passed;
	str[1] = '\0';
	print_result_str_int_int(str, expected, obtained);
}

int main(void)
{
	write(1, "--------------------------------------------------------------------------------\n", 81);
	write(1, "part 1\n", 7);
	write(1, "--------------------------------------------------------------------------------\n", 81);
/*
*/	isalpha_tests();
	isdigit_tests();
	isalnum_tests();
	isascii_tests();
    isprint_tests();
    strlen_tests();	
    memset_tests();
    bzero_tests();
	memcpy_tests();
	memmove_tests();
	strlcpy_tests();
	strlcat_tests();
	toupper_tests();
	tolower_tests();
	strchr_tests();
	strrchr_tests();
	strncmp_tests();
	memchr_tests();
	memcmp_tests();
	strnstr_tests();
	atoi_tests();
	calloc_tests();
	strdup_tests();

	write(1, "--------------------------------------------------------------------------------\n", 81);
	write(1, "\n", 1);

	write(1, "part 2\n", 7);
	write(1, "--------------------------------------------------------------------------------\n", 81);

    substr_tests();
	strjoin_tests();
	strtrim_tests();
	split_tests();
	itoa_tests();
	strmapi_tests();
	striteri_tests();
	putchar_fd_tests();
	putstr_fd_tests();
	putendl_fd_tests();
	putnbr_fd_tests();

	write(1, "--------------------------------------------------------------------------------\n", 81);
	ft_putptr_fd_tests();
/*
*/
}
