/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreamerlino <andreamerlino@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 20:24:40 by andreamerli       #+#    #+#             */
/*   Updated: 2024/04/02 20:24:42 by andreamerli      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_list **lst_a)
{
	t_list	*last;
	t_list	*temp;

	if (!*lst_a || !(*lst_a)->next)
		return ;
	last = *lst_a;
	while (last->next->next)
		last = last->next;
	temp = last->next;
	last->next = NULL;
	temp->next = *lst_a;
	*lst_a = temp;
	write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_list **lst_b)
{
	t_list	*last;
	t_list	*temp;

	if (!*lst_b || !(*lst_b)->next)
		return ;
	last = *lst_b;
	while (last->next->next)
		last = last->next;
	temp = last->next;
	last->next = NULL;
	temp->next = *lst_b;
	*lst_b = temp;
	write(1, "rrb\n", 4);
}

void	reverse_rotate_ab(t_list **lst_a, t_list **lst_b)
{
	t_list	*last;
	t_list	*temp;

	if (!*lst_a || !*lst_b || !(*lst_a)->next || !(*lst_b)->next)
		return ;
	last = *lst_a;
	while (last->next->next)
		last = last->next;
	temp = last->next;
	last->next = NULL;
	temp->next = *lst_a;
	*lst_a = temp;
	last = *lst_b;
	while (last->next->next)
		last = last->next;
	temp = last->next;
	last->next = NULL;
	temp->next = *lst_b;
	*lst_b = temp;
	write(1, "rrr\n", 4);
}
