#include "minishell.h"

t_redir	*create_redirection(enum e_ltype type, const char *file)
{
	t_redir	*redir = malloc(sizeof(t_redir));

	redir->type = type;
	redir->file = strdup(file);
	redir->heredoc_fd = -1;
	redir->next = NULL;

	return (redir);
}

t_command *create_command(char *args[], int num_args, t_redir *redirs)
{
	t_command	*cmd = malloc(sizeof(t_command));

	cmd->args = calloc(num_args + 1, sizeof(char *));

	for (int i = 0; i < num_args; i++)
		cmd->args[i] = strdup(args[i]);

	cmd->next = NULL;
	cmd->redirections = redirs;
	return cmd;
}

void free_pipeline(t_pipeline *pipeline)
{
	t_command	*cmd = pipeline->cmd, *tmp_cmd;
	t_redir		*redir, *tmp_redir;

	while (cmd) {
		tmp_cmd = cmd;
		cmd = cmd->next;

		if (tmp_cmd->args) {
			for (int i = 0; tmp_cmd->args[i] != NULL; i++) {
				free(tmp_cmd->args[i]);
			}
			free(tmp_cmd->args);
		}

		redir = tmp_cmd->redirections;
		while (redir) {
			tmp_redir = redir;
			redir = redir->next;
			free(tmp_redir->file);
			free(tmp_redir);
		}

		free(tmp_cmd);
	}
	free(pipeline);
}

t_pipeline *parse_pipeline(char *input)
{
	t_pipeline	*pipeline = malloc(sizeof(t_pipeline));
	char		*cmd_str, *cmd_args_str;
	char		*cmds[10];
	int			num_cmds = 0;
		
	// Split the input by '|'
	cmd_str = strtok(input, "|");
	while (cmd_str != NULL) {
		cmds[num_cmds++] = cmd_str;
		cmd_str = strtok(NULL, "|");
	}
		
	t_command *prev_cmd = NULL;

	// t_redir		*redir_in = create_redirection(RED_IN, "Makefile");
	// t_redir		*redir_out = create_redirection(RED_OUT, "output.txt");
	// t_redir		*redir_append = create_redirection(APPEND, "append.txt");

	// redir_in->next = redir_out;
	// redir_out->next = redir_append;


	// t_redir		*redir1 = redir_in;

	for (int i = 0; i < num_cmds; i++) {
		char *args[100];
		int num_args = 0;

		cmd_args_str = strtok(cmds[i], " ");
		while (cmd_args_str != NULL) {
			args[num_args++] = cmd_args_str;
			cmd_args_str = strtok(NULL, " ");
		}
		
		t_command *cmd = create_command(args, num_args, NULL);
		
		if (prev_cmd == NULL) {
			pipeline->cmd = cmd;
		} else {
			prev_cmd->next = cmd;
		}
		
		prev_cmd = cmd;
	}

	pipeline->num_cmds = num_cmds;
	return pipeline;
}

int	g_is_running = 1;

int	main(int argc, char **argv, char **envp)
{
	t_program	minishell = {NULL, envp, NULL, 0};
	t_pipeline	*pipeline;
	char		*input;

	init_env(&minishell);
	while (1)
	{
		setup_prompt_signal();
		input = readline("minishell$ ");
		if (!input)
		{
			free_lst(minishell.envlst);
			printf("exit\n");
			break;
		}
		if (*input)
			add_history(input);
		if (*input)
		{
			pipeline = parse_pipeline(input);
			process_pipeline(pipeline, &minishell);
			free(input);
		}
	}
	return (0);
}
