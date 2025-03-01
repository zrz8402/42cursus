#include "minishell.h"

void	init_env(t_program *minishell)
{
	int		i;
	char	*key;
	char	*value;
	char	*equal;

	if (!minishell->envp)
		return ;
	i = -1;
	while (minishell->envp[++i])
	{
		equal = ft_strchr(minishell->envp[i], '=');
		if (equal)
		{
			key = ft_substr(minishell->envp[i], 0, equal - minishell->envp[i]);
			value = ft_strdup(equal + 1);
			update_envlst(minishell, key, value, 1);
			free(value);
			free(key);
		}
	}
}

t_env	*create_node(char *key, char *value)
{
	t_env *new;

	new = (t_env *)ft_calloc(1, sizeof(t_env));
	if (!new)
		return (NULL);
	new->key = ft_strdup(key);
	if (value)
		new->value = ft_strdup(value);
	new->next = NULL;
	return (new);
}

void	append_node(t_env **envlst, t_env *new)
{
	t_env	*tmp;

	if (!*envlst)
	{
		*envlst = new;
		return ;
	}
	tmp = *envlst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	update_envlst(t_program *minishell, char *key, char *value, int append)
{
	if (append)
		append_node(&minishell->envlst, create_node(key, value));
}

void	free_lst(t_env *envlst)
{
	t_env *tmp;

	while (envlst)
	{
		tmp = envlst;
		envlst = envlst->next;
		free(tmp->key);
		if (tmp->value)
			free(tmp->value);
		free(tmp);
	}
}

int	builtin_env(t_command *cmd, t_program *minishell)
{
	t_env	*tmp;

	tmp = minishell->envlst;
	while (tmp)
	{
		if (tmp->value)
			printf("%s=%s\n", tmp->key, tmp->value);
		tmp = tmp->next;
	}
	return (0);
}

void	unset_var(t_env **envlst, char *key)
{
	t_env	*prev;
	t_env	*cur;

	prev = NULL;
	cur = *envlst;
	while (cur)
	{
		if (ft_strncmp(key, cur->key, ft_strlen(key)) == 0)
		{
			if (prev)
				prev->next = cur->next;
			else
				*envlst = cur->next;
			free(cur->key);
			free(cur->value);
			free(cur);
			return ;
		}
		prev = cur;
		cur = cur->next;
	}
}

int	builtin_unset(t_command *cmd, t_program *minishell)
{
	int	i;

	if (!cmd->args[1])
		return (0);
	i = 0;
	while (cmd->args[++i])
		unset_var(&minishell->envlst, cmd->args[i]);
	return (0);
}