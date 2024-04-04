/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreamerlino <andreamerlino@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 20:17:05 by andreamerli       #+#    #+#             */
/*   Updated: 2024/04/02 20:18:43 by andreamerli      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_list **lst_a)
{
	t_list	*last;
	t_list	*temp;

	if (!*lst_a)
		return ;
	last = *lst_a;
	while (last->next)
		last = last->next;
	temp = (*lst_a)->next;
	last->next = *lst_a;
	(*lst_a)->next = NULL;
	*lst_a = temp;
	write(1, "ra\n", 3);
}

void	rotate_b(t_list **lst_b)
{
	t_list	*last;
	t_list	*temp;

	if (!*lst_b)
		return ;
	last = *lst_b;
	while (last->next)
		last = last->next;
	temp = (*lst_b)->next;
	last->next = *lst_b;
	(*lst_b)->next = NULL;
	*lst_b = temp;
	write(1, "rb\n", 3);
}

void	rotate_ab(t_list **lst_a, t_list **lst_b)
{
	t_list	*last;
	t_list	*temp;

	if (!*lst_a || !*lst_b)
		return ;
	last = *lst_a;
	while (last->next)
		last = last->next;
	temp = (*lst_a)->next;
	last->next = *lst_a;
	(*lst_a)->next = NULL;
	*lst_a = temp;
	last = *lst_b;
	while (last->next)
		last = last->next;
	temp = (*lst_b)->next;
	last->next = *lst_b;
	(*lst_b)->next = NULL;
	*lst_b = temp;
	write(1, "rr\n", 3);
}
