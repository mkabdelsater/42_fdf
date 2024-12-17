/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:59:01 by moabdels          #+#    #+#             */
/*   Updated: 2024/06/13 14:45:53 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TESTING INCLUDES
// #include <stdio.h>
// #include <stdlib.h>
//START
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
//END
//TESTING

// int	main(void)
// {
// 	char	arr[10];
// 	char	*ptr;

// 	ptr = arr;
// 	ptr = ft_memset(arr, 'u', 8);
// 	printf("After memset : %s\n", ptr);
// 	ft_bzero(ptr, 8);
// 	printf("After bzero  : %s\n", ptr);

// 	return (0);
// }
