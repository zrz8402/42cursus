#include "minishell.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#include <stdlib.h>
#include <string.h>

t_command *create_command(char *args[], int num_args) {
    t_command *cmd = malloc(sizeof(t_command));

    cmd->args = calloc(num_args + 1, sizeof(char *));

    for (int i = 0; i < num_args; i++) {
        cmd->args[i] = strdup(args[i]);
        if (!cmd->args[i]) {
            for (int j = 0; j < i; j++) {
                free(cmd->args[j]);
            }
            free(cmd->args);
            free(cmd);
            return NULL;
        }
    }

    cmd->next = NULL;
    cmd->redirections = NULL;
    return cmd;
}

t_pipeline *parse_pipeline(void) {
    t_pipeline *pipeline = malloc(sizeof(t_pipeline));
    if (!pipeline) {
        return NULL;
    }

    // Create first command "ls -l"
    char *args1[] = {"ls", "-l", NULL};
    t_command *cmd1 = create_command(args1, 2);
    if (!cmd1) {
        free(pipeline);
        return NULL;
    }

    // Create second command "cat"
    char *args2[] = {"cat", "Makefile", NULL};
    t_command *cmd2 = create_command(args2, 2);


	// char *args2[] = {"./ls", "-a", NULL};
    // t_command *cmd2 = create_command(args2, 2);

    // Connect cmd1 and cmd2 to form a pipeline
    pipeline->cmd = cmd1;
    cmd1->next = cmd2;
    pipeline->num_cmds = 2;

    return pipeline;
}

void free_pipeline(t_pipeline *pipeline) {
    t_command *cmd = pipeline->cmd, *tmp_cmd;
    
    while (cmd) {
        tmp_cmd = cmd;
        cmd = cmd->next;
        // free(tmp_cmd->args);
        free(tmp_cmd);
    }
    free(pipeline);
}

int main(int argc, char **argv, char **envp) {
    t_program minishell = {NULL, envp, NULL, 0, 0};
	init_env(&minishell); // set envlst

    t_pipeline *pipeline;
    t_pipex pipex = {0};

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

    return 0;
}
