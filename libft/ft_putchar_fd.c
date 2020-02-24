/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 20:32:09 by wvenita           #+#    #+#             */
/*   Updated: 2019/04/15 21:41:14 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	char arr[2];

	if ((t_u8)c < 128)
		write(fd, &c, 1);
	else
	{
		arr[0] = ((3 << 6) + ((t_u8)c >> 6));
		arr[1] = ((1 << 7) + ((t_u8)c & 63));
		write(fd, arr, 2);
	}
}
