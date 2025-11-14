/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heychong <heychong@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 00:41:02 by heychong          #+#    #+#             */
/*   Updated: 2025/11/14 18:31:58 by heychong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_split(char const *str, char delimiter)
{
	int		count;
	int		judge;

	count = 0;
	judge = 0;
	while (*str)
	{
		if (*str != delimiter && !judge)
		{
			judge = 1;
			count++;
		}
		else if (*str == delimiter)
			judge = 0;
		str++;
	}
	return (count);
}

char	*word_dup(char *start, int len)
{
	char	*word;
	int		i;

	word = (char *)malloc(len + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = start[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**free_and_return_null(char **arr, int i)
{
	while (i > 0)
		free(arr[--i]);
	free(arr);
	return (NULL);
}

char	**execute(char **arr, char *str, char delimiter, int words)
{
	int	i;
	int	start;
	int	end;

	i = 0;
	start = 0;
	while (i < words)
	{
		while (str[start] == delimiter)
			start++;
		end = start;
		while (str[end] && str[end] != delimiter)
			end++;
		arr[i] = word_dup(str + start, end - start);
		if (!arr[i])
			return (free_and_return_null(arr, i));
		i++;
		start = end;
	}
	arr[i] = NULL;
	return (arr);
}

char	**ft_split(char *str, char delimiter)
{
	char	**arr;
	int		words;

	if (!str)
		return (NULL);
	words = count_split(str, delimiter);
	arr = (char **)malloc(sizeof(char *) * (words + 1));
	if (!arr)
		return (NULL);
	return (execute(arr, str, delimiter, words));
}

/*#include <stdio.h>

int	main()
{
	char	*str = "hello world";

	printf("%zu", count_split(str, ' '));
}*/
