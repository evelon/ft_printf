/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <ezemango@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 19:54:58 by jolim             #+#    #+#             */
/*   Updated: 2020/11/01 13:01:21 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_p_str(t_spec *spec, va_list *ap)
{
	char	*str;
	int		count;

	if (!(str = ft_strdup(va_arg(*ap, char *))))
		str = ft_strdup("(null)");
	if (spec->f_dot && ft_strlen(str) > spec->precision)
		str[spec->precision] = '\0';
	if (spec->f_hyphen)
		str = ft_align_left(str, spec->width - ft_strlen(str));
	else if (spec->f_zero)
		str = ft_pad_zero(str, spec->width - ft_strlen(str));
	else
		str = ft_align_right(str, spec->width - ft_strlen(str));
	count = ft_print_stdout(str);
	free(str);
	return (count);
}
