/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreamerlino <andreamerlino@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 22:16:08 by andreamerli       #+#    #+#             */
/*   Updated: 2024/04/06 13:02:34 by andreamerli      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	position_max_int(t_list *lst)
{
	int		m;
	int		i;
	t_list	*temp;

	m = 1;
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
	temp = lst;
	while (i != temp->content)
	{
		m++;
		temp = temp->next;
	}
	return (m);
}

int	position_min_int(t_list *lst)
{
	int		m;
	int		i;
	t_list	*temp;

	m = 1;
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
	while (i != temp->content)
	{
		m++;
		temp = temp->next;
	}
	return (m);
}

int	position_of_x(t_list *lst, int m)
{
	int	x;

	x = 1;
	while (m < lst->content)
	{
		x++;
		lst = lst->next;
	}
	return (x);
}

int	position_of_x2(t_list *lst1, int m)
{
	t_list	*lst;
	int		x;

	lst = lst1;
	x = 1;
	while (lst != NULL)
	{
		if (m == lst->content)
			return (x);
		lst = lst->next;
		x++;
	}
	return (-1);
}

int	max_int_array(int i, t_m_s *ms)
{
	int	k;

	k = ms->b[0];
	while ((i - 1) >= 0)
	{
		if (k < ms->b[i -1])
			k = ms->b[i -1];
		i --;
	}
	return (k);
}
