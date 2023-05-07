/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjimenez <bjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 00:31:12 by jaromero          #+#    #+#             */
/*   Updated: 2022/12/14 22:32:58 by bjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *p, int c)
{
	char	*s;

	s = (char *)p;
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		else
			s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
