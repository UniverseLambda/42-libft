/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clsaad <clsaad@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 10:08:48 by clsaad            #+#    #+#             */
/*   Updated: 2020/11/26 10:08:48 by clsaad           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

static unsigned int	ft_count_delimited(char const *string, char sep)
{
	char			previous_is_sep;
	unsigned int	seg_count;
	unsigned int	i;

	i = 0;
	seg_count = 0;
	previous_is_sep = -1;
	while (string[i])
		if (string[i++] == sep)
		{
			if (!previous_is_sep && i != 0)
				++seg_count;
			previous_is_sep = 1;
		}
		else
			previous_is_sep = 0;
	seg_count += (previous_is_sep == 0) ? 1 : 0;
	return (seg_count);
}

static int			ft_split_core(char ***tab, char const *s, char c)
{
	unsigned int	sub_str_lenght;
	unsigned int	i;

	i = 0;
	if (!(*tab = ft_calloc((ft_count_delimited(s, c) + 1), sizeof(char *))))
		return (0);
	while (s != NULL && *s != 0)
		if (*s != c)
		{
			sub_str_lenght = 0;
			while (*s != c && *s != 0)
			{
				sub_str_lenght++;
				s++;
			}
			if (!((*tab)[i] = ft_calloc((sub_str_lenght + 1), sizeof(char))))
				return (0);
			ft_strlcpy((*tab)[i++], s - sub_str_lenght, (sub_str_lenght + 1));
		}
		else
			s++;
	(*tab)[i] = NULL;
	return (1);
}

char				**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;

	tab = NULL;
	if (!ft_split_core(&tab, s, c))
	{
		if (tab != NULL)
		{
			i = 0;
			while (tab[i] != NULL || tab[i] != 0)
				free(tab[i++]);
			free(tab);
		}
		return (NULL);
	}
	return (tab);
}
