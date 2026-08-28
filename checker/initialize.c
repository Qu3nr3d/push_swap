/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akacpere <akacpere@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 20:35:31 by akacpere          #+#    #+#             */
/*   Updated: 2026/08/28 15:53:44 by akacpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	initialize_stacks_and_operation(t_stack *a, t_stack *b, char **opr)
{
	a->first_node = NULL;
	a->last_node = NULL;
	a->size = 0;
	b->first_node = NULL;
	b->last_node = NULL;
	b->size = 0;
	*opr = NULL;
}
