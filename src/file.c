/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephane <stephane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 01:47:59 by svogrig           #+#    #+#             */
/*   Updated: 2023/11/11 12:36:13 by stephane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test_stephane.h"

int	open_file_test_result(void)
{
	int			fd;
	mode_t		mode;

	mode = S_IRUSR | S_IWUSR;
	fd = open("log_libft_test_stephane_test_result", O_CREAT | O_RDWR | O_TRUNC, mode);
	return (fd);
}

int	open_file_msgs_error(void)
{
	int			fd;
	mode_t		mode;

	mode = S_IRUSR | S_IWUSR;
	fd = open("log_libft_test_stephane_msgs_error", O_CREAT | O_RDWR | O_TRUNC | O_APPEND, mode);
	return (fd);
}

char	*load_file_content(int fd)
{
	struct stat	file_attribut;
	char		*content;

	fstat(fd, &file_attribut);
	content = malloc(file_attribut.st_size + 1);
	if (!content)
		return (NULL);
	lseek(fd, 0, SEEK_SET);
	read(fd, content, file_attribut.st_size);
	*(content + file_attribut.st_size) = '\0';
	return (content);
}
