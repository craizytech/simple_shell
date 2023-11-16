#include "main.h"

/**
 * create_buff - create a string buffer
 * Return: pointer to the buffer or NULL
*/

char *create_buff()
{
	char *str = malloc(sizeof(char) * BUFF_SIZE);

	if (str == NULL)
		return (NULL);

	return (str);
}
/**
 * remove_new_line - remove a the new line character
 * @str: the string/ buffer
 * Return: nothing
*/
void remove_new_line(char *str)
{
	size_t len;

	len = strlen(str);

	if (len > 0 && str[len - 1] == '\n')
	{
		str[len - 1] = '\0';
	}
}

/**
 * initialize_path - get the full path to run a program
 * @path_var: path variable
 * @str_arr: an array of arguments
 * @path: the path
 * Return: a pointer to the full path created
*/
char *initialize_path(char *path_var, char *path[], char *str_arr[])
{
	size_t i = 0;
	char *executable_path, *path[MAX_ARGS];

	path_var = getenv("PATH");
	if (!path_var)
	{
		perror("Error");
		return (NULL);
	}

	path[i++] = strtok(path_var, ":");
	while ((path[i] = strtok(NULL, ":")) != NULL)
		i++;

	executable_path = find_the_path(str_arr[0], path);

	return (executable_path);
}
