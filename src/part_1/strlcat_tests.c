/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:07:48 by svogrig           #+#    #+#             */
/*   Updated: 2023/11/07 22:30:25 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft_test_stephane.h"

static void test_with_all_size(char *dst, char *src, int fd)
{
	int 	len_dst;
	int 	len_max;
	char	dest_tested[30];
	char	dest_ref[30];
	int		result;
	int		result_ref;
	int		error;
	int		sub_error;
	int		size;

	len_dst = strlen(dst);
	len_max = len_dst + strlen(src) + 3; // test des size plus grande que dst + src + '\0'
	error = 0;
	size = -1;
	while (size < len_max)
	{
		ft_bzero(dest_tested, 30);
		memcpy(dest_tested, dst, len_dst);
		ft_bzero(dest_ref, 30);
		memcpy(dest_ref, dst, len_dst);

		result = ft_strlcat(dest_tested, src, size);
		result_ref = strlcat(dest_ref, src, size);

		sub_error =  result != result_ref;
		sub_error += strcmp(dest_ref, dest_tested);
		size++;
		if (sub_error)
		{
			dprintf(fd, "%s", YELLOW);
			dprintf(fd, "tested value : ");
			dprintf(fd, WHITE);
			dprintf(fd, "\"%s\" \"%s\" %d - ", dst, src, size);
			dprintf(fd, "%s", YELLOW);
			dprintf(fd, "expected : ");
			dprintf(fd, "%s", GREEN);
			dprintf(fd, "%d \"%s\"", result_ref, dest_ref);
			dprintf(fd, "%s", YELLOW);
			dprintf(fd, " - obtained : ");
			dprintf(fd, "%s", RED);
			dprintf(fd, "%d \"%s\"", result, dest_tested);
			dprintf(fd, "\n%s", RESET);
		}
		error += sub_error;
	}
	print_succes(error == 0);
}
/*
#include <string.h>

size_t	strlcat(char *dst, const char *src, size_t size);

Concatene la chaine src dans la chaine dest mais :
- la taille finale sera limite a size - 1.
- le caractere '\0' est ajoute a la fin sauf si size = 0
- size inclu le caractere ajoute '\0'.
- Ne fonctionne qu'avec des chaines "C", src doit etre termine par '\0'.
- Renvoi la taille totale de la chaine qui aurait ete cree sans limite de size,
  soit la longueurs src.
*/

void	strlcat_tests(void)
{
	int		fd;

	fd = open_file_msgs_error();

	print_fct_name("ft_strlcat");

	test_with_all_size("", "", fd);
	test_with_all_size("", "abc", fd);
	test_with_all_size("a", "", fd);
	test_with_all_size("123456", "", fd);
	test_with_all_size("123456", "abc", fd);
	test_with_all_size("123456", "abcdef", fd);
	test_with_all_size("123456", "abcdefghi", fd);

	printf("\n");

	print_message_error(fd);

	close(fd);
}