/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_alloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 01:31:01 by wvenita           #+#    #+#             */
/*   Updated: 2020/02/24 01:31:01 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *ft_strdup_alloc(const char *s1, size_t size_allocation)
{
	char *copy;

	if (!(copy = (char *)malloc((size_allocation) * sizeof(char))))
		return (NULL);
	copy = ft_strcpy(copy, s1);
	return (copy);
}
