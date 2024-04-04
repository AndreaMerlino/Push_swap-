/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_the_node_founded.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreamerlino <andreamerlino@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 12:46:53 by andreamerli       #+#    #+#             */
/*   Updated: 2024/04/04 13:14:26 by andreamerli      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_the_node_founded1(t_list **lst_a, t_list **lst_b, t_algo *al)
{
	al->c = 0;
	al->d = 0;
	al->k = position_of_x2(*lst_a, al->holder2);
	if ((al->k -1 <= (ft_lstsize(*lst_a) / 2)) && al->k > 1)
		al->c = al->k;
	else if (al->k > 1)
		al->d = ft_lstsize(*lst_a) - al->k;
	while ((al->c > 0 && al->d == 0) && (al->v[1] > 0 && al->w[1] == 0))
	{
		rotate_ab(lst_a, lst_b);
		al->c --;
		al->v[1]--;
	}
	while (al->c == 0 && (al->d > 0 && al->w[1] > 0))
	{
		reverse_rotate_ab(lst_a, lst_b);
		al->d --;
		al->w[1]--;
	}
}

void	push_the_node_founded_while(t_list **lst_a, t_algo *al)
{
	while ((*lst_a)->content != al->holder2)
	{
		al->k = position_of_x2(*lst_a, al->holder2);
		if (al->k -1 <= (ft_lstsize(*lst_a) / 2))
			rotate_a(lst_a);
		else
			reverse_rotate_a(lst_a);
	}
}

void	push_the_node_founded2(t_list **lst_a, t_list **lst_b, t_algo *al)
{
	if ((*lst_b)->content == max_int(*lst_b))
		push_b(lst_b, lst_a);
	else if ((*lst_b)->next->content == max_int(*lst_b))
	{
		rotate_b(lst_b);
		push_b(lst_b, lst_a);
	}
	else if (al->last->content == max_int(*lst_b))
	{
		reverse_rotate_b(lst_b);
		push_b(lst_b, lst_a);
	}
	else
	{
		al->k = position_of_x(*lst_b, max_int(*lst_b));
		if (al->k - 1 <= (ft_lstsize(*lst_b) / 2))
			rotate_b(lst_b);
		else
			reverse_rotate_b(lst_b);
	}
}

void	push_the_node_founded(t_list **lst_a, t_list **lst_b,
		t_m_s *ms, t_algo *al)
{
	push_the_node_founded1(lst_a, lst_b, al);
	push_the_node_founded_while(lst_a, al);
	if ((*lst_a)->content > max_int(*lst_b)
		|| (*lst_a)->content < min_int(*lst_b))
		push_the_node_founded2(lst_a, lst_b, al);
	else
	{
		if ((*lst_b)->content == before_contentvalue((*lst_a)->content,
				ms, *lst_b))
			push_b(lst_b, lst_a);
		else
		{
			while ((*lst_b)->content != before_contentvalue((*lst_a)->content,
					ms, *lst_b))
			{
				al->k = position_of_x2(*lst_b,
						before_contentvalue((*lst_a)->content, ms, *lst_b));
				if (al->k -1 <= (ft_lstsize(*lst_b) / 2))
					rotate_b(lst_b);
				else
					reverse_rotate_b(lst_b);
			}
		}
	}
}
