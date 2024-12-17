/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:59:01 by moabdels          #+#    #+#             */
/*   Updated: 2024/09/19 17:45:42 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TESTING INCLUDES
// #include <stdio.h>
//START
#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	size;

	size = 0;
	while (str[size])
		size++;
	return (size);
}
//END

//TESTING

// int	main(int argc, char const *argv[])
// {
// 	int	i_index;

// 	i_index = 1;
// 	if (argc < 2)
// 	{
// 		printf("not enough args");
// 	}
// 	while (i_index < argc)
// 	{
// 		printf("arg %d is : %s\n", i_index, argv[i_index]);
// 		i_index++;
// 	}

// 	return (0);
// }
