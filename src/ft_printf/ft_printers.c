/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 09:54:42 by clsaad            #+#    #+#             */
/*   Updated: 2020/12/03 09:54:43 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include <ft_stdio.h>
#include <ft_parser.h>
#include <libft.h>

void		wrc(char c)
{
	ft_putchar_fd(c, STDOUT_FILENO);
}

int			ft_fill(char filler, ssize_t len)
{
	int count;

	count = 0;
	while (count < len)
	{
		wrc(filler);
		++count;
	}
	return (count);
}

int			ft_printf_char(unsigned char c, t_parsing_result res)
{
	int	count;

	count = 1;
	while (!(res.flags & F_MINUS) && res.width > 1)
	{
		wrc(((res.flags & F_ZERO) && (res.type == '%')) ? '0' : ' ');
		--(res.width);
		++count;
	}
	wrc(c);
	while ((res.flags & F_MINUS) && res.width > 1)
	{
		wrc(' ');
		--(res.width);
		++count;
	}
	return (count);
}

int			ft_printf_str(char *str, t_parsing_result res)
{
	ssize_t	len;
	int		count;

	if (str == NULL)
		str = "(null)";
	count = 0;
	len = ft_strlen(str);
	if ((len > res.precision) && (res.flags & F_PRECISION))
		len = res.precision;
	while (!(res.flags & F_MINUS) && (count + len < res.width))
	{
		ft_putchar_fd((res.flags & F_ZERO) ? '0' : ' ', STDOUT_FILENO);
		++count;
	}
	write(STDOUT_FILENO, str, len);
	while ((res.flags & F_MINUS) && (count + len < res.width))
	{
		ft_putchar_fd((res.flags & F_ZERO) ? '0' : ' ', STDOUT_FILENO);
		++count;
	}
	count += len;
	return (count);
}
