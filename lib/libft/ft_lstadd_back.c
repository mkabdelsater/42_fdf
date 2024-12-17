/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:59:01 by moabdels          #+#    #+#             */
/*   Updated: 2024/09/19 18:02:33 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TESTING INCLUDES
// #include <stdio.h>
//START
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}
//END

//TESTING

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
// 		printf("arg %d is : %s\n", i_index, current_arg);
// 		i_index++;
// 	}

// 	return (0);
// }
