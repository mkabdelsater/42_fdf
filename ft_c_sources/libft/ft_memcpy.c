/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:59:01 by moabdels          #+#    #+#             */
/*   Updated: 2024/06/13 15:38:36 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TESTING INCLUDES
// #include <stdio.h>
// #include <stdlib.h>
//START
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	void	*dest_ptr;

	dest_ptr = dest;
	if (!dest && !src)
		return (dest);
	while (n--)
		*(char *)dest++ = *(char *)src++;
	return (dest_ptr);
}
//END

//TESTING

// int	main(void)
// {
// 	char	src[] = "example";
// 	char 	*src_ptr = &src[0];
// 	char	dest[7];
// 	int		copy[5];
// 	int 	i_index = 0;

// 	ft_memcpy(dest, src, sizeof(src));
// 	printf("Source : %s\nDest   : %s\n", src_ptr, dest);

// 	int	numbers[] = {1, 2, 4, 8, 16};

// 	ft_memcpy(copy, numbers, 5 * sizeof(int));
// 	while (i_index < 5)
// 	{
// 		printf("src[%d] : %d, dest[%d] : %d\n", i_index, numbers[i_index],
// 			i_index, copy[i_index]);
// 		i_index++;
// 	}
// 	return (0);
// }
