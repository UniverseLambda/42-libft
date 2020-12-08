/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdlib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 11:36:04 by clsaad            #+#    #+#             */
/*   Updated: 2020/12/08 11:36:05 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_STDLIB_H
# define _FT_STDLIB_H

# include <stddef.h>

int			ft_atoi(const char *nptr);
char		*ft_itoa(int n);
void		*ft_calloc(size_t nmemb, size_t size);

#endif
