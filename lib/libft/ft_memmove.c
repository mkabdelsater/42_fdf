/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:59:01 by moabdels          #+#    #+#             */
/*   Updated: 2024/06/28 14:28:55 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TESTING INCLUDES
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// void	print_arr(int *arr, int size)
// {
// 	int	i_index;

// 	i_index = 0;
// 	printf("{ ");
// 	while (i_index < size)
// 	{
// 		printf("%d ", arr[i_index]);
// 		i_index++;
// 	}
// 	printf("}\n");
// }

//START
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	void	*dest_ptr;

	dest_ptr = dest;
	if (!dest && !src)
		return (dest);
	if (dest == src)
		return (dest);
	if (dest > src)
	{
		while (n--)
			((char *)dest)[n] = ((char *)src)[n];
	}
	else
	{
		while (n--)
			*(char *)dest++ = *(char *)src++;
	}
	return (dest_ptr);
}
//END

//TESTING

// int	main(void)
// {
// 	int		source[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
// 	int		dest[10];

// 	printf("Initial Array : ");
// 	print_arr(source, 10);
// 	printf("Destination Array : ");
// 	ft_memmove(dest, source, sizeof(int) * 8);
// 	print_arr(dest, 10);
// 	ft_memmove(source + 2, source, sizeof(int) * 8);
// 	printf("Initial Array after using memmove on it : ");
// 	print_arr(source, 10);
// 	return (0);
// }
