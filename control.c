/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreamerlino <andreamerlino@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 18:03:11 by andreamerli       #+#    #+#             */
/*   Updated: 2024/04/02 11:50:07 by andreamerli      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	number_checker(t_list *lst)
{
	t_list	*temp;
	t_list	*temp2;
	int		contenuto;

	temp = lst;
	while (temp)
	{
		temp2 = temp;
		contenuto = temp2->content;
		temp2 = temp2->next;
		while (temp2)
		{
			if (contenuto == temp2->content)
			{
				write(1, "Error", 5);
				exit(1);
			}
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
				write (1, "Error", 5);
				exit (1);
			}
		}
		i++;
	}
}

void	max_min(char *contenitore)
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
		write(1, "Error", 5);
		exit(1);
	}
}

int	min_int(t_list *lst)
{
	int		i;
	t_list	*temp;

	temp = lst;
	i = temp->content;
	temp = temp->next;
	while (temp)
	{
		if (i > temp->content)
		{
			i = temp->content;
			temp = temp->next;
		}
		else
			temp = temp->next;
	}
	temp = lst;
	return (i);
}

int	max_int(t_list *lst)
{
	int		i;
	t_list	*temp;

	temp = lst;
	i = temp->content;
	temp = temp->next;
	while (temp)
	{
		if (i < temp->content)
		{
			i = temp->content;
			temp = temp->next;
		}
		else
			temp = temp->next;
	}
	return (i);
}
