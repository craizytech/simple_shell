#include "main.h"
/**
* find_the_path - an pointer that tries to access the given path using x_OK
* @command: the given input by user
* @path: the array of pointers to the desired executable file
* Return: give NULL value on success
*/
char *find_the_path(char *command, char *path[])
{
	char exec_path[BUFF_SIZE];
	int i;

	if (access(command, X_OK) == 0)
		return (command);

	for (i = 0; path[i] != NULL; i++)
	{
		snprintf(exec_path, sizeof(exec_path), "%s/%s", path[i], command);
		if (access(exec_path, X_OK) == 0)
		{
			return (strdup_static(exec_path));
		}

	}
	return (NULL);
}

/**
 * print_env - print out the environment variables
 * @env: environment
 * Return: nothing
 */
void print_env(char **env)
{
	int i;

	if (env == NULL)
		return;

	for (i = 0; env[i] != NULL; i++)
		_print_str(env[i]);
}
