/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:09:18 by svogrig           #+#    #+#             */
/*   Updated: 2023/11/06 20:48:08 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test_stephane.h"

/*
#include <string.h>

char *	strnstr(const char *big, const char *little, size_t len);

- localise la premiere occurence de la chaine little dans les n premiers
  caractere de la chaine big.
- retourne l'adresse du premier caractere de la premiere occurence de little.
- si little est une chaine vide, big est retournee.
- si little n'est pas trouve, NULL est retourne.
*/

static void	test(char *big, char* little, size_t len, int fd_msg_error)
{
	char	*ptr_user;
	char	*ptr_ref;
	int		error;

	ptr_user = ft_strnstr(big, little, len);
	ptr_ref = strnstr(big, little, len);
	error = ptr_user != ptr_ref;
	print_succes(error == 0);
	if (error)
	{
		log_test_str_str_int(big, little, len, fd_msg_error);
		log_result_str_str(ptr_ref, ptr_user, fd_msg_error);
	}
	
}	

void	strnstr_tests(void)
{
	int	fd_mesg_error;

	fd_mesg_error = open_file_msgs_error();

	print_fct_name("ft_strnstr");

	test("lorem ipsum dolor", "lorem", 15, fd_mesg_error);
	test("", "Bar", 0, fd_mesg_error);
	test("", "", 0, fd_mesg_error);
	test("Bar", "", 0, fd_mesg_error);
	test("", "Bar", 10, fd_mesg_error);
	test("", "", 10, fd_mesg_error);
	test("Bar", "", 10, fd_mesg_error);
	test("Foo Bar Baz", "Bar", 0, fd_mesg_error);
	test("Foo Bar Baz", "Bar", 4, fd_mesg_error);
	test("Foo Bar Baz", "Bar", 5, fd_mesg_error);
	test("Foo Bar Baz", "Bar", 8, fd_mesg_error);
	test("Foo Bar Baz", "Bar", 30, fd_mesg_error);
	test("lorem ipsum dolor sit amet", "dolor", 15, fd_mesg_error);

	printf("\n");

	print_message_error(fd_mesg_error);

	close(fd_mesg_error);
}