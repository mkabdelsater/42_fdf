/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:59:01 by moabdels          #+#    #+#             */
/*   Updated: 2024/09/10 13:10:22 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TESTING INCLUDES
// #include <stdio.h>
//START
// TODO : In the future I should probably look up recursion vs iteration
// TODO : performance on a low level, and how the stack is handled for processes

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!del || !lst || !*lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
	free(*lst);
	*lst = NULL;
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
