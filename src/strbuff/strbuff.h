/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strbuff.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 12:35:40 by clsaad            #+#    #+#             */
/*   Updated: 2020/12/08 12:35:40 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef _STRBUFF_H
# define _STRBUFF_H

# include <stddef.h>

# include <ft_strbuff.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

typedef struct		s_bblock
{
	struct s_bblock	*next;
	char			data[BUFFER_SIZE];
}					t_bblock;

typedef struct		s_buff
{
	size_t			content_size;
	size_t			buff_size;
	t_bblock		block;
}					t_buff;

#endif
