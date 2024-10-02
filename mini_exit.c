/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineimatu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:41:51 by ineimatu          #+#    #+#             */
/*   Updated: 2024/10/02 14:14:01 by ineimatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft/libft.h"
#include "builtin.h"
#include "struct.h"

void	ft_exit(t_info *info, int ex_stat, t_cmd *cmds, t_exec *exec_info)
{
	free_child(info, cmds, exec_info);
	/*if (info->envp)
		free_envlst(info->envp);
	if (info->copy)
		free_envlst(info->copy);
   	if (info->list)
		free_envlst(info->list);
	free(info);*/
	exit(ex_stat);
}

void	exit_error(t_info *info, int ex_st, t_cmd *cmds, t_exec *exec_info)
{
	ft_putstr_fd("minishelll: exit: ", 2);
	ft_putstr_fd("numeric argument required", 2);
	ft_exit(info, ex_st, cmds, exec_info);
}

void	check_arg(char *arg, t_info *info, t_cmd *cmds, t_exec *exec_info)
{
	int	i;

	i = 0;
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	if (!arg[i])
		exit_error(info, 2, cmds, exec_info);
	if (ft_strcmp(arg, "9223372036854775808") <= 0)
		exit_error(info, 2, cmds, exec_info);
	if (ft_strcmp(arg, "-9223372036854775809") <= 0)
		exit_error(info, 2, cmds, exec_info);
	if (ft_strlen(arg) > 19)
		exit_error(info, 2, cmds, exec_info);
	while (arg[i])
	{
		if ((arg[i] != '\f') && (arg[i] != '\t') && (arg[i] != '\r') \
				&& (arg[i] != '\v') && (arg[i] != ' '))
		{
			if (arg[i] < 48 || arg[i] > 57)
				exit_error(info, 1, cmds, exec_info);
		}
		i++;
	}
}

long long	ft_atoi_ex(char *str)
{
	long long	nbr;
	long long	i;
	int			flag;

	nbr = 0;
	i = 0;
	flag = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		flag = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = (str[i] - '0') + nbr * 10;
		i++;
	}
	if (flag == -1)
		nbr = nbr * flag;
	return (nbr);
}

int	mini_exit(char **av, t_info *info, t_cmd *cmds, t_exec *exec_info)
{
	int			i;
	long long	ex_stat;

	i = 1;
	while (av[i])
		i++;
	if (i >= 3)
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", 2);
		ex_stat = 1;
		return (1);
	}
	else
	{
		i = 1;
		if (av[i])
		{
			check_arg(av[i], info, cmds, exec_info);
			ex_stat = ft_atoi_ex(av[i]);
		}
		else
			ft_exit(info, 1, cmds, exec_info);
	}
	ft_exit(info, ex_stat, cmds, exec_info);
	return (0);
}	
