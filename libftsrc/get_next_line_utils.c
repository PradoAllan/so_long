/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprado <aprado@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:57:32 by aprado            #+#    #+#             */
/*   Updated: 2024/03/14 14:58:33 by aprado           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_gnl_strchr(char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (0);
}

int	ft_gnl_strlen(char *s)
{
	int	len;

	len = 0;
	if (s)
		while (s[len])
			len++;
	return (len);
}

char	*ft_gnl_strjoin(char *s1, char *s2)
{
	int		s1len;
	int		s2len;
	int		i;
	int		j;
	char	*new;

	if (!s1 && !s2)
		return (NULL);
	i = 0;
	s1len = ft_gnl_strlen(s1);
	s2len = ft_gnl_strlen(s2);
	new = (char *)malloc((s1len + s2len + 1) * sizeof(char));
	if (new == NULL)
		return (NULL);
	while (s1 && i < s1len)
	{
		new[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && j < s2len)
		new[i++] = s2[j++];
	new[i] = '\0';
	return (new);
}

char	*ft_gnl_strdup(char *s)
{
	int		strlen;
	int		i;
	char	*dup;

	i = 0;
	strlen = ft_gnl_strlen(s);
	dup = (char *)malloc((strlen + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);
	while (i < strlen)
		dup[i++] = *s++;
	dup[strlen] = '\0';
	return (dup);
}
