/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 23:35:48 by jaromero          #+#    #+#             */
/*   Updated: 2022/12/21 11:30:09 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_sub_unset(char **aux, char **envp, char **split, int x)
{
	int	i;
	int	y;
	int	z;

	z = ft_array_size(envp) - 1;
	aux = malloc(sizeof(char *) * ft_array_size(envp));
	if (!aux)
		return (NULL);
	i = 0;
	y = 0;
	while (z > 0)
	{
		if (ft_strnstr(envp[i], split[x], ft_strlen(split[x])) == NULL)
		{
			aux[y] = malloc(sizeof(char) * (ft_strlen(envp[i]) + 1));
			if (!aux[y])
				return (NULL);
			ft_strlcpy(aux[y], envp[i], (ft_strlen(envp[i]) + 1));
			z--;
			y++;
		}
		i++;
	}
	aux[y] = 0;
	return (aux);
}

char	**ft_unset_var(char **split, int x, char **envp)
{
	int		i;
	char	**aux;

	i = 0;
	aux = 0;
	if (ft_strchr(split[x], '=') == 0)
		split[x] = ft_free_and_join(split[x], "=");
	while (envp[i])
	{
		if (ft_strnstr(envp[i], split[x], ft_strlen(split[x])) != NULL)
		{
			aux = ft_sub_unset(aux, envp, split, x);
			free_split(envp);
			return (aux);
		}
		i++;
	}
	return (envp);
}

int	ft_check_var(char *split)
{
	char	*p;

	p = split;
	if (*split != '_' && ft_isalpha(*split) == 0)
		return (1);
	while (*p != '\0')
	{
		if (*p != '_' && ft_isalnum(*p) == 0)
			return (1);
		p++;
	}
	return (0);
}

char	**ft_unset(char **split, char **envp, t_ms_data *ms_data)
{
	int	i;
	int	x;

	(void)envp;
	i = 1;
	x = 0;
	while (split[i])
	{
		if (ft_check_var(split[i]) == 1)
		{
			ft_putstr_fd("minishell: unset: `", 2);
			ft_putstr_fd(split[i], 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
			ft_signal_cmd(1, ms_data);
			x = 1;
		}
		else
		{
			g_ms_data->envp = ft_unset_var(split, i, g_ms_data->envp);
			if (x == 0)
				ft_signal_cmd(0, ms_data);
		}
		i++;
	}
	return (g_ms_data->envp);
}
