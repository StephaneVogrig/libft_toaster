/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substr_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:22:58 by svogrig           #+#    #+#             */
/*   Updated: 2023/11/06 18:43:36 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
char	*ft_substr(char const *s, unsigned int start, size_t len);

- Retourne une sous chaine de s aui commence a l'index start et a une longueur
  maximum de len.
- La chaine est alloue avec malloc.
- Renvoi NULL en cas d'echec de l'allocation.
*/

#include "libft_test_stephane.h"

static void	test(char *s, unsigned int start, size_t len, char *expected, int file_msg_error)
{
	char 	*str_user;
	int		error;

	str_user = ft_substr(s, start, len);
	if (!str_user)
		return ;
	error = strcmp(str_user, expected);
	print_succes(error == 0);
	if (error)
	{
		log_test_str_int_int(s, start, len, file_msg_error);
		log_result_str_str(expected, str_user, file_msg_error);
	}

}
void	substr_tests(void)
{
	int	file_msg_error;

	file_msg_error = open_file_msgs_error();

	print_fct_name("ft_substr");
	
	test("12345ABCDEabcde12345", 0, 5, "12345", file_msg_error);
	test("12345ABCDEabcde12345", 5, 0, "", file_msg_error);
	test("12345ABCDEabcde12345", 5, 5, "ABCDE", file_msg_error);
	test("12345ABCDEabcde12345", 5, 10, "ABCDEabcde", file_msg_error);
	test("12345ABCDEabcde12345", 5, 30, "ABCDEabcde12345", file_msg_error);

	printf("\n");

	print_message_error(file_msg_error);

	close(file_msg_error);
}