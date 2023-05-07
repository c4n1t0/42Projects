/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:54:14 by jaromero          #+#    #+#             */
/*   Updated: 2022/11/19 17:18:45 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_sub_double_quote(t_quote *quote, char *s)
{
	quote->i = 1;
	while ((*quote->p != '"' && quote->i == 1)
		|| (*quote->p != '\0' && quote->i == 1))
	{
		quote->p++;
		if (*quote->p == '"')
			quote->i = 0;
		if ((quote->p == s && quote->i == 1) || *quote->p == '\0')
			return ;
	}
}

void	ft_sub_single_quote(t_quote *quote, char *s)
{
	quote->i = 2;
	while ((*quote->p != 39 && quote->i == 2)
		|| (*quote->p != '\0' && quote->i == 2))
	{
		quote->p++;
		if (*quote->p == 39)
			quote->i = 0;
		if ((quote->p == s && quote->i == 2) || *quote->p == '\0')
			return ;
	}
}

int	ft_quote_pipe(char *str, char *s)
{
	t_quote	quote;

	quote.p = str;
	quote.i = 0;
	while (*quote.p != '\0')
	{
		if (*quote.p == '"' || *quote.p == 39)
		{
			if (*quote.p == '"')
				ft_sub_double_quote(&quote, s);
			else if (*quote.p == 39)
				ft_sub_single_quote(&quote, s);
			if ((quote.p == s && quote.i != 0) || *quote.p == '\0')
				return (quote.i);
			quote.i = 0;
		}
		quote.p++;
	}
	return (0);
}
