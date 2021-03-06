/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 12:10:44 by tsiguenz          #+#    #+#             */
/*   Updated: 2021/12/30 12:43:41 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*gnl_strdup(char *s)
{
	int		i;
	char	*dup;

	i = 0;
	dup = gnl_calloc((gnl_strlen(s) + 1), sizeof(char));
	if (!dup)
		return (0);
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	return (dup);
}

void	*gnl_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	void	*ptr;

	i = 0;
	if (!nmemb || !size)
		return (0);
	ptr = malloc(nmemb * size);
	if (ptr == 0)
		return (0);
	while (i < (nmemb * size))
	{
		*(char *)(ptr + i) = 0;
		i++;
	}
	return (ptr);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	res = gnl_calloc((gnl_strlen(s1) + gnl_strlen(s2) + 1), sizeof(char));
	if (!res)
		return (0);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	return (res);
}
