/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 00:56:06 by wvenita           #+#    #+#             */
/*   Updated: 2020/02/24 14:13:32 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*str_to_fill(char *str, t_flag *flag, int sign)
{
	char			*to_add;
	unsigned int	to_add_len;
	unsigned int	i;

	(void)sign;
	to_add_len = 0;
	if (to_add_len + ft_strlen(str) >= flag->width)
		return (ft_strdup(""));
	if (!(to_add = (char *)ft_memalloc(sizeof(char) * (flag->width + 2))))
		return (NULL);
	i = 0;
	while (to_add_len + ft_strlen(str) + i < flag->width)
	{
		to_add[i] = ft_can_fill_with_zeros_float(flag, sign) ? '0' : ' ';
		i++;
	}
	to_add[i] = '\0';
	return (to_add);
}

char		*ft_apply_padding_str(char *str, t_flag *flag, int sign)
{
	char	*to_add;

	if (str[0] && str[0] == '0' && flag->conv == 'o')
		flag->hash = 0;
	to_add = str_to_fill(str, flag, sign);
	if (flag->minus == 1)
		str = ft_str_join_r(str, to_add, flag);
	else
		str = ft_str_join(to_add, str, flag);
	ft_memdel((void **)&to_add);
	return (str);
}
