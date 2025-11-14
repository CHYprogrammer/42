/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heychong <heychong@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 21:42:15 by heychong          #+#    #+#             */
/*   Updated: 2025/11/14 17:18:07 by heychong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	big_i;
	size_t	little_i;

	if (!little || !ft_strlen(little))
		return (big);
	big_i = 0;
	while (big[big_i] && big_i < len)
	{
		little_i = 0;
		while (little[little_i] == big[big_i + little_i]
			&& big_i + little_i < len)
			little_i++;
		if (little[little_i] == '\0')
			return (big + big_i);
		big_i++;
	}
	return (NULL);
}

/*#include <stdio.h>
#include <bsd/string.h>

int	main(void)
{
	char	*haystack = "";
	char	*needle = "";

	printf("MyResult: %s\n", ft_strnstr(haystack, needle, -1));
	printf("Expected: %s\n", strnstr(haystack, needle, -1));
	printf("MyResult: %s\n", ft_strnstr(haystack, needle, 0));
	printf("Expected: %s\n", strnstr(haystack, needle, 0));
}*/
