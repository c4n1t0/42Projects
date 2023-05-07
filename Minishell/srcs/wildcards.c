/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcards.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 20:58:05 by jaromero          #+#    #+#             */
/*   Updated: 2022/12/20 20:56:06 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*ft_initwld_data(t_wld_data *wld, char *gnl)
{
	wld->wld_aux = NULL;
	wld->p = ft_split_pipe(gnl, ' ');
	wld->wld = (char **)malloc(sizeof(char *) * ft_array_size(wld->p) + 1);
	if (!wld->wld)
		return (NULL);
	wld->wld_mode = (int *)malloc(sizeof(int) * ft_array_size(wld->p));
	if (!wld->wld_mode)
		return (NULL);
	return (0);
}

void	*ft_one_wld(t_wld_data *wld, int i)
{
	if (*wld->q == *wld->p[i])
	{
		wld->q++;
		wld->wld[i] = ft_strdup(wld->q);
		wld->wld_mode[i] = 1;
	}
	else if (*wld->q == wld->p[i][ft_strlen(wld->p[i]) - 1])
	{
		wld->wld[i] = malloc (sizeof(char) * (ft_strlen(wld->p[i]) - 1));
		if (!wld->wld[i])
			return (NULL);
		ft_memcpy(wld->wld[i], wld->p[i], ft_strlen(wld->p[i]) - 1);
		wld->wld[i][ft_strlen(wld->p[i]) - 1] = '\0';
		wld->wld_mode[i] = 2;
	}
	else
	{
		wld->wld[i] = ft_strdup(wld->p[i]);
		wld->wld_mode[i] = 3;
	}
	return (0);
}

void	ft_more_wld(t_wld_data *wld, int i)
{
	wld->wld[i] = ft_strdup(wld->p[i]);
	wld->wld_mode[i] = 4;
}

void	ft_no_wld(t_wld_data *wld, int i)
{
	wld->wld_mode[i] = 0;
	wld->wld[i] = ft_strdup(wld->p[i]);
}

char	*ft_change_wildcard(char *gnl)
{
	t_wld_data	wld;
	int			i;

	ft_initwld_data(&wld, gnl);
	i = 0;
	while (wld.p[i] != NULL)
	{
		if (ft_strchr_pipes(wld.p[i], '*'))
		{
			wld.q = ft_newstrchr(wld.p[i], '*');
			if (ft_n_wld(wld.p[i]) == 1)
				ft_one_wld(&wld, i);
			else
				ft_more_wld(&wld, i);
		}
		else
			ft_no_wld(&wld, i);
		i++;
	}
	wld.wld[i] = NULL;
	gnl = ft_checkdir(wld.wld, gnl, wld.wld_mode, wld.p);
	free_split(wld.p);
	free_split (wld.wld);
	free (wld.wld_mode);
	return (gnl);
}
