/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 01:10:34 by wvenita           #+#    #+#             */
/*   Updated: 2020/02/24 13:54:19 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_print_s(va_list *ap, t_flag *flag)
{
	char	*output;
	char	*arg;
	size_t	size;

	arg = va_arg(*ap, char *);
	size = arg == NULL ? ft_strlen("(null)") : ft_strlen(arg);
	size = ft_len_to_alloc(size, flag);
	if (!(output = (char *)ft_memalloc(sizeof(char) * size)))
		return (NULL);
	output = ft_strcpy(output, arg == NULL ? "(null)" : arg);
	output = ft_apply_precision_str(output, flag, 1);
	output = ft_apply_padding_str(output, flag, 1);
	return (output);
}
