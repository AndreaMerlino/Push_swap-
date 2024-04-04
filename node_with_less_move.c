/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_with_less_move.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreamerlino <andreamerlino@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 22:10:21 by andreamerli       #+#    #+#             */
/*   Updated: 2024/04/04 11:42:20 by andreamerli      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	node_with_less_move_1condition(t_list **lst_b, t_algo *al)
{
	al->k = position_of_x(*lst_b, max_int(*lst_b));
	if (al->k - 1 <= (ft_lstsize(*lst_b) / 2))
	{
		al->x = (al->k) + al->a - al->b;
		al->v[0] = al->x;
	}
	else
	{
		al->x = 1 + (ft_lstsize(*lst_b) - al->k) + al->a - al->b;
		al->w[0] = al->x;
	}
}

void	node_with_less_move_2condition(t_list **lst_b, t_m_s *ms, t_algo *al)
{
	al->k = position_of_x2(*lst_b, before_contentvalue
			(al->temp->content, ms, *lst_b));
	if (al->k - 1 <= (ft_lstsize(*lst_b) / 2))
	{
		al->x = (al->k) + al->a - al->b;
		al->v[0] = al->x;
	}
	else
	{
		al->x = 1 + (ft_lstsize(*lst_b)) - al->k + al->a - al->b;
		al->w[0] = al->x;
	}
}

void	node_with_less_move(t_list **lst_a, t_list **lst_b,
		t_m_s *ms, t_algo *al)
{
	while (al->temp)
	{
		if (al->temp->content > max_int(*lst_b)
			|| al->temp->content < min_int(*lst_b))
			node_with_less_move_1condition(lst_b, al);
		else
			node_with_less_move_2condition(lst_b, ms, al);
		if (al->x < al->holder)
		{
			al->w[1] = al->w[0];
			al->v[1] = al->v[0];
			al->holder = al->x;
			al->holder2 = al->temp->content;
		}
		al->temp = al->temp->next;
		if (al->a - 1 < ft_lstsize(*lst_a) / 2)
			al->a++;
		else
			al->b++;
		al->w[0] = 0;
		al->v[0] = 0;
	}
}
