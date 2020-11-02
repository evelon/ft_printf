/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <ezemango@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 10:34:42 by jolim             #+#    #+#             */
/*   Updated: 2020/11/01 18:52:52 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_spec	*ft_set_spec(void)
{
	t_spec *spec;

	if (!(spec = (t_spec *)malloc(1 * sizeof(t_spec))))
		return (NULL);
	spec->f_hyphen = 0;
	spec->f_dot = 0;
	spec->f_zero = 0;
	spec->width = 0;
	spec->precision = 0;
	spec->sp = '\0';
	return (spec);
}
