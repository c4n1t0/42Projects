/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 09:25:51 by jaromero          #+#    #+#             */
/*   Updated: 2022/12/27 19:05:40 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_free_and_join(char *instr, char *str)
{
	char	*temp;

	temp = ft_strjoin(instr, str);
	free(instr);
	return (temp);
}

void	ft_delay_exec(void)
{
	int			x;

	x = 0;
	while (x < 10000000)
		x++;
}

int	ft_check_gnl(char *gnl)
{
	char	*p;

	p = gnl;
	while (*p != '\0')
	{
		if (ft_isprint(*p) != 0 && *p != ' ')
			return (1);
		p++;
	}
	return (0);
}

char	*ft_delete_isspaces(char *str)
{
	char	*p;
	char	*temp;

	p = str;
	temp = malloc (sizeof(char) * (ft_strlen(str) + 1));
	if (!temp)
		return (NULL);
	while (*p == ' ' || *p == '\t' || *p == '\f' || *p == '\r')
		p++;
	ft_strlcpy(temp, p, (ft_strlen(p) + 1));
	return (temp);
}

char	**ft_free_and_split_pipe(char **split, char *gnl)
{
	free_split (split);
	split = ft_split_pipe(gnl, '|');
	return (split);
}
