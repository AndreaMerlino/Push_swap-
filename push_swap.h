/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreamerlino <andreamerlino@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 22:18:21 by andreamerli       #+#    #+#             */
/*   Updated: 2024/04/03 12:28:10 by andreamerli      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

typedef struct s_tools
{
	int		i;
	t_list	*head;
	t_list	*temp;
	t_list	*newnode;
	char	**contenitore;
	char	**clean;
}	t_tools;

typedef struct merge_s
{
	int	*array;
	int	*b;
	int	i;
	int	j;
	int	k;
}	t_m_s;

typedef struct alogritm
{
	int		holder;
	int		holder2;
	int		k;
	int		x;
	int		a;
	int		b;
	int		c;
	int		d;
	int		w[2];
	int		v[2];
	t_list	*last;
	t_list	*temp;
}	t_algo;

typedef struct inutile
{
	int	temp;
	int	list_size;
	int	hold;
}	t_t;

void	*ft_calloc(size_t count, size_t size);
void	swap_a(t_list *lst);
void	swap_b(t_list*lst);
void	swap_ab(t_list *lst, t_list *lst2);
void	push_a(t_list **lst_a, t_list **lst_b);
void	push_b(t_list **lst_b, t_list**lst_a);
void	rotate_a(t_list**lst_a);
void	rotate_b(t_list **lst_b);
void	rotate_ab(t_list **lst_a, t_list **lst_b);
void	reverse_rotate_a(t_list**lst_a);
void	reverse_rotate_b(t_list **lst_b);
void	reverse_rotate_ab(t_list **lst_a, t_list**lst_b);

void	string_checker(char **argv);
void	number_checker(t_list*lst);
void	max_min(char *contenitore);
void	merge_sort(t_m_s *ms, int lower, int upper);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_lstsize(t_list *lst);
int		position_max_int(t_list *lst);
int		position_min_int(t_list *lst);
int		min_int(t_list *lst);
int		max_int(t_list *lst);
int		max_int_array(int i, t_m_s *ms);
int		position_of_x(t_list *lst, int m);
int		ft_atoi(const char *str);

int		position_of_x2(t_list *lst, int m);
void	algortim222(t_list **lst_a, t_list **lst_b, t_m_s *ms);
void	node_with_less_move(t_list **lst_a, t_list **lst_b,
			t_m_s *ms, t_algo *al);
void	push_the_node_founded(t_list **lst_a, t_list **lst_b,
			t_m_s *ms, t_algo *al);
void	init_array(t_m_s *ms, int i, t_list *lst);
int		before_contentvalue(int i, t_m_s *ms, t_list *lst);
int		after_contentvalue(int i, t_m_s *ms, t_list *lst);
void	magic_3(t_list **stack_a, int i);
t_list	*ft_lstlast(t_list*lst);
t_list	*ft_lstsecondlast(t_list *lst);
t_list	*init_stack_a(int argc, char **argv);

#endif
