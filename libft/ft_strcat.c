/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 21:53:27 by wvenita           #+#    #+#             */
/*   Updated: 2020/02/24 14:26:53 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int		i;
	size_t	n;

	i = -1;
	n = ft_strlen(dest);
	while (src[++i])
		dest[n + i] = src[i];
	dest[n + i] = '\0';
	return (dest);
}

char	*ft_strcat_r(const char *src, char *dst)
{
	char	*tmp;

	tmp = ft_strdup(dst);
	if (tmp == NULL)
		return (NULL);
	ft_strcpy(dst, src);
	ft_strcat(dst, tmp);
	ft_memdel((void **)&tmp);
	return (dst);
}
