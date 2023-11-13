/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcmp_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephane <stephane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:05:05 by svogrig           #+#    #+#             */
/*   Updated: 2023/11/12 12:50:51 by stephane         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft_test_stephane.h"


/*
#include <string.h>

int memcmp(const void *s1, const void *s2, size_t n);

Compare les n premiers octets des zones mémoire s1 et s2.
- Renvoi un entier inférieur à zero si s1 est inferieur à s2.
- Renvoi un entier égal à zero si est egal à s2.
- Renvoi un entier superieur à zéro si s1 est supérieur à s2.
*/
void	memcmp_tests(void)
{
	int	fd;

	fd = open_file_msgs_error();

	print_fct_name("ft_memcmp");

	printf("\n");

	print_message_error(fd);

	close(fd);
}