/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <ezemango@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 19:58:56 by jolim             #+#    #+#             */
/*   Updated: 2020/11/01 19:17:33 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_stdout(char *str)
{
	int	count;
	int	len;

	count = 0;
	if (str == NULL)
	{
		count += write(1, "(null)", 6);
		return (count);
	}
	len = ft_strlen(str);
	count += write(1, str, len);
	return (count);
}

int	ft_route_sp(t_spec *spec, va_list *ap)
{
	int	ret;

	ret = 0;
	if (spec->sp == 'c' || spec->sp == '%')
		ret = ft_p_char(spec, ap);
	else if (spec->sp == 's')
		ret = ft_p_str(spec, ap);
	else if (spec->sp == 'd' || spec->sp == 'i')
		ret = ft_p_dec(spec, ap);
	else if (spec->sp == 'x' || spec->sp == 'X')
		ret = ft_p_hex(spec, ap);
	else if (spec->sp == 'p')
		ret = ft_p_ptr(spec, ap);
	else if (spec->sp == 'u')
		ret = ft_p_unsigned(spec, ap);
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	t_spec	*spec;
	char	*fmt;
	int		count;
	int		p;

	va_start(ap, format);
	fmt = (char *)format;
	p = 0;
	count = 0;
	while (*(fmt + p))
	{
		if (*(fmt + p) == '%')
		{
			count += write(1, fmt, p);
			fmt += p + 1;
			spec = ft_read_spec(&(fmt), &ap);
			count += ft_route_sp(spec, &ap);
			free(spec);
			p = -1;
		}
		p++;
	}
	count += write(1, fmt, p);
	va_end(ap);
	return (count);
}
