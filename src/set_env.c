/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shackbei <shackbei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 23:06:51 by shackbei          #+#    #+#             */
/*   Updated: 2021/11/27 23:06:52 by shackbei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	set_env(t_data *data, char **envp)
{
	int	i;

	data->env = malloc(sizeof(char *) * (ft_arrlen(envp) + 1));
	if (!data->env)
		return (1);
	i = 0;
	while (envp[i])
	{
		data->env[i] = ft_strdup(envp[i]);
		i++;
	}
	data->env[i] = NULL;
	return (0);
}
