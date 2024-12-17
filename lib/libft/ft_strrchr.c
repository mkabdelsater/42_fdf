/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:59:01 by moabdels          #+#    #+#             */
/*   Updated: 2024/07/03 14:23:17 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TESTING INCLUDES
// #include <stdio.h>
// #include <stdlib.h>
//START
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i_index;
	char			*return_ptr;
	char			chr;

	return_ptr = NULL;
	i_index = 0;
	chr = (char) c;
	while (s[i_index])
	{
		if (s[i_index] == chr)
			return_ptr = (char *) &s[i_index];
		i_index++;
	}
	if (s[i_index] == c)
		return_ptr = (char *) &s[i_index];
	return (return_ptr);
}
//END

//TESTING

// int	main(int argc, char const *argv[])
// {
// 	char	*ptr;
// 	char	*test;

// 	test = "tesae";
// 	if (argc < 3)
// 	{
// 		printf("not enough args");
// 		return (1);
// 	}

// 	ptr = ft_strrchr(argv[1], *argv[2]);

// 	if (ptr)
// 		printf("\'%c\' Found in %s @ %s\n",*argv[2], argv[1], ptr);
// 	else
// 		printf("\'%c\' not found in %s\n", *argv[2], argv[1]);
// 	return (0);
// }
