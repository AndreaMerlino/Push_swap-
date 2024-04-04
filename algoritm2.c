/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreamerlino <andreamerlino@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 12:03:14 by andreamerli       #+#    #+#             */
/*   Updated: 2024/04/03 12:11:49 by andreamerli      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_calloc(size_t count, size_t size)
{
	void		*ptr;
	size_t		bytes;

	bytes = count * size;
	ptr = malloc(bytes);
	if (!ptr)
		return (NULL);
	while (bytes--)
		((char *)ptr)[bytes] = 0;
	return (ptr);
}

void	magic_3_3(t_list **stack_a, int i)
{
	int	y;

	i = position_max_int(*stack_a);
	y = position_min_int(*stack_a);
	if (i == 2 && y == 1)
	{
		swap_a(*stack_a);
		rotate_a(stack_a);
	}
	else if (i == 3 && y == 2)
		swap_a(*stack_a);
	else if (i == 2 && y == 3)
		reverse_rotate_a(stack_a);
	else if (i == 1 && y == 2)
		rotate_a(stack_a);
	else if (i == 1 && y == 3)
	{
		swap_a(*stack_a);
		reverse_rotate_a(stack_a);
	}
}

void	magic_3(t_list **stack_a, int i)
{
	t_list	*temp;

	if (i == 2)
	{
		temp = *stack_a;
		i = temp->content;
		if (i > temp->next->content)
			swap_a(*stack_a);
	}
	if (i == 3)
		magic_3_3(stack_a, i);
}
