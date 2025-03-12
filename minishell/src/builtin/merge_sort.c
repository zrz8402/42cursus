/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:36:48 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/12 18:52:29 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*find_middle(t_env *envlst)
{
	t_env	*slow;
	t_env	*fast;

	if (!envlst)
		return (NULL);
	slow = envlst;
	fast = envlst->next;
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return (slow);
}

t_env	*merge(t_env *left, t_env *right)
{
	t_env	dummy;
	t_env	*tail;

	tail = &dummy;
	dummy.next = NULL;
	while (left && right)
	{
		if (ft_strcmp(left->key, right->key) <= 0)
		{
			tail->next = left;
			left = left->next;
		}
		else
		{
			tail->next = right;
			right = right->next;			
		}
		tail = tail->next;
	}
	if (left)
		tail->next = left;
	if (right)
		tail->next = right;
	return (dummy.next);
}

t_env	*merge_sort(t_env *envlst)
{
	t_env	*mid;
	t_env	*left;
	t_env	*right;

	if (!envlst || !envlst->next)
		return (envlst);
	mid = find_middle(envlst);
	left = envlst;
	right = mid->next;
	mid->next = NULL;
	
	left = merge_sort(left);
	right = merge_sort(right);
	return (merge(left, right));
}
