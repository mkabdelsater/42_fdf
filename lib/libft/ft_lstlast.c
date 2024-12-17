/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:59:01 by moabdels          #+#    #+#             */
/*   Updated: 2024/06/27 15:30:11 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TESTING INCLUDES
// #include <stdio.h>
//START
#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*temp;

	if (!lst)
		return (NULL);
	temp = lst;
	while (temp->next)
		temp = temp->next;
	return (temp);
}
//END

//TESTING

// int	main(int argc, char *argv[])
// {
// 	int		i_index;
// 	char	*current_arg;
// 	t_list	*new_node;
// 	t_list	*list;
// 	t_list	*temp;
// 	t_list	*last;

// 	list = NULL;
// 	i_index = 1;
// 	if (argc < 2)
// 	{
// 		printf("not enough args");
// 		return (1);
// 	}
// 	while (i_index < argc)
// 	{
// 		current_arg = argv[i_index];
// 		new_node = ft_lstnew(current_arg);
// 		ft_lstadd_front(&list, new_node);
// 		i_index++;
// 	}
// 	temp = list;
// 	while (temp)
// 	{
// 		printf("< %s > -> ", (char *)temp->content);
// 		temp = temp->next;
// 	}
// 	last = ft_lstlast(list);
// 	printf("\nlast element : %s\n", (char *)last->content);
// 	return (0);
// }
