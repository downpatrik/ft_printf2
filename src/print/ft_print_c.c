/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 00:59:58 by wvenita           #+#    #+#             */
/*   Updated: 2020/02/24 14:06:17 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_index_one(char *output)
{
	int	i;

	i = 0;
	while (output[i] && output[i] != 1)
		i++;
	if (output[i] == 1)
		return (i);
	return (0);
}

char		*ft_print_c(va_list *ap, t_flag *flag)
{
	char	*output;
	size_t	size;

	size = ft_len_to_alloc(2, flag);
	if (!(output = (char *)ft_memalloc(size * sizeof(*output))))
		return (NULL);
	output[0] = (char)va_arg(*ap, int);
	output[1] = '\0';
	if (output[0] == 0)
	{
		flag->character = 0;
		output[0] = 1;
	}
	output = ft_apply_precision_str(output, flag, 1);
	output = ft_apply_padding_str(output, flag, 1);
	flag->character_i = ft_index_one(output);
	return (output);
}
