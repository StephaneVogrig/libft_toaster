/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:07:48 by svogrig           #+#    #+#             */
/*   Updated: 2023/11/07 17:35:11 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft_test_stephane.h"
/*
static void	test(char *str1, char *str2, int n, int fd)
{
	int		tested;
	int		ref;
	int		error;
	char	dest_tested[30];
	char	dest_ref[30];
	int		len_str1;

	len_str1 = strlen(str1);
	ft_bzero(dest_tested, 30);
	memcpy(dest_tested, str1, len_str1);
	ft_bzero(dest_ref, 30);
	memcpy(dest_ref, str1, len_str1);

	tested = ft_strlcat(dest_tested, str2, n);
	ref = strlcat(dest_ref, str2, n);

	error =  tested != ref;
	error += strcmp(dest_ref, dest_tested);

	print_succes(error == 0);
	if(error)
	{
		log_test_str_str_int(str1, str2, n, fd);
		//log_expected_int_str(ft_join(ref, dest_ref, fd);
		//log_obtain_int_str(tested, dest_tested, fd)
	}
}
*/
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
	size = 0;
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

size_t	strlat(char *dst, const char *src, size_t size);

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
	test_with_all_size("a", "", fd);
	test_with_all_size("123456", "", fd);
	test_with_all_size("123456", "abc", fd);
	test_with_all_size("123456", "abcdef", fd);
	test_with_all_size("123456", "abcdefghi", fd);
	//test_with_all_size("123456", "", fd);
/*
	test("123456", "", 0, fd);
	test("123456", "", 3, fd);
	test("123456", "", 6, fd);
	test("123456", "", 10, fd);
	test("", "123456", 0, fd);
	test("", "123456", 3, fd);
	test("", "123456", 6, fd);
	test("", "123456", 10, fd);

	test("abcd", "123456", 0, fd);
	test("abcd", "123456", 3, fd);
	test("abcd", "123456", 6, fd);
	test("abcd", "123456", 10, fd);
*/
	// test libftTester
/*
	strlcat_test("B", "AAAAAAAAA", 0, fd);
	strlcat_test("B", "AAAAAAAAA", 1, fd);
	strlcat_test("BBBB", "AAAAAAAAA", 3, fd);
	strlcat_test("BBBB", "AAAAAAAAA", 6, fd);
	strlcat_test("CCCCC", "AAAAAAAAA", -1, fd);
	strlcat_test("CCCCCCCCCCCCCCC", "AAAAAAAAA", 17, fd);
	
	strlcat_test("", "123", 0, fd);
	strlcat_test("", "123", 1, fd);
	strlcat_test("", "123", 2, fd);
	strlcat_test("", "123", 3, fd);
	strlcat_test("", "123", 4, fd);
*/
	printf("\n");

	print_message_error(fd);

	close(fd);
}