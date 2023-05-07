/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_env_0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:03:09 by jaromero          #+#    #+#             */
/*   Updated: 2022/12/21 11:34:33 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_search_var_env_init(char *p)
{
	int		i;
	char	*q;
	char	*ptr;

	i = 0;
	if (ft_strchr(p, '"'))
	{
		ptr = ft_strchr(p, '"');
		if (ptr)
			*ptr = '\0';
	}
	p = ft_free_and_join(p, "=");
	while (g_ms_data->envp[i] != NULL)
	{
		if (ft_strnstr(g_ms_data->envp[i], p, ft_strlen(p) + 1) != NULL)
		{
			q = g_ms_data->envp[i];
			while (*q != '=')
				q++;
			q++;
			return (free (p), q);
		}
		i++;
	}
	return (free (p), NULL);
}

void	ft_sub_subchange_var(t_change_var *var)
{
	var->status = 0;
	var->i = 0;
	var->q++;
	while ((ft_isalnum(*var->q) != 0 && *var->q != ' ') || *var->q == '?'
		|| (*var->q == '_' && *var->q != '\0'))
		var->q++;
	while (var->p != var->q)
	{
		var->str[var->i] = *var->p;
		var->i++;
		var->p++;
	}
	var->str[var->i] = '\0';
}

char	*ft_subchange_var(char *gnl, t_ms_data *ms_data)
{
	t_change_var	var;

	var.p = ft_strchr_var(gnl, '$');
	if (ft_strncmp(var.p, "$?", 2) != 0)
		var.p++;
	var.str = ft_calloc((ft_strlen(var.p) + 1), sizeof(char *));
	var.q = var.p;
	ft_sub_subchange_var(&var);
	if (ft_strncmp(var.str, "$?", 1) == 0)
	{
		free (var.str);
		var.str = ft_strdup(ms_data->v_exit);
		var.status = 1;
	}
	else
		var.str = ft_search_var_env_init(var.str);
	if (!var.str)
		return (free(var.str), NULL);
	var.p = ft_strchr_var(gnl, '$');
	*var.p = '\0';
	var.p = ft_strjoin(gnl, var.str);
	var.p = ft_free_and_join(var.p, var.q);
	if (var.status == 1)
		free (var.str);
	return (free (gnl), var.p);
}

char	*ft_delete_var(char	*gnl)
{
	char	*p;
	char	*q;

	p = ft_strchr(gnl, '$');
	q = p;
	while ((ft_isalnum(*q) != 0 && *q != ' ') || *q == '$' || *q == '?'
		|| (*q == '_' && *q != '\0'))
		q++;
	while (*q != '\0')
	{
		*p = *q;
		p++;
		q++;
	}
	*p = '\0';
	return (gnl);
}

char	*ft_change_var(char *gnl, t_ms_data *ms_data)
{
	char	*p;

	while (ft_strchr_var(gnl, '$') != 0)
	{
		p = ft_strchr_var(gnl, '$');
		p = ft_subchange_var(gnl, ms_data);
		if (p)
		{
			gnl = ft_strdup(p);
			free (p);
		}
		else
			gnl = ft_delete_var(gnl);
	}
	return (gnl);
}
