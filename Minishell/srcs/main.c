/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 23:42:59 by jaromero          #+#    #+#             */
/*   Updated: 2022/12/27 20:05:47 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_quote_red(char *gnl)
{
	char	**split;
	int		i;

	i = -1;
	split = ft_split(gnl, ' ');
	while (split[++i])
	{
		if (ft_strstr(split[i], "<<"))
		{	
			if (*split[i] != '"')
			{	
				free_split(split);
				return (0);
			}
		}
	}
	free_split(split);
	return (1);
}

void	ft_one_execute(t_ms_data *ms_data, char *gnl, char *argv)
{
	ms_data->v_exit = ft_itoa(0);
	gnl = ft_strdup(argv);
	if (gnl)
	{
		if (*gnl == ' ' || *gnl == '\t' || *gnl == '\n')
			gnl = ft_delete_spaces(gnl);
	}
	if (gnl && *gnl != '\0')
		ft_analytics(gnl, ms_data);
	exit(ft_atoi(ms_data->v_exit));
}

void	ft_minishell_engine(char *gnl, t_ms_data *ms_data)
{
	while (gnl)
	{
		gnl = readline("yogurdelimon🍋@42School🖥️  $>");
		if (gnl != NULL)
		{
			if (*gnl == ' ' || *gnl == '\t' || *gnl == '\n')
				gnl = ft_delete_spaces(gnl);
		}
		else
		{
			free (gnl);
			ms_data->ext = ft_atoi(ms_data->v_exit);
			free(ms_data->v_exit);
			exit(ms_data->ext);
		}
		if (gnl && *gnl != '\0')
		{
			if (ft_quote_red(gnl))
				add_history(gnl);
			ft_analytics(gnl, ms_data);
		}	
		else
			free (gnl);
	}	
}

int	main(int argc, char **argv, char **envp)
{
	char				*gnl;
	t_ms_data			ms_data;

	(void)argc;
	g_ms_data = &ms_data;
	gnl = argv[0];
	ms_data.act_folder = malloc(1);
	if (!ms_data.act_folder)
		return (0);
	g_ms_data->pid_pr = 0;
	ft_save_envp_global(envp);
	signal(SIGINT, ft_act_signals);
	signal(SIGQUIT, SIG_IGN);
	if (argc != 1 && ft_strnstr(argv[1], "-c", 3) != NULL && argv[2])
		ft_one_execute(&ms_data, gnl, argv[2]);
	else
	{
		ft_printf("\nWelcome to HardCore mode!!\n");
		ms_data.v_exit = ft_itoa(0);
		ft_minishell_engine(gnl, &ms_data);
	}
	return (0);
}
