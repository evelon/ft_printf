/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <ezemango@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 18:38:32 by jolim             #+#    #+#             */
/*   Updated: 2020/11/01 18:50:32 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_null_left(char *c, int len)
{
	int count;

	free(c);
	if (len == 0)
		len++;
	if (!(c = (char *)malloc(len * sizeof(char))))
		return (0);
	ft_memset(c, ' ', len);
	c[0] = '\0';
	count = write(1, c, len);
	return (count);
}

int			ft_p_char(t_spec *spec, va_list *ap)
{
	char	*c;
	int		count;

	count = 0;
	if (!(c = (char *)malloc(2 * sizeof(char))))
		return (0);
	if (spec->sp == '%')
		*c = '%';
	else
		*c = (char)va_arg(*ap, int);
	if (c[0] == '\0' && spec->f_hyphen)
		return (ft_null_left(c, spec->width));
	c[1] = '\0';
	if (spec->width == 0)
		spec->width++;
	if (spec->f_hyphen)
		c = ft_align_left(c, spec->width - 1);
	else if (spec->f_zero)
		c = ft_pad_zero(c, spec->width - 1);
	else
		c = ft_align_right(c, spec->width - 1);
	count += write(1, c, spec->width);
	free(c);
	return (count);
}
