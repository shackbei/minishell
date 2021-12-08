/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shackbei <shackbei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:20:18 by shackbei          #+#    #+#             */
/*   Updated: 2021/12/06 18:41:03 by shackbei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"
#include <sys/errno.h>

void	exec_bin(t_data *data)
{
	int		i;
	char	*cmd;
	char	**paths;
	char	**argv;

	argv = data->all[3];
	i = 0;
	paths = ft_split(ft_getenv(data, "PATH"), ':');
	while (paths && paths[i])
	{
		cmd = ft_strjoin(paths[i], "/");
		free(paths[i]);
		paths[i] = cmd;
		cmd = ft_strjoin(paths[i], argv[0]);
		if (access(cmd, F_OK) == 0)
			break ;
		free(cmd);
		cmd = argv[0];
		i++;
	}
	execve(cmd, argv, data->env);
	ft_putstr_fd("command not found: ", 2);
	ft_putendl_fd(argv[0], 2);
	free_matrix(paths);
	exit(127);
}
