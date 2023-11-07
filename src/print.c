/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svogrig <svogrig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 01:49:25 by svogrig           #+#    #+#             */
/*   Updated: 2023/11/07 00:42:32 by svogrig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test_stephane.h"

void	print_succes(bool succes)
{
    if (succes)
        printf(" %s[ok]", GREEN);
    else
        printf(" %s[ko]", RED);
    printf("%s", RESET);
}

void    print_fct_name(const char* name)
{
    char    str[17];
    int     i;
    
    i = 0;
    while (i < 14 && name[i])
    {
        str[i] = name[i];
        ++i;
    }
    while (i < 14)
    {
        str[i] = ' ';
        ++i;
    }
    str[14] = ':';
    str[15] = ' ';
    str[16] = '\0';
    write(1, str, 15);
}

void	print_message_error(int fd)
{
	char	*msgs_error;
	msgs_error = load_file_content(fd);
	ft_putstr_fd(msgs_error, 1);
    free(msgs_error);
}

