/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:59:01 by moabdels          #+#    #+#             */
/*   Updated: 2024/06/28 14:26:26 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TESTING INCLUDES
// #include <stdio.h>
//START
#include "libft.h"

void	print_list(t_list *lst);

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;
	t_list	*new_list;

	new_list = NULL;
	new_node = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (!new_node)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
//END

//TESTING
// * This should test all the list functions *

// static void	encode_caesar_char(unsigned int index, char *chr)
// {
// 	if (index == 0)
// 		*chr = ft_toupper(*chr);
// 	if (*chr == 'z' || *chr == 'Z')
// 		*chr -= 25;
// 	else if (ft_isalpha(*chr))
// 		(*chr)++;
// }

// static void	encode_caesar_str(void *str)
// {
// 	ft_striteri(str, encode_caesar_char);
// }

// static void	reverse_char_case(unsigned int index, char *c)
// {
// 	if (*c <= 'z' && *c >= 'a')
// 		*c = ft_toupper(*c);
// 	else if (*c >= 'A' && *c <= 'Z' && index)
// 		*c = ft_tolower(*c);
// }

// static void	*reverse_case(void *str)
// {
// 	ft_striteri(str, reverse_char_case);
// 	return (str);
// }

// void	print_list(t_list *lst)
// {
// 	t_list	*temp;

// 	temp = lst;
// 	while (temp)
// 	{
// 		printf("(%s) -> ", (char *)temp->content);
// 		temp = temp->next;
// 	}
// 	printf("\n");
// }

// static void del_str(void *str)
// {
// 	printf("Attempting to free %s\n", (char *)str);
// }

// int	main(int argc, char *argv[])
// {
// 	int		i_index;
// 	char	*current_arg;
// 	t_list	*new_node;
// 	t_list	*list;
// 	t_list	*new_list;

// 	list = NULL;
// 	new_list = NULL;
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
// 	print_list(list);
// 	printf("\nlist size : %d\n", ft_lstsize(list));
// 	ft_lstiter(list, encode_caesar_str);
// 	printf("List After Applying Cipher :\n");
// 	print_list(list);
// 	new_list = ft_lstmap(list, reverse_case, del_str);
// 	printf("New List :\n");
// 	print_list(new_list);
// 	print_list(list);
// 	printf("Clearing List...\n");
// 	ft_lstclear(&list, del_str);
// 	print_list(list);
// 	return (0);
// }
