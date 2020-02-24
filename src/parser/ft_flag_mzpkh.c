/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_mzpkh.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 00:44:42 by wvenita           #+#    #+#             */
/*   Updated: 2020/02/24 04:46:58 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_flag_get_hash(char *flag)
{
  unsigned int i;

  i = 0;
  if (flag[ft_strlen(flag) - 1] == '%')
    return (0);
  while ((flag[i] && is_valid_conversion(flag[i]) == 0) || flag[i] == '0')
  {
    if (flag[i] == '#')
      return (1);
    i++;
  }
  return (0);
}

int ft_flag_get_key(char *flag)
{
  char c;

  c = flag[ft_strlen(flag) - 1];
  if (ft_strlen(flag) == 1)
    return (0);
  if (c == '%')
    return (KEY_PERCENTAGE);
  else if (c == 'c' || c == 'C')
    return (KEY_C);
  else if (c == 'd' || c == 'i' || c == 'D')
    return (KEY_D);
  else if (c == 'o' || c == 'x' || c == 'X' || c == 'u' || c == 'O' || c == 'U' || c == 'b')
    return (KEY_NB);
  else if (c == 'p')
    return (KEY_P);
  else if (c == 's' || c == 'S')
    return (KEY_S);
  else if (c == 'f')
    return (KEY_F);
  else if (c == 'e')
    return (KEY_E);
  else
    return (0);
}

int ft_flag_get_minus(char *flag)
{
  unsigned int i;

  i = 0;
  while (flag[i])
  {
    if (flag[i] == '-')
      return (1);
    i++;
  }
  return (0);
}

int ft_flag_get_plus(char *flag)
{
  unsigned int i;

  i = 0;
  if (flag[ft_strlen(flag) - 1] == '%')
    return (0);
  while (flag[i] && (is_valid_conversion(flag[i]) == 0 || flag[i] == '0'))
  {
    if (flag[i] == '+')
      return (1);
    i++;
  }
  return (0);
}

int ft_flag_get_zero(char *str)
{
  unsigned int i;

  i = 0;
  while (str[i])
  {
    if (str[i] == '.')
      break;
    if (ft_isdigit(str[i]))
    {
      if (str[i] == '0')
        return (1);
      break;
    }
    i++;
  }
  return (0);
}