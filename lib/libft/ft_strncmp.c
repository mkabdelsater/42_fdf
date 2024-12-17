/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:59:01 by moabdels          #+#    #+#             */
/*   Updated: 2024/07/01 16:28:54 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TESTING INCLUDES
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
//START
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i_index;

	i_index = 0;
	while ((s1[i_index] || s2[i_index]) && i_index < n)
	{
		if ((unsigned char) s1[i_index] != (unsigned char) s2[i_index])
			return ((unsigned char) s1[i_index] - (unsigned char) s2[i_index]);
		i_index++;
	}
	return (0);
}
//END

//TESTING

// int	main(int argc, char const *argv[])
// {
// 	int	ft_res;
// 	int	std_res;

// 	if (argc < 4)
// 	{
// 		printf("not enough args");
// 		return (1);
// 	}
// 	ft_res = ft_strncmp(argv[1], argv[2], atoi(argv[3]));
// 	std_res = strncmp(argv[1], argv[2], atoi(argv[3]));
// 	printf("ft_strncmp returns : %d\nstrncmp returns :   %d\n",
// 		ft_res, std_res);

// 	return (0);
// }
