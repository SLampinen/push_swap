/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slampine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:33:12 by slampine          #+#    #+#             */
/*   Updated: 2023/03/13 12:23:53 by slampine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_new(int data)
{
	t_stack	*newnode;

	newnode = malloc(sizeof(*newnode));
	if (!newnode)
		return (NULL);
	newnode->value = data;
	newnode->index = 0;
	newnode->next = NULL;
	return (newnode);
}

void	stack_add_bottom(t_stack **stack, t_stack *new)
{
	t_stack	*temp;

	if (new == NULL)
		return ;
	if (*stack == NULL)
	{
		*stack = new;
	}
	else
	{
		temp = stack_last(*stack);
		temp->next = new;
	}
}

t_stack	*stack_last(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

t_stack	*second_last(t_stack *stack)
{
	while (stack && stack->next != NULL && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}

int	stack_size(t_stack *stack)
{
	int		res;
	t_stack	*newnode;

	newnode = stack;
	res = 1;
	if (!stack)
		return (0);
	while (newnode->next != NULL)
	{
		newnode = newnode->next;
		res++;
	}
	return (res);
}
