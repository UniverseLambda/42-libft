/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdio.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 14:39:45 by clsaad            #+#    #+#             */
/*   Updated: 2020/11/27 14:39:46 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_STDIO_H
# define _FT_STDIO_H

# include <stdarg.h>

int ft_printf(const char *fmt, ...) __attribute__((__format__(__printf__,1,2)));
int ft_vprintf(
	const char *fmt, va_list args) __attribute__((__format__(__printf__,1,0)));

#endif
