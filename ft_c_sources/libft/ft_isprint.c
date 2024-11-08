/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:59:01 by moabdels          #+#    #+#             */
/*   Updated: 2024/07/03 14:29:27 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TESTING INCLUDES
// #include <stdio.h>
// #include <stdlib.h>
//START

//END
#include "libft.h"

int	ft_isprint(int c)
{
	if (c > 31 && c < 127)
	{
		return (16384);
	}
	return (0);
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
// 		printf("arg %d is : %s\n", i_index, argv[i_index]);
// 		i_index++;
// 	}

// 	return (0);
// }
