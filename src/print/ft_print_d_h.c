/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d_h.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 01:01:19 by wvenita           #+#    #+#             */
/*   Updated: 2020/02/24 01:02:26 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t ft_nblen_dh(short nb)
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

static char *ft_dhtoa_offset(short nb, size_t size)
{
  char *output;
  size_t nb_len;
  short n;

  n = nb;
  if (nb == 0)
    return (ft_strdup_alloc("0", size));
  if (nb == SHRT_MIN)
    return (ft_strdup_alloc("32768", size));
  nb_len = ft_nblen_dh(n);
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

char *ft_print_d_h(va_list *ap, t_flag *flag)
{
  char *output;
  short tmp_val;
  size_t size;
  int tmp;
  int sign;

  tmp = va_arg(*ap, int);
  sign = (short)tmp;
  tmp_val = (short)tmp;
  size = ft_nblen_dh(tmp_val);
  size = ft_len_to_alloc(size, flag);
  output = ft_dhtoa_offset(tmp_val, size);
  output = ft_apply_precision_nb(output, flag, sign);
  output = ft_apply_padding_nb(output, flag, sign);
  return (output);
}