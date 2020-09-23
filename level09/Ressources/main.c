/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcm1k <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 15:20:25 by mcm1k             #+#    #+#             */
/*   Updated: 2020/09/22 15:38:08 by mcm1k            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <stdio.h>
# include <stdlib.h>

int		main(int ac, char **av)
{
	int			fd;
	struct stat	st;
	char		*src;
	int			ret;

	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (NULL);
	if (stat(av[1], &st) == -1)
		return (NULL);
	if (!(src = (char *)malloc(st.st_size)))
		return (NULL);
	if ((ret = read(fd, src, st.st_size)) == -1)
		return (NULL);
	close(fd);

	int i = 0;
	while (i < st.st_size)
	{
		src[i] = src[i] - i;
		i++;
	}
	puts(src);
	return (0);
}
