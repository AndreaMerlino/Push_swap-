/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreamerlino <andreamerlino@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 21:15:25 by andreamerli       #+#    #+#             */
/*   Updated: 2024/04/03 12:44:32 by andreamerli      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	merge_part1(t_m_s *ms, int lower, int middle, int upper)
{
	ms->i = lower;
	ms->j = middle + 1;
	ms->k = lower;
	while (ms->i <= middle && ms->j <= upper)
	{
		if (ms->array[ms->i] < ms->array[ms->j])
		{
			ms->b[ms->k] = ms->array[ms->i];
			ms->i++;
		}
		else
		{
			ms->b[ms->k] = ms->array[ms->j];
			ms->j++;
		}
		ms->k++;
	}
}

void	merge(t_m_s *ms, int lower, int middle, int upper)
{
	merge_part1(ms, lower, middle, upper);
	if (ms->i > middle)
	{
		while (ms->j <= upper)
		{
			ms->b[ms->k] = ms->array[ms->j];
			ms->j++;
			ms->k++;
		}
	}
	else
	{
		while (ms->i <= middle)
		{
			ms->b[ms->k] = ms->array[ms->i];
			ms->i++;
			ms->k++;
		}
	}
	ms->i = lower;
	while (ms->i <= upper)
	{
		ms->array[ms->i] = ms->b[ms->i];
		ms->i++;
	}
}

void	merge_sort(t_m_s *ms, int lower, int upper)
{
	int	middle;

	if (lower < upper)
	{
		middle = (lower + upper) / 2;
		merge_sort (ms, lower, middle);
		merge_sort (ms, middle + 1, upper);
		merge(ms, lower, middle, upper);
	}
}
