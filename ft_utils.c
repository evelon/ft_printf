/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <ezemango@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 16:23:19 by jolim             #+#    #+#             */
/*   Updated: 2020/11/01 19:28:38 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strlen(const char *s)
{
	const char	*eos;

	eos = s;
	while (*eos++)
		;
	return (eos - s - 1);
}

void	*ft_memset(void *b, char c, int len)
{
	int	p;

	p = 0;
	while (p < len)
	{
		*((unsigned char *)b + p) = (unsigned char)c;
		p++;
	}
	return (b);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		len;
	int		p;

	if (s1 == NULL)
		return (NULL);
	len = ft_strlen(s1);
	if (!(s2 = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	p = 0;
	while (p <= len)
	{
		*(s2 + p) = *(s1 + p);
		p++;
	}
	return (s2);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		len1;
	int		len2;
	int		p;
	char	*new;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(new = (char *)malloc((len1 + len2 + 1) * sizeof(char))))
		return (NULL);
	p = 0;
	while (p < len1)
	{
		*(new + p) = *(s1 + p);
		p++;
	}
	p = 0;
	while (p < len2)
	{
		*(new + len1 + p) = *(s2 + p);
		p++;
	}
	*(new + len1 + p) = '\0';
	return (new);
}
