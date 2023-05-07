/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_in_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 18:28:46 by bjimenez          #+#    #+#             */
/*   Updated: 2022/12/27 18:38:31 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_chk_red_pipe(char *p)
{
	int	i;

	i = 0;
	while (*p == '<')
	{
		p++;
		i++;
	}
	if (i > 3)
		return (1);
	while (*p != '\0' && *p != '<' && *p != '|')
	{
		if (ft_isalnum(*p) != 0 || *p == '/' || *p == '-' || *p == '_'
			|| *p == '$')
			return (0);
		p++;
	}
	return (1);
}

void	ft_while_redir(char *p, t_ms_data *ms_data)
{
	int	i;

	i = 0;
	while (*p == '<')
	{
		p++;
		i++;
	}
	return (ft_redirection_error_in(1, (i + 3), ms_data));
}

int	ft_check_redirection_in(char *p, t_ms_data *ms_data)
{
	int	i;

	i = 0;
	while (*p == '<')
	{
		p++;
		i++;
	}
	if (i > 3)
		return (ft_redirection_error_in(1, i, ms_data), 1);
	while (*p != '\0' && *p != '<' && *p != '|')
	{
		if (ft_isalnum(*p) != 0 || *p == '/' || *p == '-' || *p == '_'
			|| *p == '$')
			return (0);
		p++;
	}
	if (*p == '<')
		return (ft_while_redir(p, ms_data), 1);
	return (ft_redirection_error_in(2, i, ms_data), 1);
}

void	ft_infile_triple_redirection(char *str, t_ms_data *ms_data)
{
	ms_data->fd_in = open("temp", O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR
			| S_IRGRP | S_IWGRP | S_IROTH);
	ft_putstr_fd(str, ms_data->fd_in);
	ft_putstr_fd("\n", ms_data->fd_in);
	close(ms_data->fd_in);
}
