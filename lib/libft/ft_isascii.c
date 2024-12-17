/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:59:01 by moabdels          #+#    #+#             */
/*   Updated: 2024/07/03 14:29:06 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TESTING INCLUDES
// #include <stdio.h>
// #include <stdlib.h>
//START

//END
#include "libft.h"

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
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
// 		printf("arg %d is : %s - is ascii ? : %d\n", i_index,
// 			argv[i_index], ft_isascii(*argv[i_index]));
// 		i_index++;
// 	}

// 	return (0);
// }
