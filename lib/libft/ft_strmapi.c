/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:59:01 by moabdels          #+#    #+#             */
/*   Updated: 2024/07/01 16:48:27 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TESTING INCLUDES
// #include <stdio.h>
//START
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i_index;
	char			*result;

	if (!s)
		return (NULL);
	result = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i_index = 0;
	while (i_index < ft_strlen(s))
	{
		result[i_index] = f(i_index, s[i_index]);
		i_index++;
	}
	result[i_index] = 0;
	return (result);
}
//END

//TESTING

// char	to_upper(unsigned int index, char c)
// {
// 	if (c >= 'a' && c <= 'z' && ++index)
// 		return (c - 32);
// 	return (c);
// }

// int	main(int argc, char *argv[])
// {
// 	char	*result;

// 	if (argc < 2)
// 		return (1);
// 	result = ft_strmapi(argv[1], to_upper);
// 	printf("Result : %s", result);
// 	return (0);
// }
