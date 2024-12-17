/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:59:01 by moabdels          #+#    #+#             */
/*   Updated: 2024/06/28 14:27:58 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TESTING INCLUDES
// #include <stdio.h>
//START
#include <stdlib.h>
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n-- > 0)
		*ptr++ = c;
	return (s);
}
//END

//TESTING

// int	main(void)
// {
// 	char	arg[10];
// 	char	*modified;
// 	char	*ptr;
// 	int		ch;
// 	size_t	n;

// 	ch = 'u';
// 	n = 8;
// 	ptr = arg;
// 	modified = (char *)ft_memset(arg, ch, n);
// 	printf("Value at ptr      : %s\nValue at arg      : %s\n", ptr, arg);

// 	int i = 0;
// 	while (i < 9)
// 		modified[i++] = 'x';
// 	printf("Value at modified : %s\n", modified);
// 	return (0);
// }
