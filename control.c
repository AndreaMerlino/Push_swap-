/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreamerlino <andreamerlino@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 18:03:11 by andreamerli       #+#    #+#             */
/*   Updated: 2024/04/10 10:31:31 by andreamerli      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	number_checker_helper(t_list **lst)
{
	t_list	*temp;

	while (*lst)
	{
		temp = *lst;
		*lst = (*lst)->next;
		free(temp);
	}
	*lst = NULL;
	write(1, "Error\n", 6);
	exit(1);
}

void	number_checker(t_list **lst)
{
	t_list	*temp;
	t_list	*temp2;
	int		contenuto;

	temp = *lst;
	while (temp)
	{
		temp2 = temp;
		contenuto = temp2->content;
		temp2 = temp2->next;
		while (temp2)
		{
			if (contenuto == temp2->content)
				number_checker_helper(lst);
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
}

void	string_checker(char **argv)
{
	char	*temp;
	int		i;

	i = 1;
	while (argv[i] != NULL)
	{
		temp = argv[i];
		while (*temp)
		{
			if ((*temp >= 48 && *temp <= 57) || (*temp == 43 && (*(temp + 1)
						>= 48 && *(temp + 1) <= 57)) || (*temp == 45
					&& (*(temp + 1) >= 48 && *(temp + 1) <= 57))
				|| *temp == 32)
				temp++;
			else
			{
				write (1, "Error\n", 6);
				exit (1);
			}
		}
		i++;
	}
}

int	max_min(char *contenitore)
{
	if (((ft_strlen(contenitore) == 10) && (ft_strncmp(contenitore,
					"2147483647", ft_strlen(contenitore)) > 0))
		|| ((ft_strlen(contenitore) == 11) && (*contenitore == '-')
			&& (ft_strncmp(contenitore, "-2147483648",
					ft_strlen(contenitore)) > 0))
		|| ((ft_strlen(contenitore) == 11) && (*contenitore == '+')
			&& (ft_strncmp(contenitore, "+2147483647",
					ft_strlen(contenitore)) > 0))
		|| ft_strlen(contenitore) > 11 || ((ft_strlen(contenitore) == 11)
			&& (*contenitore != '+' && *contenitore != '-')))
	{
		return (100);
	}
	return (0);
}
