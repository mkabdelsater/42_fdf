/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:59:01 by moabdels          #+#    #+#             */
/*   Updated: 2024/06/28 14:29:33 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TESTING INCLUDES
// #include <stdio.h>

//START
#include "libft.h"
#include <stdlib.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		dest_len;
	size_t		total_len;
	const char	*src_copy;

	if ((!dst || !src) && !size)
		return (0);
	src_copy = src;
	dest_len = 0;
	while (*(dst + dest_len) && dest_len < size)
		dest_len++;
	if (dest_len < size)
		total_len = dest_len + ft_strlen(src);
	else
		return (size + ft_strlen(src_copy));
	while (*src_copy && (dest_len + 1) < size)
	{
		*(dst + dest_len) = *src_copy++;
		dest_len++;
	}
	*(dst + dest_len) = '\0';
	return (total_len);
}

//END

//TESTING

// int	main(int argc, char *argv[])
// {
// 	char	dest_buf[100];
// 	char	*src;
// 	char	*dest_buf_ptr;
// 	size_t	to_copy, to_cat;

// 	if (argc < 2)
// 		return (1);
// 	to_copy = ft_strlen(argv[1]) / 2;
// 	to_cat = ft_strlen(argv[2]) / 2;
// 	src = argv[1];
// 	printf("Attempting to copy %ld from %s\n", to_copy, src);
// 	printf("Copied %ld chars, result : %s\n",
// 		ft_strlcpy(dest_buf, src, to_copy + 1),
// 		dest_buf);
// 	src = argv[2];
// 	printf("Attempting to Cat  %ld from %s\n", to_cat, argv[2]);
// 	printf("Cat-ed %ld chars, result : %s\n",
// 		ft_strlcat(dest_buf, src, to_cat + to_copy + 1), dest_buf);
// 	printf("Expected Size : %ld\nActual Size  : %ld\n", to_copy + to_cat,
// 		ft_strlen(dest_buf));
// 	dest_buf_ptr = dest_buf;
// 	while (*dest_buf_ptr)
// 	{
// 		printf("%c\n", *dest_buf_ptr);
// 		dest_buf_ptr++;
// 	}
// 	return (0);
// }
