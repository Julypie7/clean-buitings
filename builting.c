/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineimatu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 10:54:22 by ineimatu          #+#    #+#             */
/*   Updated: 2024/09/30 15:46:00 by ineimatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "struct.h"

int	exec_builtin(char **arr_cmd, t_info *info)
{
	if (ft_strncmp(arr_cmd[0], "pwd", ft_strlen(arr_cmd[0]) == 0))
		return (mini_pwd(info->envp));
	else if (ft_strncmp(arr_cmd[0], "cd", ft_strlen(arr_cmd[0]) == 0))
		return (mini_cd(arr_cmd, info));
	else if (ft_strncmp(arr_cmd[0], "env", ft_strlen(arr_cmd[0]) == 0))
		return (mini_env(arr_cmd, info));
	else if (ft_strncmp(arr_cmd[0], "export", ft_strlen(arr_cmd[0]) == 0))
		return (mini_export(arr_cmd, info));
	else if (ft_strncmp(arr_cmd[0], "echo", ft_strlen(arr_cmd[0]) == 0))
		return (mini_echo(argv));
	else if (ft_strncmp(arr_cmd[0], "unset", ft_strlen(arr_cmd[0]) == 0)
		return (mini_unset(info));
	else if (ft_strncmp (arr_cmd[0], "error", ft_strlen(arr_cmd[0]) == 0))
		return (mini_exit(info));
}

int main(int argc, char **argv)
{
	builtings(argv
}
