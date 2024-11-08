/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:59:01 by moabdels          #+#    #+#             */
/*   Updated: 2024/07/01 16:45:24 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TESTING INCLUDES
// #include <stdio.h>
//START
// TODO : REVIEW_TAGS_K_M - see the reasoning of returning an empty string;
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i_index;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	result = ft_calloc(len + 1, sizeof(char));
	if (!result)
		return (NULL);
	i_index = 0;
	while (i_index < len)
	{
		result[i_index] = s[start + i_index];
		i_index++;
	}
	return (result);
}
//END

//TESTING

// int	main(int argc, char *argv[])
// {
// 	char	*rslt;

// 	if (argc < 4)
// 	{
// 		printf("not enough args");
// 		return (1);
// 	}
// 	rslt = ft_substr(argv[1], ft_atoi(argv[2]), ft_atoi(argv[3]));
// 	if (rslt)
// 		printf("Result = %s;\nSize   = %ld", rslt, ft_strlen(rslt));
// 	else
// 		printf("NULL returned");

// 	return (0);
// }
