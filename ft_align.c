/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_align.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <ezemango@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 22:38:32 by jolim             #+#    #+#             */
/*   Updated: 2020/11/01 12:51:37 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_make_pad(int len, char c)
{
	char	*pad;

	if (!(pad = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	ft_memset(pad, c, len);
	pad[len] = '\0';
	return (pad);
}

char		*ft_pad_zero(char *num, int padlen)
{
	char	*pad;
	char	*ret;

	if (padlen <= 0)
		return (num);
	if (!(pad = ft_make_pad(padlen, '0')))
		return (NULL);
	ret = ft_strjoin(pad, num);
	free(pad);
	free(num);
	return (ret);
}

char		*ft_align_left(char *num, int padlen)
{
	char *pad;
	char *ret;

	if (padlen <= 0)
		return (num);
	if (!(pad = ft_make_pad(padlen, ' ')))
		return (NULL);
	ret = ft_strjoin(num, pad);
	free(pad);
	free(num);
	return (ret);
}

char		*ft_align_right(char *num, int padlen)
{
	char	*pad;
	char	*ret;

	if (padlen <= 0)
		return (num);
	if (!(pad = ft_make_pad(padlen, ' ')))
		return (NULL);
	ret = ft_strjoin(pad, num);
	free(pad);
	free(num);
	pad = ret;
	return (ret);
}
