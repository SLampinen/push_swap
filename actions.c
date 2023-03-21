/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slampine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:50:44 by slampine          #+#    #+#             */
/*   Updated: 2023/02/09 13:50:47 by slampine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	int	temp;

	if (stack == NULL || stack->next == NULL )
		return ;
	temp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = temp;
}

void	push(t_stack **src, t_stack **dest)
{
	t_stack	*temp;

	if (*src == NULL)
		return ;
	temp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = temp;
}

void	rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*tail;

	if (!(*stack) || (*stack)->next == NULL)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	tail = stack_last(*stack);
	temp->next = NULL;
	tail->next = temp;
}

void	reverse_rotate(t_stack **stack)
{
	t_stack	*tail;
	t_stack	*temp;
	t_stack	*before_tail;

	if (!(*stack) || (*stack)->next == NULL)
		return ;
	temp = *stack;
	tail = stack_last(*stack);
	before_tail = second_last(*stack);
	*stack = tail;
	(*stack)->next = temp;
	before_tail->next = NULL;
}
