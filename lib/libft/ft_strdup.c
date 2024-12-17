/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:59:01 by moabdels          #+#    #+#             */
/*   Updated: 2024/06/21 16:55:50 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TESTING INCLUDES
// #include <stdio.h>
//START
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup_str;
	size_t	s_len;

	s_len = ft_strlen(s) + 1;
	dup_str = (char *)malloc(sizeof(char) * s_len);
	if (!dup_str)
		return (NULL);
	return (ft_memcpy(dup_str, s, s_len));
}
//END

//TESTING

// int	main(int argc, char *argv[])
// {
// 	int		i_index;
// 	size_t	test_len;
// 	char	*current_arg;
// 	char	*test_str;

// 	i_index = 1;
// 	if (argc < 2)
// 	{
// 		printf("not enough args");
// 		return (1);
// 	}
// 	while (i_index < argc)
// 	{
// 		current_arg = argv[i_index];
// 		test_str = ft_strdup(current_arg);
// 		test_len = ft_strlen(test_str);
// 		printf("Copied string : %s\n", test_str);
// 		if (test_len == ft_strlen(current_arg))
// 			printf("Success : Lengths Match\n");
// 		else
// 			printf("Failure : Lengths don't Match!!\n");
// 		if (test_str[test_len + 1] == '\0')
// 			printf("Success : Test was Null Terminated\n");
// 		else
// 			printf("Failure : Test was not Null Terminated\n");
// 		i_index++;
// 	}

// 	return (0);
// }
