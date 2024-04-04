/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreamerlino <andreamerlino@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 21:03:47 by andreamerli       #+#    #+#             */
/*   Updated: 2024/04/02 12:31:13 by andreamerli      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_process_loop(t_tools *tool)
{
	if (tool->head == 0)
	{
		tool->head = tool->temp;
		tool->newnode = tool->temp;
	}
	else
	{
		tool->newnode->next = tool->temp;
		tool->newnode = tool->temp;
	}
}

t_list	*init_process(int argc, char **argv, t_tools *tool)
{
	char	**contenitore;
	char	**clean;
	char	**start;

	while (tool->i < (argc -1))
	{
		contenitore = ft_split(argv[tool->i +1], 32);
		clean = contenitore;
		start = contenitore;
		while (*contenitore)
		{
			max_min(*contenitore);
			tool->temp = ft_calloc(sizeof(t_list), 1);
			tool->temp->content = ft_atoi(*contenitore);
			init_process_loop(tool);
			contenitore ++;
			free(*clean);
			clean = contenitore;
		}
		free (start);
		tool->i++;
	}
	return (tool->head);
}

t_list	*init_stack_a(int argc, char **argv)
{
	t_tools	tool;

	tool.i = 0;
	tool.newnode = NULL;
	tool.temp = NULL;
	tool.head = NULL;
	tool.head = init_process(argc, argv, &tool);
	return (tool.head);
}

void	init_array(t_m_s *ms, int i, t_list *lst)
{
	int	k;

	k = 0;
	ms->array = ft_calloc(i * sizeof(int), 1);
	ms->b = ft_calloc(i * sizeof(int), 1);
	while (lst)
	{
		ms->array[k] = lst->content;
		lst = lst->next;
		k++;
	}
}
