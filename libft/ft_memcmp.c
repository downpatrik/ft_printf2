/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 13:58:11 by wvenita           #+#    #+#             */
/*   Updated: 2019/04/12 00:18:24 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (n != 0)
		while (n--)
			if (*(t_u8*)s1++ != *(t_u8*)s2++)
				return (*(t_u8*)--s1 - *(t_u8*)--s2);
	return (0);
}
