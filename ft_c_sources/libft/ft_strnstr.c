/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:59:01 by moabdels          #+#    #+#             */
/*   Updated: 2024/07/01 16:25:45 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TESTING INCLUDES
// #include <stdio.h>
// #include <stdlib.h>
//START
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i_index;
	size_t	j_index;

	i_index = 0;
	j_index = 0;
	if (little[0] == 0)
		return ((char *) big);
	while (big[i_index] && i_index < len)
	{
		while (big[i_index + j_index]
			&& big[i_index + j_index] == little[j_index]
			&& i_index + j_index < len)
		{
			j_index++;
			if (little[j_index] == 0)
				return ((char *) big + i_index);
		}
		i_index++;
		j_index = 0;
	}
	return (NULL);
}

//END

//TESTING

// int	main(int argc, const char *argv[])
// {
// 	const char	*little;
// 	const char	*big;
// 	size_t		len;
// 	char		*result;

// 	if (argc < 4)
// 	{
// 		printf("Not enough args!\n");
// 		return (1);
// 	}

// 	big = argv[1];
// 	little = argv[2];
// 	len = atoi(argv[3]);
// 	result = ft_strnstr(big, little, len);

// 	if (result)
// 		printf("Found : %s", result);
// 	else
// 		printf("Not Found");
// 	return (0);
// }
