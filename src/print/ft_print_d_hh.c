/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d_hh.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 01:05:00 by wvenita           #+#    #+#             */
/*   Updated: 2020/02/24 01:05:09 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t ft_nblen_dhh(char nb)
{
  size_t nblen;

  nblen = 0;
  if (nb == 0)
    return (1);
  while (nb != 0)
  {
    nb /= 10;
    nblen++;
  }
  return (nblen);
}

static char *ft_dhhtoa_offset(char nb, size_t size)
{
  char *output;
  size_t nb_len;
  char n;

  n = nb;
  if (nb == 0)
    return (ft_strdup_alloc("0", size));
  if (nb == CHAR_MIN)
    return (ft_strdup_alloc("128", size));
  nb_len = ft_nblen_dhh(n);
  if (!(output = (char *)ft_memalloc((size + 1) * sizeof(*output))))
    return (NULL);
  n = n < 0 ? -n : n;
  output[nb_len] = '\0';
  while (n != 0)
  {
    output[--nb_len] = (n % 10) + '0';
    n /= 10;
  }
  return (output);
}

char *ft_print_d_hh(va_list *ap, t_flag *flag)
{
  char *output;
  char tmp_val;
  size_t size;
  int tmp;
  int sign;

  tmp = va_arg(*ap, int);
  sign = (char)tmp;
  tmp_val = (char)tmp;
  size = ft_nblen_dhh(tmp_val);
  size = ft_len_to_alloc(size, flag);
  output = ft_dhhtoa_offset(tmp_val, size);
  output = ft_apply_precision_nb(output, flag, sign);
  output = ft_apply_padding_nb(output, flag, sign);
  return (output);
}