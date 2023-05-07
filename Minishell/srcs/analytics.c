/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analytics.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 09:36:47 by bjimenez          #+#    #+#             */
/*   Updated: 2022/12/27 19:05:30 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_builtins(char **split, t_ms_data *ms_data)
{
	if (ft_strncmp(split[0], "echo", (ft_strlen(split[0]) + 1)) == 0)
		ft_echo(split, g_ms_data->envp, ms_data);
	else if (ft_strncmp(split[0], "cd", (ft_strlen(split[0]) + 1)) == 0)
		ft_cd(ms_data, split[1]);
	else if (ft_strncmp(split[0], "pwd", (ft_strlen(split[0]) + 1)) == 0)
		ft_pwd(ms_data);
	else if (ft_strncmp(split[0], "export", (ft_strlen(split[0]) + 1)) == 0)
		ft_export(split, ms_data);
	else if (ft_strncmp(split[0], "unset", (ft_strlen(split[0]) + 1)) == 0)
		ft_unset(split, g_ms_data->envp, ms_data);
	else if (ft_strncmp(split[0], "env", (ft_strlen(split[0]) + 1)) == 0)
		ft_print_env(g_ms_data->envp, ms_data);
	else if (ft_strncmp(split[0], "exit", (ft_strlen(split[0]) + 1)) == 0)
		ft_exit(split, ms_data);
	else
		return (0);
	return (1);
}

int	ft_pipe_error_detected(char *gnl, t_ms_data *ms_data)
{
	if (ft_check_pipes(gnl, ms_data) == 1)
	{
		ft_putstr_fd("minishell: syntax error near unexpected token `|'\n", 2);
		ft_signal_cmd(258, ms_data);
		return (1);
	}
	if (ft_check_pipes(gnl, ms_data) == 2)
	{
		ft_putstr_fd("minishell: syntax error near unexpected token `||'\n", 2);
		ft_signal_cmd(258, ms_data);
		return (1);
	}
	return (0);
}

char	*ft_pipe_detected(char *gnl, t_ms_data *ms_data, char **split)
{
	if (ft_pipe_error_detected(gnl, ms_data))
		return (gnl);
	split = ft_split_pipe(gnl, '|');
	ms_data->n_f = ft_array_size(split);
	if (ft_array_size(split) < 2)
		ft_signal_cmd(2, ms_data);
	else
	{
		if (ft_detec_dr(gnl) && ft_chk_red_pipe(ft_strchr_pipes(gnl, '<')) == 0)
		{
			if (ft_heredoc_pipe(ms_data, gnl))
				return (free (gnl), free_split(split),
					free(ms_data->infile), NULL);
			ft_prepare_dred_in(gnl, ms_data);
			gnl = ft_dred_file(gnl, ms_data);
		}
		if (ms_data->status_sig == 0)
			split = ft_free_and_split_pipe(split, gnl);
		else
			return (free_split (split), NULL);
	}
	ft_pipes(split, g_ms_data->envp, ms_data);
	ft_change_last_exec(split[ms_data->n_f - 1], ms_data, 1);
	return (free_split(split), gnl);
}

char	*ft_simple_exec(char *gnl, t_ms_data *ms_data, char **split)
{
	gnl = ft_redirections_prepare(gnl, ms_data);
	if (!gnl || ft_check_gnl(gnl) == 0)
		return (free (gnl), NULL);
	split = ft_split_pipe(gnl, ' ');
	split = ft_parse_quote(split);
	if (ft_array_size(split) == 1)
	{
		free_split(split);
		split = ft_split(gnl, '\t');
	}
	ms_data->n_f = ft_array_size(split);
	ft_change_last_exec(split[ms_data->n_f - 1], ms_data, 0);
	if (ft_builtins(split, ms_data) == 1)
		return (free_split(split), gnl);
	if (ms_data->redirection_status != 0)
		ft_redirecions_exec(ms_data, split, gnl);
	else if (gnl)
		ft_exc_rest(gnl, g_ms_data->envp, ms_data);
	free_split(split);
	return (gnl);
}

void	ft_analytics(char *gnl, t_ms_data *ms_data)
{
	char	**split;
	char	*temp;

	split = NULL;
	ft_init_value_redirection(ms_data);
	gnl = ft_change_var(gnl, ms_data);
	if (ft_strchr_pipes(gnl, '*') != 0)
		gnl = ft_change_wildcard(gnl);
	temp = ft_strtrim(gnl, "\n");
	free(gnl);
	gnl = ft_strtrim(temp, " ");
	free(temp);
	if (ft_strchr_pipes(gnl, '|') != 0)
		gnl = ft_pipe_detected(gnl, ms_data, split);
	else
		gnl = ft_simple_exec(gnl, ms_data, split);
	if (access("temp", F_OK) != -1)
		unlink("temp");
	ms_data->status_path = 0;
	free(gnl);
}
