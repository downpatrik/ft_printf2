/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 01:30:56 by wvenita           #+#    #+#             */
/*   Updated: 2020/02/24 14:15:20 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strcat_char(char *s1, const char c)
{
	size_t	len1;

	len1 = ft_strlen(s1);
	s1[len1] = c;
	s1[len1 + 1] = '\0';
	return (s1);
}
