/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:59:01 by moabdels          #+#    #+#             */
/*   Updated: 2024/09/16 12:47:47 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TESTING INCLUDES
// #include <stdio.h>
//START
#include "libft.h"

size_t	ft_count_words(char const *str, char delimiter)
{
	size_t				i_index;
	size_t				count;

	i_index = 0;
	count = 0;
	while (str[i_index])
	{
		if (str[i_index] != delimiter)
		{
			count++;
			while (str[i_index] && str[i_index] != delimiter)
				i_index++;
		}
		else if (str[i_index] == delimiter)
			i_index++;
	}
	return (count);
}

static size_t	get_word_len(char const *str, char delimiter)
{
	size_t	i_index;

	i_index = 0;
	while (str[i_index] && str[i_index] != delimiter)
		i_index++;
	return (i_index);
}

static void	free_2d_char_array(size_t size, char **arr)
{
	while (size--)
		free(arr[size]);
	free(arr);
}

static char	**splice(char const *str, char chr, char **arr, size_t word_count)
{
	size_t	i_index;
	size_t	j_index;

	i_index = 0;
	j_index = 0;
	while (i_index < word_count)
	{
		while (str[j_index] && str[j_index] == chr)
			j_index++;
		arr[i_index] = ft_substr(str, j_index,
				get_word_len(&str[j_index], chr));
		if (!arr[i_index])
		{
			free_2d_char_array(i_index, arr);
			return (NULL);
		}
		while (str[j_index] && str[j_index] != chr)
			j_index++;
		i_index++;
	}
	arr[i_index] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	words;

	if (!s)
		return (NULL);
	words = ft_count_words(s, c);
	result = (char **)malloc(sizeof(char *) * (words + 1));
	if (!result)
		return (NULL);
	result = splice(s, c, result, words);
	return (result);
}
//END

//TESTING

// int	main(int argc, char *argv[])
// {
// 	char	**result;
// 	size_t	i_index;

// 	i_index = 0;
// 	if (argc < 2)
// 	{
// 		printf("not enough args");
// 		return (1);
// 	}
// 	result = ft_split(argv[1], *argv[2]);
// 	printf("Final Result :\n");
// 	while (result[i_index])
// 	{
// 		printf("%s\n", result[i_index]);
// 		i_index++;
// 	}
// 	printf("this should be null? <%s>", result[i_index]);
// 	return (0);
// }
