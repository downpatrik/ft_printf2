/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_join.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 01:30:48 by wvenita           #+#    #+#             */
/*   Updated: 2020/02/24 14:15:37 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_str_join(const char *to_add, char *str1, t_flag *flag)
{
	char	*output;
	size_t	size_allocation;
	int		k;
	int		i;

	size_allocation = ft_len_to_alloc(
			ft_strlen(str1) + ft_strlen(to_add), flag);
	if (!(output = (char *)ft_memalloc(sizeof(char) * (size_allocation + 1))))
		return (NULL);
	k = 0;
	i = 0;
	while (to_add[i])
		output[k++] = to_add[i++];
	i = 0;
	while (str1[i])
		output[k++] = str1[i++];
	output[k] = 0;
	ft_memdel((void **)&str1);
	return (output);
}
