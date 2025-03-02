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
	t_env	*new;

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
	t_env	*tmp;

	if (append)
	{
		append_node(&minishell->envlst, create_node(key, value));
		return ;
	}
	tmp = minishell->envlst;
	while (tmp)
	{
		if (ft_strncmp(key, tmp->key, ft_strlen(key)) == 0)
		{
			if (value)
			{
				free(tmp->value);
				tmp->value = ft_strdup(value);
			}
			return ;
		}
		tmp = tmp->next;
	}
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
		{
			ft_putstr_fd(tmp->key, 1);
			ft_putstr_fd("=", 1);
			ft_putstr_fd(tmp->value, 1);
			ft_putstr_fd("\n", 1);
		}
		tmp = tmp->next;
	}
	return (0);
}

char	*get_var_value(char *key, t_env *envlst)
{
	while (envlst)
	{
		if (ft_strncmp(key, envlst->key, ft_strlen(key)) == 0)
			return (envlst->value);
		envlst = envlst->next;
	}
	return (NULL);
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

int	cd_home(t_program *minishell)
{
	char	*home;

	update_envlst(minishell, "OLDPWD", get_var_value("PWD", minishell->envlst), 0);
	home = get_var_value("HOME", minishell->envlst);
	if (!home)
	{
		ft_putstr_fd("minishell: cd: HOME not set\n", 2);
		return (1);
	}
	if (chdir(home) != 0)
	{
		ft_putstr_fd("chdir failed", 2);
		return (1);
	}
	update_envlst(minishell, "PWD", home, 0);
	return (0);
}

int	cd_pwd(t_program *minishell)
{
	char	*cwd;
	char	buf[1024];

	cwd = getcwd(buf, sizeof(buf));
	update_envlst(minishell, "PWD", cwd, 0);
	return (0);
}

int	builtin_cd(t_command *cmd, t_program *minishell)
{
	if (!cmd->args[1])
		return (cd_home(minishell));
	if (cmd->args[1])
	{	
		if (cmd->args[2])
		{
			ft_putstr_fd("minishell: cd: too many arguments\n", 2);
			return (1);
		}
		if (chdir(cmd->args[1]) != 0)
		{
			ft_putstr_fd("minishell: cd: ", 2);
			ft_putstr_fd(cmd->args[1], 2);
			ft_putstr_fd(": No such file or directory\n", 2);
			return (1);		
		}
		update_envlst(minishell, "OLDPWD", get_var_value("PWD", minishell->envlst), 0);
		cd_pwd(minishell);
	}
	return (0);
}
