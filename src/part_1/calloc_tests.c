/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephane <stephane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:11:19 by svogrig           #+#    #+#             */
/*   Updated: 2023/11/11 20:56:58 by stephane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdlib.h>

void *calloc(size_t nmemb, size_t size);

La fonction calloc() alloue de la mémoire
- pour un tableau de nmemb éléments de size octets chacun
- renvoie un pointeur sur la mémoire allouée.
- La mémoire est mise à zéro.
- Si nmemb ou size vaut 0, calloc() renvoie soit NULL,
  soit un pointeur unique qui peut être passé avec succès à free().
- Si la multiplication de nmemb et de size entraîne un dépassement d'int
  calloc() renvoie une erreur.

En revanche, un dépassement d'entier ne serait pas détecté
dans l'appel suivant à malloc(), ce qui aurait pour conséquence
d'allouer un bloc de mémoire de taille incorrecte:

           malloc(nmemb * size)

*/
#include "libft_test_stephane.h"

static void	test(size_t nmemb, size_t size, int fd_mesg_error)
{
	int		error;
	char	*ptr_user;
	char	*ptr_expected;

	error = 0;
	ptr_user = ft_calloc(nmemb, size);
	ptr_expected = calloc(nmemb, size);
	if(ptr_user == NULL && ptr_expected != NULL)
	{
		error = 1;
	}
	if(ptr_user != NULL && ptr_expected == NULL)
	{
		error = 1;
	}
	print_succes(error == 0);
	if (error)
	{
		log_test_int_int(nmemb, size, fd_mesg_error);
		log_result_ptr_ptr(ptr_expected, ptr_user, fd_mesg_error);
	}
	free(ptr_expected);
	free(ptr_user);
	
}

void	calloc_tests(void)
{
	int	file_msg_error;
	//char	ref[] = {0, 0, 0, 0};

	file_msg_error = open_file_msgs_error();

	print_fct_name("ft_calloc");

	//test(2, 2, ref, file_msg_error);
	test(0, 0, file_msg_error);
	test(0, 5, file_msg_error);
	test(5, 0, file_msg_error);
	test(-5, -5, file_msg_error);
	test(0, -5, file_msg_error);
	test(-5, 0, file_msg_error);

	printf("\n");

	print_message_error(file_msg_error);

	close(file_msg_error);
}