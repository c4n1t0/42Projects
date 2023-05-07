/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_prepare.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 20:14:01 by jaromero          #+#    #+#             */
/*   Updated: 2022/12/18 09:08:58 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_redirecions_exec(t_ms_data *ms_data, char **split, char *gnl)
{
	if (ms_data->redirection_status == 3)
		ft_inoutfile_arg(split, ms_data);
	else if (ms_data->redirection_status == 2)
		ft_outfile_arg(gnl, ms_data);
	else if (ms_data->redirection_status == 1)
		ft_infile_arg(gnl, ms_data);
}

char	*ft_loop_redirc_out(char *gnl, t_ms_data *ms_data)
{
	while (ft_strchr_pipes(gnl, '>') != 0)
	{
		gnl = ft_remove_redirection_out(gnl, ms_data);
		if (gnl == NULL)
			return (NULL);
	}
	if (*gnl == '\0')
		return (NULL);
	return (gnl);
}

char	*ft_loop_redirc_in(char *gnl, t_ms_data *ms_data)
{
	while (ft_strchr_pipes(gnl, '<') != 0)
	{
		gnl = ft_remove_redirection_in(gnl, ms_data);
		if (gnl == NULL)
			return (NULL);
	}
	if (*gnl == '\0')
		return (NULL);
	return (gnl);
}

char	*ft_redirections_prepare(char *gnl, t_ms_data *ms_data)
{
	if (ft_strchr_pipes(gnl, '>') != 0 && ft_strchr_pipes(gnl, '<') != 0)
		ms_data->redirection_status = 3;
	if (ft_strchr_pipes(gnl, '>') != 0)
	{
		if (ms_data->redirection_status == 0)
			ms_data->redirection_status = 2;
		gnl = ft_loop_redirc_out(gnl, ms_data);
		if (!gnl)
			return (NULL);
	}
	if (ft_strchr_pipes(gnl, '<') != 0)
	{
		if (ms_data->redirection_status == 0)
			ms_data->redirection_status = 1;
		gnl = ft_loop_redirc_in(gnl, ms_data);
		if (!gnl)
			return (NULL);
	}
	return (gnl);
}
