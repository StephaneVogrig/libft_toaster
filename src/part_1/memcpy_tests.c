/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephane <stephane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:05:34 by svogrig           #+#    #+#             */
/*   Updated: 2023/11/12 19:06:07 by stephane         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft_test_stephane.h"
#define SIZE_DEST 10
/**/
static void	test(char *dest, const void *src, size_t n, int fd)
{
	char	dest_2[SIZE_DEST];
	char	*dest_user;
	char	*dest_ref;
	size_t	error;
	
	dest_ref = memcpy(dest_2, dest, SIZE_DEST);
	
	dest_user = ft_memcpy(dest, src, n);
	dest_ref = memcpy(dest_2, src, n);
	
	error = memcmp(dest_user, dest_ref, SIZE_DEST);
	
	print_succes(error == 0);
	if (error)
	{
		log_tested_title(fd);
		write(fd, dest, SIZE_DEST);
		dprintf(fd, ", %s, %ld", (char *)src, n);
		log_expected_title(fd);
		log_obtained_title(fd);
	}
	
}


static void	test_null_null_0(int fd)
{
	char	*res_user;
	char	*res_ref;
	char	*dest_user;
	char	*dest_ref;
	char	*src;
	size_t	error;

	dest_user = NULL;
	dest_ref = NULL;
	src = NULL;
	res_user = ft_memcpy(dest_user, src, 0);
	res_ref = memcpy(dest_ref, src, 0);
	error = res_user != res_ref;
	print_succes(error == 0);
	if (error)
	{
		log_tested_title(fd);
		dprintf(fd, "NULL, NULL, O");
		log_expected_title(fd);
		dprintf(fd, "%s", res_ref);
		log_obtained_title(fd);
		dprintf(fd, "%s", res_user);
	}
}
/**/
/*
#include <string.h>

void *memcpy(void *dest, const void *src, size_t n);

Copie n bytes depuis src vers dest.
- retourne un pointeur sur dest.
- dest et src ne doivent pas se chevaucher.
- utiliser memmove si les aires memoires se chevauchent.
*/

void	memcpy_tests(void)
{
	int		fd;
	char	dest[SIZE_DEST];
	
	fd = open_file_msgs_error();

	print_fct_name("ft_memcpy");

	test_null_null_0(fd);
/*
	test(NULL, NULL, 0);
	test(NULL, NULL, 5);
	test(NULL, "src", 0);
	test(NULL, "src", 5);
*/	
/*	
	ft_bzero(dest, SIZE_DEST);
	test(dest, NULL, 0, fd);

	ft_bzero(dest, SIZE_DEST);
	test(dest, NULL, 5, fd);
*/	
	ft_memset(dest, '.', SIZE_DEST);
	test(dest, "done", 0, fd);

	ft_memset(dest, '.', SIZE_DEST);
	test(dest, "done", 1, fd);
	
	ft_memset(dest, '.', SIZE_DEST);
	test(dest, "done", 2, fd);

	ft_memset(dest, '.', SIZE_DEST);
	test(dest, "done", 4, fd);
	
	ft_memset(dest, '.', SIZE_DEST);
	test(dest, "done", 5, fd);

	ft_memset(dest, '.', SIZE_DEST);
	test(dest, "done", SIZE_DEST, fd);
	
	ft_memset(dest, '.', SIZE_DEST);
	test(dest, "", 0, fd);
	

	printf("\n");

	print_message_error(fd);

	close(fd);
}