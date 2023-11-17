/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_tests.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:21:32 by svogrig           #+#    #+#             */
/*   Updated: 2023/11/15 22:13:06 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test_stephane.h"

static void	test(char *str, char c, char **expected)
{
	char	**tab;
	int		i;

	tab = ft_split(str, c);
	if (!tab)
	{
		printf("echec allocation memoire");
		return ;
	}
	i = 0;
	//file = open_file_test_result();
	while(*expected)
	{
		//write(file, *expected, strlen(*expected);
		expected++;
	}
	
	while (tab[i])
	{
		/*ft_putnbr_fd(i, 1);
		ft_putstr_fd(" = ", 1);
		ft_putstr_fd(tab[i], 1);
		ft_putstr_fd("\n", 1);*/
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	split_tests(void)
{
	int	fd;
	
	fd = open_file_msgs_error();

	print_fct_name("ft_split");

	char	test1[] = "Mon test a moi";
	char	*expected[] = {"Mon", "test", "a", "moi", NULL};
	test(test1, ' ', expected);
/*	test("          ", ' ');
	test("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse", ' ');
	test("   lorem   ipsum dolor     sit amet, consectetur   adipiscing elit. Sed non risus. Suspendisse   ", ' ');
	test("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.", 'i');
	test("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.", 'z');
	test("", 'z');
*/
	printf("\n");

	print_message_error(fd);

	close(fd);
}
