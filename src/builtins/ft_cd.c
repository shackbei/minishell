/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shackbei <shackbei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 22:33:43 by shackbei          #+#    #+#             */
/*   Updated: 2021/12/01 17:50:53 by shackbei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	update_pwd(t_data *data)
{
	char	cwd[MAX_PATH];
	char	**argv;
	char	*new[3];

	argv = data->all[3];
	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		perror("minishell: pwd");
		return (1);
	}
	else
	{
		free_matrix(data->all[3]);
		new[0] = "export";
		new[1] = ft_strjoin("PWD=", cwd);
		new[2] = NULL;
		data->all[3] = new;
		ft_export(data);
		free(new[1]);
		data->all[3] = NULL;
	}
	return (0);
}

int	ft_cd(t_data *data)
{
	char	**argv;

	argv = data->all[3];
	if (!argv[1])
	{
		if (chdir(ft_getenv(data, "HOME")) == -1)
		{
			ft_putstr_fd("minishell: cd: ", 2);
			perror(ft_getenv(data, "HOME"));
			return (1);
		}
	}
	else
	{
		if (chdir(argv[1]) == -1)
		{
			ft_putstr_fd("minishell: cd: ", 2);
			perror(argv[1]);
			return (1);
		}
	}
	update_pwd(data);
	return (0);
}
