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
    t_command *cmd = malloc(sizeof(t_command));

    cmd->args = calloc(num_args + 1, sizeof(char *));

    for (int i = 0; i < num_args; i++) {
        cmd->args[i] = strdup(args[i]);
    }

    cmd->next = NULL;
    cmd->redirections = redirs;
    return (cmd);
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

t_pipeline *parse_pipeline(void)
{
    t_pipeline	*pipeline = malloc(sizeof(t_pipeline));

	t_redir		*redir_in = create_redirection(RED_IN, "Makefile");
	// t_redir		*redir_out = create_redirection(RED_OUT, "output.txt");
	// t_redir		*redir_append = create_redirection(APPEND, "append.txt");

	// redir_in->next = redir_out;
	// redir_out->next = redir_append;

    char		*args1[] = {"exit", "9", NULL};
	t_redir		*redir1 = redir_in;
    t_command	*cmd1 = create_command(args1, 1, redir1);


    char *args2[] = {"ls", "-l", NULL};
    t_command *cmd2 = create_command(args2, 1, NULL);
	pipeline->cmd = cmd1;

	cmd1->next = cmd2;
	pipeline->num_cmds = 2;

	return pipeline;
}

int main(int argc, char **argv, char **envp)
{
	t_program minishell = {NULL, envp, NULL, 0};
	init_env(&minishell); // set envlst

	t_pipeline *pipeline;

	// char *input = "echo hello";
	// printf("------input------\n");
	// printf("%s\n", input);
	// printf("----------------\n\n");

	pipeline = parse_pipeline();
	process_pipeline(pipeline, &minishell);

	// free_lst(minishell.envlst);
	// free_pipeline(pipeline);
	// // Process the pipeline (execute commands)
	// process_pipeline(pipeline, &minishell, &pipex);

	// // Clean up allocated memory
	// free_pipeline(pipeline);
	// free_lex_list(minishell.lex_list);

	return (minishell.exit);
}
