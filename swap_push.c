/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreamerlino <andreamerlino@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 20:25:47 by andreamerli       #+#    #+#             */
/*   Updated: 2024/04/04 18:52:55 by andreamerli      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list *lst)
{
	int		a;

	if (lst == NULL || lst->next == NULL)
		return ;
	a = lst->content;
	lst->content = lst->next->content;
	lst->next->content = a;
	write(1, "sa\n", 3);
}

void	swap_b(t_list *lst)
{
	int		a;

	if (lst == NULL || lst->next == NULL)
		return ;
	a = lst->content;
	lst->content = lst->next->content;
	lst->next->content = a;
	write(1, "sb\n", 3);
}

void	swap_ab(t_list *lst, t_list *lst2)
{
	int		a;

	if (lst == NULL || lst->next == NULL || lst2 == NULL || lst2->next == NULL)
		return ;
	a = lst->content;
	lst->content = lst->next->content;
	lst->next->content = a;
	a = lst2->content;
	lst2->content = lst2->next->content;
	lst2->next->content = a;
	write(1, "ss\n", 3);
}

void	push_a(t_list **lst_a, t_list **lst_b)
{
	t_list	*temp;

	if (!*lst_b)
		return ;
	temp = *lst_a;
	*lst_a = ft_calloc(sizeof(t_list), 1);
	(*lst_a)->next = temp;
	(*lst_a)->content = (*lst_b)->content;
	temp = *lst_b;
	*lst_b = (*lst_b)->next;
	free(temp);
	write(1, "pa\n", 3);
}

void	push_b(t_list **lst_b, t_list **lst_a)
{
	t_list	*temp;

	if (!*lst_a)
		return ;
	temp = *lst_a;
	*lst_a = (*lst_a)->next;
	temp->next = *lst_b;
	*lst_b = temp;
	write(1, "pb\n", 3);
}
