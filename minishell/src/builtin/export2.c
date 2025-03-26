/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:36:48 by ruzhang           #+#    #+#             */
/*   Updated: 2025/03/26 22:59:18 by ruzhang          ###   ########.fr       */
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

void	duplicate_envlst(t_env *envlst, t_env **new)
{
	if (!envlst)
		return ;
	while (envlst)
	{
		update_envlst(new, envlst->key, envlst->value, 1);
		envlst = envlst->next;
	}
}

/*
Function to print result of export
Using merge_sort to sort the list
*/
void	export_list(t_env *envlst)
{
	t_env	*tmp;
	t_env	*temp;

	tmp = NULL;
	duplicate_envlst(envlst, &tmp);
	temp = merge_sort(tmp);
	tmp = temp;
	while (tmp)
	{
		if (ft_strcmp(tmp->key, "_"))
		{
			ft_putstr_fd("declare -x ", STDOUT_FILENO);
			ft_putstr_fd(tmp->key, STDOUT_FILENO);
			if (tmp->value)
			{
				ft_putstr_fd("=\"", STDOUT_FILENO);
				ft_putstr_fd(tmp->value, STDOUT_FILENO);
				ft_putendl_fd("\"", STDOUT_FILENO);
			}
			else
				write(1, "\n", 1);
		}
		tmp = tmp->next;
	}
	free_envlst(temp);
}
