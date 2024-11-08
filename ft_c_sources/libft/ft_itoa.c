/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:59:01 by moabdels          #+#    #+#             */
/*   Updated: 2024/07/03 14:29:36 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TESTING INCLUDES
// #include <stdio.h>
//START
#include "libft.h"

static int	nbr_len(int nbr)
{
	int	len;

	len = 0;
	if (nbr < 1)
		len++;
	while (nbr)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

static long long	abs_val(long long n)
{
	long long	result;

	result = 1;
	if (n < 0)
		result *= -n;
	else
		result *= n;
	return (result);
}

static char	*str_new(size_t len)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	return (str);
}

char	*ft_itoa(int n)
{
	unsigned int	nbr;
	int				len;
	char			*result;

	len = nbr_len(n);
	result = str_new(len);
	if (!result)
		return (NULL);
	result[len] = '\0';
	nbr = abs_val(n);
	while (len--)
	{
		result[len] = 48 + nbr % 10;
		nbr /= 10;
	}
	if (n < 0)
		result[0] = 45;
	return (result);
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
// 		printf("%s\n", ft_itoa(ft_atoi(current_arg)));
// 		i_index++;
// 	}

// 	return (0);
// }
