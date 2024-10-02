/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineimatu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:44:01 by ineimatu          #+#    #+#             */
/*   Updated: 2024/10/02 14:07:36 by ineimatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"

//EXIT
int	mini_exit(char **av, t_info *info, t_cmd *cmds, t_exec *exec_info);
long long	ft_atoi_ex(char *str);
void	check_arg(char *arg, t_info *info, t_cmd *cmd, t_exec *exec_info);
void	exit_error(t_info *info, int ex_st, t_cmd *cmds, t_exec *exec_info);
void	ft_exit(t_info *info, int ex_stat, t_cmd *cmd, t_exec *exec_info);

//ENV
int	mini_env(char **argv, t_info *info);

//PWD
int	mini_pwd(t_envp *lst);

//ECHO
int	mini_echo(char **argv);
int size_of_argv(char **argv);

//UNSET
t_envp	*do_unset(t_info *info, t_envp *to_unset);
int	mini_unset(char **argv, t_info *info);

//CD
int	mini_cd(char **argv, t_info *info);
int	just_cd(t_envp *lst, char *path, t_info *info);
void	change_pwd(t_envp *lst);
char	*ft_getenv(char *str, t_envp *lst);

//void	ft_putstr_fd(char *s, int fd);
int	ft_strcmp(char *s1, char *s2);
char	*ft_strcpy(char *s1, char *s2);

#endif
