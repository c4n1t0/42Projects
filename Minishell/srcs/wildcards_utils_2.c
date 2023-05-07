/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcards_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 19:23:20 by bjimenez          #+#    #+#             */
/*   Updated: 2022/12/21 11:37:59 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_wld_strjoin(char *s1, char *s2)
{
	unsigned long	ss1;
	unsigned long	ss2;
	char			*new_s;
	unsigned long	count;

	count = 0;
	ss1 = ft_strlen(s1);
	ss2 = ft_strlen(s2);
	new_s = malloc((sizeof(char) * (ss1 + ss2 + 1)));
	if (!new_s)
		return (NULL);
	while (count < ss1 + ss2)
	{
		if (count < ss1)
			new_s[count] = s1[count];
		else if (count >= ss1)
			new_s[count] = s2[count - ss1];
		count++;
	}
	free (s1);
	new_s[count] = '\0';
	return (new_s);
}

int	ft_check_wld(char **d_wld, char *d_name)
{
	int	i;

	i = 0;
	while (d_wld[i])
	{
		if (ft_strstr(d_name, d_wld[i]))
		{
			d_name = ft_strstr(d_name, d_wld[i]);
			i++;
		}
		else
			return (0);
	}
	return (1);
}

char	*ft_strstr(char *str, char *to_find)
{
	char	*q;
	int		i;
	int		j;

	i = 0;
	q = str;
	if (*to_find == '\0')
		return (str);
	while (q[i] != '\0')
	{
		j = 0;
		if (q[i] == to_find[j])
			str = &q[i];
		while (q[i + j] == to_find[j])
		{	
			if (to_find[j + 1] == '\0')
				return (str);
			else if (to_find[j + 1] != q[i + j + 1])
				break ;
			j++;
		}
		i++;
	}
	return (0);
}
