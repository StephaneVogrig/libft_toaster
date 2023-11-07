/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcpy_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:08:15 by svogrig           #+#    #+#             */
/*   Updated: 2023/11/07 15:33:21 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test_stephane.h"

void	strlcpy_test(char *src, size_t size, int file_msg_error)
{
	char	dst[16];
	char	dst_user[16];
	char	dst_ref[16];
	size_t	result_user;
	size_t	result_ref;
	int		error;

	bzero(dst_user, 16);
	memset(dst_user, 'a', 10);
	result_user = ft_strlcpy(dst_user, (char *)src, size);

	memset(dst_ref, 0, 16);
	memset(dst_ref, 'a', 10);
	result_ref = strlcpy(dst_ref, (char *)src, size);

	error = result_user != result_ref;
	error += strcmp(dst_user, dst_ref);
	
	print_succes(error == 0);
	if (error)
	{
		memset(dst, 0, 16);
		memset(dst, 'a', 10);
		log_test_str_str_int(dst, src, size, file_msg_error);
		log_result_int_str(result_ref, dst_ref, result_user, dst_user, file_msg_error);
	}
}
/*
#include <string.h>

size_t	strlcpy(char *dst, const char *src, size_t size);

Copie la chaine src dans la chaine dest mais :
- la taille finale sera limite a size - 1.
- le caractere '\0' est a la fin ajoute sauf si size = 0
- size inclu le caractere ajoute '\0'.
- Ne fonctionne qu'avec des chaines "C", src doit etre termine par '\0'.
- Renvoi la taille totale de la chaine qui aurait ete cree sans limite de size,
  soit la longueurs dst + src.
*/
void	strlcpy_tests(void)
{
	int	file_msg_error;

	file_msg_error = open_file_msgs_error();

	print_fct_name("ft_strlcpy");

	strlcpy_test("", 0,file_msg_error);
	strlcpy_test("", 5,file_msg_error);
	strlcpy_test("12345", 0,file_msg_error);
	strlcpy_test("12345", 2,file_msg_error);
	strlcpy_test("12345", 5,file_msg_error);
	strlcpy_test("12345", 7,file_msg_error);

	printf("\n");

	print_message_error(file_msg_error);

	close(file_msg_error);
}