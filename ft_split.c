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

static size_t	get_array_size(const char *s, char c)
{
	size_t size;
	size_t index;

	size = 1;
	index = 0;
	while (s[index] != 0)
	{
		if (s[index] == c)
		{
			if (index != 0 && s[index - 1] != c)
			{
				++size;
			}
		}
		++index;
	}
	return (size + 1);
}

static size_t	get_string(const char *s, char c, char **dest)
{
	size_t	end;

	end = 0;
	while (s[end] != 0)
	{
		if (s[end] == c)
		{
			break ;
		}
		++end;
	}
	*dest = malloc(end);
	if (*dest == NULL)
		return (0);
	ft_strlcpy(*dest, s, end + 1);
	return (end);
}

static void		split_abort_on_error(char **array)
{
	size_t index;

	index = 0;
	while (array[index] != NULL)
	{
		free(array[index]);
		++index;
	}
	free(array);
}

char			**ft_split(const char *s, char c)
{
	size_t	array_size;
	char	**array;
	size_t	array_index;
	size_t	s_index;

	array_size = get_array_size(s, c);
	array = ft_calloc(array_size, sizeof(char *));
	array_index = 0;
	s_index = 0;
	if (array != NULL)
		while (s[s_index] != 0)
		{
			if (s[s_index] != c)
			{
				s_index += get_string(s + s_index, c, array + array_index) - 1;
				if (array[array_index] == NULL)
				{
					split_abort_on_error(array);
					return (NULL);
				}
				++array_index;
			}
			++s_index;
		}
	return (array);
}
