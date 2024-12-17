/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:59:01 by moabdels          #+#    #+#             */
/*   Updated: 2024/06/24 16:04:54 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TESTING INCLUDES
// #include <stdio.h>
//START
#include "libft.h"

static short int	char_is_in_set(char const *set, char const chr)
{
	size_t	i_index;

	if (!set)
		return (0);
	i_index = 0;
	while (set[i_index])
	{
		if (chr == set[i_index])
			return (1);
		i_index++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	start;
	size_t	end;
	size_t	i_index;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && char_is_in_set(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && char_is_in_set(set, s1[end - 1]))
		end--;
	result = (char *)malloc((end - start + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i_index = 0;
	while ((start + i_index) < end)
	{
		result[i_index] = s1[start + i_index];
		i_index++;
	}
	result[i_index] = '\0';
	return (result);
}
//END

//TESTING

// int	main(int argc, char *argv[])
// {
// 	if (argc < 3)
// 	{
// 		printf("not enough args");
// 		return (1);
// 	}

// 	printf("Trimmed string : %s", ft_strtrim(argv[1], argv[2]));

// 	return (0);
// }
