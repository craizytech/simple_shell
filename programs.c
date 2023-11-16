#include "main.h"

/**
 * run_code - runs the entered command
 * @str_arr: an array of arguments
 * @envp: the environment variables
 * @pid: process id
 * Return: 0 on success
*/

int run_code(char **str_arr, char **envp, pid_t pid)
{
	int i = 0;
	char *path[MAX_ARGS], *path_var, *executable_path;


	if (executable_path != NULL)
	{
		pid = fork();

		if (pid < 0)
		{
			perror("Process execution failure");
			return (EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			execve(executable_path, str_arr, envp);
			perror("Execve failure");
			exit(EXIT_FAILURE);
		}
		free(executable_path);
		wait(NULL);
	}

	return (0);
}
