/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 09:48:05 by bjacob            #+#    #+#             */
/*   Updated: 2020/11/27 15:10:48 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

static int		ft_strncmp(char *s1, char *s2, int n)
{
	int i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		else
			i++;
	}
	return (0);
}

int		c_in_s(char* s, char **charset)
{
	int i;
	int len;

	len = ft_strlen(charset[0]);
	i = 0;
	while (charset[i])
	{
		if (!ft_strncmp(charset[i], s, len))
			return (1);
		i++;
	}
	return (0);
}

int		next_sep(char *str, char **charset, int end)
{
	int len;

	len = 0;
	while (len < end && !c_in_s(str + len, charset))
		len++;
	return (len);
}

int		get_nb_words(char *str, char **charset, int end_str)
{
	int		i;
	int		nb_w;
	int 	new_w;

	i = 1;
	nb_w = 0;
	new_w = 1;
	if (!str[0])
		return (0);
	while (i < end_str)
	{
		if (c_in_s(str + i, charset))
		{
			i = i + ft_strlen(charset[0]);
			nb_w++;
		}
		i++;
	}
	return (nb_w);
}

char	*ft_malloc_ptr(int i, int *j, char *str, char **charset, int end_str)
{
	char	*ptr;
	int		len;

	len = next_sep(str + i, charset, end_str - i);
	if(!(ptr = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	*j = 0;
	while (*j < len)
	{
		ptr[*j] = str[i + *j];
		(*j)++;
	}
	ptr[(*j)] = '\0';
	return (ptr);
}

void	sep_str_in_tab(char *str, char **charset, char ***str_tab, int *j, int end_str, int **len_w)
{
	int		i;
	char	*ptr;
	int		new_w;
	int		i_words;

	new_w = 1;
	i = 0;
	i_words = 0;
	while (i < end_str)
	{
		if (!c_in_s(str + i, charset))
		{
			ptr = ft_malloc_ptr(i, j, str, charset, end_str);
			new_w = 0;
			i = i + *j;
			(*len_w)[i_words] = *j;
			(*str_tab)[i_words++] = ptr;
		}
		else if (c_in_s(str + i, charset))
		{			
			i = i + ft_strlen(charset[0]);
			new_w = 1;
		}
	}
}

char	**ft_split(char *str, char **charset, int end_str, int **len_w)
{
	char	**str_tab;
	int		nb_w;
	int		*j;
	int		i;

	i = 0;
	j = &i;
	str_tab = 0;
	nb_w = get_nb_words(str, charset, end_str);
	if (nb_w == 0)
	{
		str_tab = malloc(sizeof(char*));
		str_tab[0] = 0;
		return (str_tab);
	}
	*len_w = malloc(sizeof(int) * (2 * nb_w + 1));
	str_tab = malloc(sizeof(char*) * (nb_w + 1));
	sep_str_in_tab(str, charset, &str_tab, j, end_str, len_w);
	str_tab[nb_w] = 0;
	return (str_tab);
}
