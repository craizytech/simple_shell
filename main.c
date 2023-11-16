#include "main.h"

/**
 * main - production environment
 * @argc: argument count
 * @argv: argument vector
 * @envp: environment variables
 * Return: 0
*/

int main(int argc, char const *argv[], char **envp)
{
	char *buff, *args_arr[MAX_ARGS];
	char *executable_path, *path[MAX_ARGS];
	size_t buffSize = BUFF_SIZE, characters;
	pid_t pid;

	(void) argc;
	(void) argv;
	buff = create_buff();
	if (isatty(STDIN_FILENO) == 0)
		return (EXIT_FAILURE);
	while (1)
	{
		printf("$ ");
		characters = getline(&buff, &buffSize, stdin);
		if (characters == 0)
			continue;
		remove_new_line(buff);
		tokenize_str(buff, args_arr, MAX_ARGS);
		executable_path = initialize_path(path, args_arr);
		printf("%s\n", executable_path);
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
				execve(executable_path, args_arr, envp);
				perror("Execve failure");
				exit(EXIT_FAILURE);
			}
			else
			{
				/*free(executable_path);*/
				wait(NULL);
			}
		}
		free(buff);
	}

	return (EXIT_SUCCESS);
}
