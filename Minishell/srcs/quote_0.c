/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 09:43:21 by jaromero          #+#    #+#             */
/*   Updated: 2022/12/21 11:21:47 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_rm_quote_search(t_rm_quote *quote)
{
	quote->q = quote->str;
	while (*quote->p != '"' && *quote->p != 39)
	{
		*quote->q = *quote->p;
		quote->q++;
		quote->p++;
	}
}

void	ft_rm_sub_double_quote(t_rm_quote *quote)
{
	quote->p++;
	while (*quote->p != '"' && *quote->p != '\0')
	{
		*quote->q = *quote->p;
		quote->p++;
		quote->q++;
	}
}

void	ft_rm_sub_single_quote(t_rm_quote *quote)
{
	quote->p++;
	while (*quote->p != 39 && *quote->p != '\0')
	{
		*quote->q = *quote->p;
		quote->p++;
		quote->q++;
	}
}

char	*ft_remove_quote(char *split)
{
	t_rm_quote	quote;

	quote.p = split;
	if (ft_strchr(split, '"') == 0 && ft_strchr(split, 39) == 0)
		return (split);
	quote.str = malloc(sizeof(char) * (ft_strlen(split) + 1));
	if (!quote.str)
		return (NULL);
	ft_rm_quote_search(&quote);
	while (*quote.p != '\0')
	{
		if (*quote.p == '"')
			ft_rm_sub_double_quote(&quote);
		else if (*quote.p == 39)
			ft_rm_sub_single_quote(&quote);
		else
		{
			*quote.q = *quote.p;
			quote.q++;
		}
		if (*quote.p != '\0')
			quote.p++;
	}
	*quote.q = '\0';
	return (free(split), quote.str);
}

char	**ft_parse_quote(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		split[i] = ft_remove_quote(split[i]);
	return (split);
}
