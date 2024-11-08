/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:59:01 by moabdels          #+#    #+#             */
/*   Updated: 2024/07/01 16:20:34 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TESTING INCLUDES
// #include <stdio.h>
// #include <stdlib.h>
// #include <bsd/string.h>
//START
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if (src_len + 1 < size)
		ft_memcpy(dst, src, src_len + 1);
	else if (size != 0)
	{
		ft_memcpy(dst, src, size - 1);
		dst[size - 1] = 0;
	}
	return (ft_strlen(src));
}

//END

//TESTING

// int	main(void)
// {
// 	char	*src;
// 	char	dest_buf[64];
// 	size_t	return_value;

// 	src = "some string";
// 	return_value = strlcpy(dest_buf, src, 6);
// 	printf("Source      : %s\nDestination : %s\nReturn Val  : %ld",
// 		src, dest_buf, return_value);
// 	return (0);
// }
