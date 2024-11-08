/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:59:01 by moabdels          #+#    #+#             */
/*   Updated: 2024/06/28 14:27:39 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TESTING INCLUDES
// #include <stdio.h>
//START
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	char	*result_ptr;

	if (!s1 || !s2)
		return (NULL);
	result = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result_ptr = result;
	while (*s1)
		*result++ = *s1++;
	while (*s2)
		*result++ = *s2++;
	*result = '\0';
	return (result_ptr);
}

//END

//TESTING

// int	main(int argc, char *argv[])
// {
// 	char	*result;
// 	size_t	result_len;

// 	if (argc < 2)
// 		return (1);
// 	result = ft_strjoin(argv[1], argv[2]);
// 	result_len = ft_strlen(result);
// 	printf("Result : %s\nLength : %ld\nSize   : %ld\n", result, result_len,
// 		sizeof(result));
// 	if (result[result_len + 1] == '\0')
// 		printf("NULT");
// 	else
// 		printf("Not NULT");

// 	return (0);
// }
