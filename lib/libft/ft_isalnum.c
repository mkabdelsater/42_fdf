/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:59:01 by moabdels          #+#    #+#             */
/*   Updated: 2024/07/01 15:40:18 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TESTING INCLUDES
// #include <stdio.h>
// #include <stdlib.h>
//START
#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isdigit(c) || ft_isalpha(c));
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
