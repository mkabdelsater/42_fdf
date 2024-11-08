/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:59:01 by moabdels          #+#    #+#             */
/*   Updated: 2024/07/03 14:41:11 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TESTING INCLUDES
// #include <stdio.h>
//START
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*return_ptr;

	if (size && nmemb >= 2147483647 / size)
		return (NULL);
	return_ptr = malloc(nmemb * size);
	if (!return_ptr)
		return (NULL);
	ft_memset(return_ptr, 0, nmemb * size);
	return (return_ptr);
}
//END

//TESTING

// TODO: REVIEW_FLAG_H 
// TODO: calloc from stdlib on this machine works on size < 0
// TODO: ft_calloc (mine) doesn't, WHY????

// void	check_ptr(char *ptr)
// {
// 	if (ptr)
// 	{
// 		printf("NOT NULL");
// 	}
// 	else
// 		printf("NULL\n");
// }

// int	main(int argc, char *argv[])
// {
// 	char	*ft_ptr;
// 	char	*std_ptr;
// 	int		nmemb;
// 	int		size;

// 	if (argc < 3)
// 	{
// 		printf("not enough args");
// 		return (1);
// 	}
// 	nmemb = atoi(argv[1]);
// 	size = atoi(argv[2]);
// 	printf("ft_calloc pointer     : ");
// 	ft_ptr = (char *)ft_calloc(nmemb, size);
// 	check_ptr(ft_ptr);
// 	printf("stdlib.calloc pointer : ");
// 	std_ptr = (char *)calloc(nmemb, size);
// 	check_ptr(std_ptr);

// 	return (0);
// }
