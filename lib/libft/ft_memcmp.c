/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:59:01 by moabdels          #+#    #+#             */
/*   Updated: 2024/06/20 13:48:38 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TESTING INCLUDES
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
//START
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str_1;
	const unsigned char	*str_2;

	str_1 = s1;
	str_2 = s2;
	while (n--)
	{
		if (*str_1++ != *str_2++)
			return (str_1[-1] - str_2[-1]);
	}
	return (0);
}

//END

//TESTING

// int	main(void)
// {
// 	char	arr1[] = {1, 2, 3};
// 	char	arr2[] = {1, 2, 2};
// 	int		result = ft_memcmp(arr1, arr2, sizeof(arr1));
// 	int		std_result = memcmp(arr1, arr2, sizeof(arr1));

// 	printf("ft_memcmp returns : %d\nmemcmp returns   : %d\n",
// 		result, std_result);

// 	int 	a = 123;
// 	int		b = 123;
// 	result = ft_memcmp(&a, &b, sizeof(int));
// 	std_result = memcmp(&a, &b, sizeof(int));

// 	printf("ft_memcmp returns : %d\nmemcmp returns   : %d\n",
// 		result, std_result);

// 	return (0);
// }
