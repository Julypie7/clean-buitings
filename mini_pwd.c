/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_pwd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineimatu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 13:17:47 by ineimatu          #+#    #+#             */
/*   Updated: 2024/09/30 18:04:08 by ineimatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "minishell.h"
 * #include "struct.h"*/

#include "fake_struct.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	mini_pwd(t_envp *lst)
{
	t_envp	*tmp;
	char	*pwd;

	tmp = lst;
	pwd = NULL;
	pwd = getcwd(pwd, 0);
	if (!pwd)
	{
		while (tmp)
		{
			if (ft_strcmp(tmp->key, "PWD=") == 0)
			{
				ft_putstr_fd(tmp->value, 1);
				return (0);
			}
			else
				tmp = tmp->next;
		}
		return (1);
	}
	else
		printf("%s\n", pwd);
	return (free(pwd), 0);
}
