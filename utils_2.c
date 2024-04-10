/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreamerlino <andreamerlino@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 10:14:13 by andreamerli       #+#    #+#             */
/*   Updated: 2024/04/10 10:31:40 by andreamerli      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	controller3_helper(t_25 *t, int i)
{
	while (t->contenitore[i])
	{
		free (t->contenitore[i]);
		i ++;
	}
	free (t->contenitore);
	write (1, "Error\n", 6);
	exit (1);
}

void	controller3(int argc, char **argv)
{
	t_25	t;
	int		i;
	int		j;

	i = 0;
	j = 0;
	t.i = 0;
	while (t.i < (argc -1))
	{
		t.contenitore = ft_split(argv[t.i + 1], 32);
		while (t.contenitore[i])
		{
			j = max_min(t.contenitore[i]);
			if (j == 100)
				controller3_helper(&t, i);
			free(t.contenitore[i]);
			i ++;
		}
		i = 0;
		free (t.contenitore);
		t.i++;
	}
}

int	min_int(t_list *lst)
{
	int		i;
	t_list	*temp;

	temp = lst;
	i = temp->content;
	temp = temp->next;
	while (temp)
	{
		if (i > temp->content)
		{
			i = temp->content;
			temp = temp->next;
		}
		else
			temp = temp->next;
	}
	temp = lst;
	return (i);
}

int	max_int(t_list *lst)
{
	int		i;
	t_list	*temp;

	temp = lst;
	i = temp->content;
	temp = temp->next;
	while (temp)
	{
		if (i < temp->content)
		{
			i = temp->content;
			temp = temp->next;
		}
		else
			temp = temp->next;
	}
	return (i);
}
