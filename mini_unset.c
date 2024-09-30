/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ineimatu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:04:47 by ineimatu          #+#    #+#             */
/*   Updated: 2024/09/30 17:53:35 by ineimatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "minishell.h"
 * #include "struct.h"*/

#include "fake_struct.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

t_envp	*do_unset(t_info *info, t_envp *to_unset)
{
	t_envp	*prev;
	t_envp	*current;

	prev = NULL;
	current = info->envp;
	while (current != to_unset)
	{
		prev = current;
		current = current->next;
	}
	free(current->key);
	free(current->value);
	if (prev)
		prev->next = current->next;
	if (!prev)
		info->envp = current->next;
	free(current);
	return (info->envp);
}

int	mini_unset(char **argv, t_info *info)
{
	t_envp	*current;
	int		i;

	i = 1;
	while (argv[i])
	{
		current = info->envp;
		while (current)
		{
			if (ft_strcmp(current->key, argv[i]) == 0)
			{
				info->envp = do_unset(info, current);
				current = info->envp;
			}
			else
				current = current->next;
		}
		i++;
	}
	return (0);
}
