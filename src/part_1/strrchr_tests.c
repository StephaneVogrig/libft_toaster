/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:09:40 by svogrig           #+#    #+#             */
/*   Updated: 2023/11/07 01:34:16 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test_stephane.h"

static void	test(char *str, int c, int fd_mesg_error)
{
	char	*user;
	char	*ref;
	int		error;

	user = ft_strrchr(str, c);
	ref = strrchr(str, c);

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
- Retourne un pointeur sur la derniere occurence du caractere c
  dans la chaine s.
- Retourne NULL si le caractere c n'est pas trouve.
- Le caractere null de terminaison est considere faisant partie de la chaine.
  Ainsi si c = '\0' un pointeur sur le caractere null de fin de chaine est
  retourne.
- Ici caractere signifie "byte". Cette fonction ne fonctionne pas avec des
  charactere multibyte.
*/

void	strrchr_tests(void)
{
	int	fd_mesg_error;

	fd_mesg_error = open_file_msgs_error();

	print_fct_name("ft_strrchr");
	
	test("", 'n', fd_mesg_error);
	test("Bonjour", 'n', fd_mesg_error);
	test("aaaaaaa", 'n', fd_mesg_error);
	test("aaaaaaa", '\0', fd_mesg_error);
	test("", '\0', fd_mesg_error);
	test("1aaaaaa", '1', fd_mesg_error);
	test("1aaaaa2", '2', fd_mesg_error);
	test("tripouille", 't' + 256, fd_mesg_error);
	test("tripouille", 'e' , fd_mesg_error);
	printf("\n");

	print_message_error(fd_mesg_error);

	close(fd_mesg_error);
}