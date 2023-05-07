/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 23:14:54 by jaromero          #+#    #+#             */
/*   Updated: 2022/11/28 17:40:08 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	unsigned long	ss1;
	unsigned long	ss2;
	char			*new_s;
	unsigned long	count;

	count = 0;
	ss1 = ft_strlen(s1);
	ss2 = ft_strlen(s2);
	new_s = malloc((sizeof(char) * (ss1 + ss2 + 1)));
	while (count < ss1 + ss2)
	{
		if (count < ss1)
			new_s[count] = s1[count];
		else if (count >= ss1)
			new_s[count] = s2[count - ss1];
		count++;
	}
	new_s[count] = '\0';
	return (new_s);
}
