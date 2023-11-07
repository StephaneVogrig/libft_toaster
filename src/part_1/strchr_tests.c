/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*  	tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:06:51 by svogrig           #+#    #+#             */
/*   Updated: 2023/11/06 08:04:01 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test_stephane.h"

static void	test(char *str, int c, int fd_mesg_error)
{
	char	*user;
	char	*ref;
	int		error;

	user = ft_strchr(str, c);
	ref = strchr(str, c);

	error = user != ref;
	
	print_succes(error == 0);
	if (error)
	{
		log_test_str_int(str, c, fd_mesg_error);
		log_result_str(ref, user, fd_mesg_error);
	}
}

/* 
 char *ft_strchr(char *s, int c)
----------------------------------
- Retourne un pointeur sur la premiere occurence du caractere c
  dans la chaine s.
- Retourne NULL si le caractere c n'est pas trouve.
- Le caractere null de terminaison est considere faisant partie de la chaine.
  Ainsi si c = '\0' un pointeur sur le caractere null de fin de chaine est
  retourne.
- Ici caractere signifie "byte". Cette fonction ne fonctionne pas avec des
  charactere multibyte.
*/

void	strchr_tests(void)
{
	int	fd_mesg_error;

	fd_mesg_error = open_file_msgs_error();
	
	test("", 'n', fd_mesg_error);
	test("Bonjour", 'n', fd_mesg_error);
	test("aaaaaaa", 'n', fd_mesg_error);
	test("aaaaaaa", '\0', fd_mesg_error);
	test("1aaaaaa", '1', fd_mesg_error);
	test("1aaaaa2", '2', fd_mesg_error);
	test("tripouille", 't' + 256, fd_mesg_error);

	print_fct_name("ft_strchr");

	printf("\n");

	print_message_error(fd_mesg_error);

	close(fd_mesg_error);
}