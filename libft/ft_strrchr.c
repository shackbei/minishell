/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shackbei <shackbei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 19:12:06 by shackbei          #+#    #+#             */
/*   Updated: 2021/11/16 13:46:10 by shackbei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	a;

	i = ft_strlen(s);
	a = (char)c;
	if (s == NULL)
		return (NULL);
	while (i >= 0 || a == '\0')
	{
		if (s[i] == a || s[i] == '\0')
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}
