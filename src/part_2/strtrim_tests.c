/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtrim_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:22:38 by svogrig           #+#    #+#             */
/*   Updated: 2023/11/07 00:35:41 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
char	*ft_strim(char const *s1, char const *set);

- retourne une copy de s1 en ayant supprime au debut et la fin les caracteres
  contnus dans set.
- allocation avec malloc
- return NULL en cas d'echec de l'allocation 
*/

#include "libft_test_stephane.h"

static void	test(char *s, char *set, char *expected, int file_msg_error)
{
	char 	*str_user;
	int		error;

	str_user = ft_strtrim(s, set);
	if (!str_user)
		return ;
	error = strcmp(str_user, expected);
	print_succes(error == 0);
	if (error)
	{
		log_test_str_str(s, set, file_msg_error);
		log_result_str_str(expected, str_user, file_msg_error);
	}
	free(str_user);
}

void	strtrim_tests(void)
{
	int	file_msg_error;

	file_msg_error = open_file_msgs_error();

	print_fct_name("ft_strtrim");
		
	test("12345ABCDEabcde12345", "12345", "ABCDEabcde", file_msg_error);
	test("12345ABCDEabcde12345", "", "12345ABCDEabcde12345", file_msg_error);
	test("12345ABCDEabcde12345", "ABCDE", "12345ABCDEabcde12345", file_msg_error);
	test("12345ABCDEabcde12345", "ABCDEabcde", "12345ABCDEabcde12345",file_msg_error);
	test("12345ABCDEabcde12345", "ABCDEabcde12345", "", file_msg_error);

	printf("\n");

	print_message_error(file_msg_error);

	close(file_msg_error);
}