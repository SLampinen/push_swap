/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slampine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:17:10 by slampine          #+#    #+#             */
/*   Updated: 2023/03/14 11:28:17 by slampine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"

int	is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	is_rev_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value < stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	is_number(char *src)
{
	int		ind;
	long	check;

	ind = 0;
	if ((src[ind] == '+' || src[ind] == '-') && src[ind + 1] != '\0')
		ind++;
	while (src[ind] && ft_isdigit(src[ind]))
		ind++;
	if (src[ind] != '\0' && ft_isdigit(src[ind]) == 0)
		return (0);
	ind = ft_atoi(src);
	check = ft_atol(src);
	if (ind != check)
		return (0);
	return (1);
}

int	check_duplicates(t_stack *src)
{
	t_stack	*temp;

	while (src->next != NULL)
	{
		temp = src;
		while (temp->next != NULL)
		{
			temp = temp->next;
			if (temp->value == src->value)
				return (1);
		}
		src = src->next;
	}
	return (0);
}
