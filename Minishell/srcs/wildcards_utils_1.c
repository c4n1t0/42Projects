/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcards_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 19:21:12 by bjimenez          #+#    #+#             */
/*   Updated: 2022/12/20 10:30:23 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_n_wld(char *target)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (target[i] != '\0')
	{	
		if (target[i] == '*')
			j++;
		i++;
	}
	return (j);
}

char	*ft_newstrchr(char *p, int c)
{
	char	*s;

	s = p;
	while (*s != '\0')
	{
		if (*s == (char)c)
			return (s);
		else
			s++;
	}
	if (*s == (char)c)
		return (s);
	return (NULL);
}

char	*ft_n_punt(char *d_name, int size_wld)
{
	char	*np;
	int		nsize;

	np = d_name;
	nsize = (ft_strlen(d_name) - size_wld);
	return (np + nsize);
}

int	ft_checktype3(char *wld, char *d_name)
{
	int	i;
	int	j;

	i = 0;
	while (wld [i] == d_name [i])
		i++;
	if (wld[i] != '*')
		return (0);
	i = ft_strlen(d_name) - 1;
	j = ft_strlen(wld) - 1;
	while (wld[j] == d_name[i--])
		j--;
	if (wld[j] != '*')
		return (0);
	return (1);
}

int	ft_checktype4(char *wld, char *d_name)
{
	char	**d_wld;
	char	*p;
	char	*q;

	q = wld;
	p = d_name;
	if (wld[ft_strlen(wld) - 1] != '*')
	{
		q = ft_strrchr(q, '*');
		q++;
		p = d_name + (ft_strlen(p) - ft_strlen(q));
		if (ft_strncmp(q, p, ft_strlen(q)))
			return (0);
	}
	d_wld = ft_split(wld, '*');
	if (ft_check_wld(d_wld, d_name) == 0)
		return (free_split(d_wld), 0);
	free_split(d_wld);
	return (1);
}
