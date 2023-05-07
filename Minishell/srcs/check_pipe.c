/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:08:39 by bjimenez          #+#    #+#             */
/*   Updated: 2022/12/27 17:33:26 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_check_red_status(t_ms_data *ms_data)
{
	if (ms_data->redirection_status == 2 || ms_data->redirection_status == 3)
		close (ms_data->fd_blt);
	if (ms_data->redirection_status == 3 || ms_data->redirection_status == 1)
		close (ms_data->fd_in);
	ms_data->fd_blt = 1;
	ms_data->fd_in = 1;
	ms_data->redirection_status = 0;
}

int	ft_check_pipes(char *gnl, t_ms_data *ms_data)
{
	t_pipes_var	c_pip;

	c_pip.i = 0;
	c_pip.str = ft_strdup(gnl);
	c_pip.p = c_pip.str;
	while (*c_pip.p != '\0')
	{
		if (*c_pip.p == '|' && c_pip.i == 0)
		{
			c_pip.p++;
			if (*c_pip.p == '|' && (*c_pip.str == '|' || *(c_pip.p + 1) == '|'))
				return (free (c_pip.str), 2);
			else
				return (free (c_pip.str), 1);
		}
		else if (*c_pip.p == '|' && c_pip.i == 1)
			c_pip.i = 0;
		else if (ft_isalnum(*c_pip.p) != 0)
			c_pip.i = 1;
		c_pip.p++;
	}
	if (ft_strncmp(gnl, c_pip.str, ft_strlen(gnl)) != 0)
		ft_check_red_status(ms_data);
	ms_data->pipe = 1;
	return (free (c_pip.str), 0);
}
