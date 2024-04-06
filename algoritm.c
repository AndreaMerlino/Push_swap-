/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreamerlino <andreamerlino@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 20:08:22 by andreamerli       #+#    #+#             */
/*   Updated: 2024/04/06 12:48:04 by andreamerli      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	controller(t_list**lst_a, t_list **lst_b)
{
	if (ft_lstsize(*lst_a) == 4)
		push_b(lst_b, lst_a);
	else
	{
		push_b(lst_b, lst_a);
		push_b(lst_b, lst_a);
	}
}

void	max_of_2_move(t_list **lst_a, t_list **lst_b, t_m_s *ms, t_algo *al)
{
	al->b = 0;
	al->a = 0;
	al->last = ft_lstlast(*lst_a);
	if ((*lst_a)->content > max_int(*lst_b)
		|| (*lst_a)->content < min_int(*lst_b))
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
	}
	else if ((*lst_b)->content == before_contentvalue((*lst_a)->content,
			ms, *lst_b))
		push_b(lst_b, lst_a);
}

void	order_stacka(t_list **lst_a, t_algo *al)
{
	while ((*lst_a)->content != min_int(*lst_a))
	{
		al->k = position_of_x2(*lst_a, min_int(*lst_a));
		if (al->k - 1 <= (ft_lstsize(*lst_a) / 2))
			rotate_a(lst_a);
		else
			reverse_rotate_a(lst_a);
	}
}

void	push_back(t_list **lst_a, t_list **lst_b, t_m_s *ms, t_algo *al)
{
	while (ft_lstsize(*lst_b) > 0)
	{
		if ((*lst_a)->content == after_contentvalue((*lst_b)->content,
				ms, *lst_a))
			push_a(lst_a, lst_b);
		else
		{
			while ((*lst_a)->content != after_contentvalue((*lst_b)->content,
					ms, *lst_a))
			{
				al->k = position_of_x2(*lst_a,
						after_contentvalue((*lst_b)->content, ms, *lst_a));
				if (al->k - 1 <= (ft_lstsize(*lst_a) / 2))
					rotate_a(lst_a);
				else
					reverse_rotate_a(lst_a);
			}
		}
	}
	order_stacka(lst_a, al);
}

void	algortim222(t_list **lst_a, t_list **lst_b, t_m_s *ms)
{
	t_algo	al;

	al.v[0] = 0;
	al.w[0] = 0;
	al.x = 0;
	al.last = NULL;
	al.temp = NULL;
	al.k = 0;
	controller(lst_a, lst_b);
	while (ft_lstsize(*lst_a) > 3)
	{
		max_of_2_move(lst_a, lst_b, ms, &al);
		if (ft_lstsize(*lst_a) == 3)
			break ;
		al.holder = 100000;
		al.temp = *lst_a;
		node_with_less_move(lst_a, lst_b, ms, &al);
		push_the_node_founded(lst_a, lst_b, ms, &al);
	}
	magic_3(lst_a, 3);
	push_back(lst_a, lst_b, ms, &al);
}
