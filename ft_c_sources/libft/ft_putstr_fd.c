/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:59:01 by moabdels          #+#    #+#             */
/*   Updated: 2024/06/27 12:19:51 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TESTING INCLUDES
// #include <stdio.h>
//START
#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}
//END

//TESTING

// int	main(int argc, char *argv[])
// {
// 	char	*str;
// 	int		fd;

// 	if (argc < 3)
// 	{
// 		printf("not enough args");
// 		return (1);
// 	}

// 	str = argv[1];
// 	fd = ft_atoi(argv[2]);
// 	ft_putstr_fd(str, fd);

// 	return (0);
// }
