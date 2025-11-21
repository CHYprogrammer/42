/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heychong <heychong@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:14:47 by heychong          #+#    #+#             */
/*   Updated: 2025/11/21 19:05:54 by heychong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			*buff;
	static char		*stash;
	static size_t	count;

	if (fd == -1)
		return (NULL);
	count = BUFFER_SIZE;
	if (stash)
		count += ft_strlen(stash);
	buff = (char *)malloc(count);
	if (!buff)
		return (NULL);
	read(fd, buff, count);
}

/*essencial variables:
	char	*buff;			最終的な返り値。BUF_SIZE分読み込んだfd内の、\n, \0, 
EOFが出るまでを一行として結果を返す。（改行文字で区切られた場合、改行文字も含
めて返す）BUF_SIZE内で上の区切りを読み取れなかった分は以下のstashに
保管される。
	static char	*stash;	次にgnl関数が呼び出されたときは、この変数の冒頭から
読み込みを開始する。
*/
