/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolim <ezemango@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 20:02:09 by jolim             #+#    #+#             */
/*   Updated: 2020/11/01 18:53:49 by jolim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>

typedef struct	s_spec
{
	int			f_hyphen;
	int			f_zero;
	int			f_dot;
	int			width;
	int			precision;
	char		sp;
}				t_spec;

int				ft_printf(const char *format, ...);
int				ft_print_stdout(char *str);

t_spec			*ft_read_spec(char **c, va_list *ap);

char			*ft_pad_zero(char *num, int	padlen);
char			*ft_align_left(char *num, int padlen);
char			*ft_align_right(char *num, int padlen);

t_spec			*ft_set_spec(void);

char			*ft_dtoa(int i);
char			*ft_utoa(unsigned int i);
char			*ft_xtoa(unsigned long long i, char x);

int				ft_p_char(t_spec *spec, va_list *ap);
int				ft_p_str(t_spec *spec, va_list *ap);
int				ft_p_dec(t_spec *spec, va_list *ap);
int				ft_p_unsigned(t_spec *spec, va_list *ap);
int				ft_p_hex(t_spec *spec, va_list *ap);
int				ft_p_ptr(t_spec *spec, va_list *ap);

char			*ft_strjoin(char *s1, char *s2);
int				ft_strlen(const char *s);
void			*ft_memset(void *b, char c, int len);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(char *s1, char *s2);

#endif
