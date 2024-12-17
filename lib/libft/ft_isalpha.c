/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:06:52 by moabdels          #+#    #+#             */
/*   Updated: 2024/07/03 14:28:39 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TESTING INCLUDES
// #include <stdio.h>
// #include <stdlib.h>
// #include <ctype.h>
//START
#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c > 64 && c < 91) || (c > 96 && c < 123))
		return (1024);
	return (0);
}

//END

// int	main(int argc, char const *argv[])
// {
// 	int			i_index;
// 	const char	*arg;

// 	i_index = 1;
// 	if (argc < 2)
// 	{
// 		printf("not enough args");
// 	}
// 	while (i_index < argc)
// 	{
// 		arg = argv[i_index];
// 		printf("arg %d - %s\n\tft_isalpha : %d\n\tisalpha : %d\n", i_index,
// 			arg, ft_isalpha(*arg), isalpha(*arg));
// 		i_index++;
// 	}
// 	return (0);
// }
