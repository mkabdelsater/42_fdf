/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:59:01 by moabdels          #+#    #+#             */
/*   Updated: 2024/07/01 16:10:41 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TESTING INCLUDES
// #include <stdio.h>
// #include <stdlib.h>
//START

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	chr;

	chr = (char) c;
	while (*s)
	{
		if (*s == chr)
			return ((char *)s);
		s++;
	}
	if (*s == chr)
		return ((char *) s);
	return (0);
}
//END

//TESTING

// int	main(int argc, char const *argv[])
// {
// 	char	*ptr;

// 	if (argc < 3)
// 	{
// 		printf("not enough args");
// 		return (1);
// 	}

// 	ptr = ft_strchr(argv[1], *argv[2]);

// 	if (*ptr)
// 		printf("Found : %s", ptr);
// 	else
// 		printf("\'%c\' not found in %s", *argv[2], argv[1]);
// 	return (0);
// }
