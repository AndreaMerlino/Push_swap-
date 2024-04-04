/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreamerlino <andreamerlino@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 21:05:54 by andreamerli       #+#    #+#             */
/*   Updated: 2024/04/04 23:09:13 by andreamerli      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	before_contentvalue(int i, t_m_s *ms, t_list *lst)
{
	int	k;
	int	temp;

	temp = 0;
	k = 0;
	init_array(ms, ft_lstsize(lst), lst);
	merge_sort(ms, 0, ft_lstsize(lst) -1);
	while (i > ms->b[k] && k < ft_lstsize(lst) - 1)
		k ++;
	temp = ms->b[k - 1];
	if (i < ms->b[k])
	{
		free(ms->b);
		free(ms->array);
		return (temp);
	}
	free(ms->b);
	free(ms->array);
	k = 1;
	return (k);
}

void	i_need_25_line(int i, t_m_s *ms, t_list *lst, t_t *t)
{
	init_array(ms, t->list_size, lst);
	t->list_size --;
	merge_sort(ms, 0, t->list_size);
	while (i < ms->b[t->list_size] && t->list_size > 0)
		t->list_size --;
	t->temp = ms->b[t->list_size];
}

int	after_contentvalue(int i, t_m_s *ms, t_list*lst)
{
	t_t	t;

	t.list_size = ft_lstsize(lst);
	t.hold = t.list_size -1;
	t.temp = 0;
	i_need_25_line(i, ms, lst, &t);
	if (i > ms->b[t.list_size])
	{
		if (t.list_size == t.hold)
			t.temp = ms->b[0];
		else
			t.temp = ms->b[t.list_size + 1];
		free(ms->b);
		free(ms->array);
		return (t.temp);
	}
	t.temp = ms->b[0];
	free (ms->b);
	free (ms->array);
	return (t.temp);
}

int	main(int argc, char **argv)
{
	int		i;
	t_m_s	ms;
	t_list	*stack_a;
	t_list	*stack_b;

	stack_b = NULL;
	stack_a = NULL;
	string_checker(argv);
	stack_a = init_stack_a(argc, argv);
	number_checker(stack_a);
	i = ft_lstsize(stack_a);
	if (i == 2 || i == 3)
		magic_3(&stack_a, i);
	else if (i > 3)
		algortim222(&stack_a, &stack_b, &ms);
	while (stack_a)
	{
		stack_b = stack_a;
		stack_a = stack_a->next;
		free(stack_b);
	}
}
