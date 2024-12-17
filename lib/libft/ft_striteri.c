/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:59:01 by moabdels          #+#    #+#             */
/*   Updated: 2024/07/04 14:01:04 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TESTING INCLUDES
// #include <stdio.h>
//START
#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i_index;

	i_index = 0;
	while (s[i_index])
	{
		(*f)(i_index, &s[i_index]);
		i_index++;
	}
}
//END

//TESTING

// void	reverse_case_title(unsigned int index, char *chr_ptr)
// {
// 	if (*chr_ptr >= 'a' && *chr_ptr <= 'z')
// 		*chr_ptr -= 32;
// 	else if (*chr_ptr >= 'A' && *chr_ptr <= 'Z' && index)
// 		*chr_ptr += 32;
// }

// int	main(int argc, char *argv[])
// {
// 	int		i_index;
// 	char	*current_arg;

// 	i_index = 1;
// 	if (argc < 2)
// 	{
// 		printf("not enough args");
// 		return (1);
// 	}
// 	while (i_index < argc)
// 	{
// 		current_arg = argv[i_index];
// 		ft_striteri(current_arg, reverse_case_title);
// 		printf("Result : %s\n", current_arg);
// 		i_index++;
// 	}

// 	return (0);
// }
