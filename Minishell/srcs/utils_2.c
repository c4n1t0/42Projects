/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:30:53 by jaromero          #+#    #+#             */
/*   Updated: 2022/12/27 18:34:21 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_redir_look(char *s, char *p)
{
	char	*q;

	q = p;
	while (*q != '\0')
	{
		if (*q == '<')
		{
			q++;
			while ((*q == ' ' && *q != '\0') || (*q == '"' && *q != '\0'))
				q++;
			if (q == s)
				return (1);
		}
		else
			q++;
	}
	return (0);
}

char	*ft_strchr_var(const char *s, int c)
{
	char	*p;

	p = (char *)s;
	while (*s != '\0')
	{
		if (*s == (char)c && (ft_quote_pipe(p, (char *)s) == 0
				|| (ft_quote_pipe(p, (char *)s) == 1)))
		{
			if ((ft_isalnum(*(s + 1)) != 0 || *(s + 1) == '_' || *(s + 1)
					== '?') && ft_redir_look((char *)s, p) == 0)
				return ((char *)s);
			else
				s++;
		}
		else
			s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

char	*ft_strchr_pipes(const char *s, int c)
{
	char	*p;

	p = (char *)s;
	while (*s != '\0')
	{
		if (*s == (char)c && ft_quote_pipe(p, (char *)s) == 0)
			return ((char *)s);
		else
			s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

static char	**ft_distrib(char *tmp, unsigned int len, int word)
{
	char			**aux;
	unsigned int	i;
	unsigned int	j;

	aux = (char **)malloc(sizeof(char *) * (word + 1));
	if (aux == 0)
		return (0);
	i = 0;
	j = 0;
	if (tmp[i] != '\0')
	{
		aux[j] = ft_strdup(&tmp[i]);
		j++;
	}
	i++;
	while (i < len)
	{
		if (tmp[i] != '\0' && tmp[i - 1] == '\0')
		{
			aux[j++] = ft_strdup(&tmp[i]);
		}
		i++;
	}
	aux[j] = 0;
	return (aux);
}

char	**ft_split_pipe(char const *s, char c)
{
	unsigned int	len;
	char			*p;
	int				word;
	char			*tmp;
	char			**aux;

	len = ft_strlen(s) + 1;
	tmp = ft_strdup(s);
	if (tmp == 0)
		return (0);
	word = 0;
	p = tmp;
	while (--len > 0)
	{
		if (*p == c
			&& ft_quote_pipe((char *)s, (char *)&s[ft_strlen(s) - len]) == 0)
			*p = '\0';
		else if (word == 0 || *(p - 1) == '\0')
			word++;
		p++;
	}
	aux = ft_distrib(tmp, ft_strlen(s), word);
	free(tmp);
	return (aux);
}
