/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvenita <wvenita@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 01:50:53 by wvenita           #+#    #+#             */
/*   Updated: 2020/02/24 01:51:32 by wvenita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_str_insert(char *str, char c, int index)
{
  char *tmp;
  char *output;

  if (str == NULL)
    return (NULL);
  tmp = (char *)ft_memalloc((index + 2) * sizeof(*tmp));
  if (tmp == NULL)
    return (NULL);
  ft_strncpy(tmp, str, index);
  tmp[index] = c;
  tmp[index + 1] = '\0';
  output = ft_strjoin(tmp, str + index);
  free(tmp);
  tmp = NULL;
  free(str);
  str = NULL;
  return (output);
}