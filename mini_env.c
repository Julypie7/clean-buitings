/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineimatu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 12:34:20 by ineimatu          #+#    #+#             */
/*   Updated: 2024/09/30 18:10:36 by ineimatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "minishell.h"
#include "struct.h"*/
#include "fake_struct.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	mini_env(char **argv, t_info *info)
{
	t_envp	*tmp;

	tmp = info->envp;
	if (argv[1])
	{
		printf("env: '%s': No such file or directory\n");
		return (1);
	}
	while (tmp)
	{
		printf("%s%s\n", tmp->key, tmp->value);
		tmp = tmp->next;
	}
	return (0);
}
