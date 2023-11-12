#include "main.h"
/**
 * _strcpy - copy a string from on location to another
 * @dest: the destination to copy to
 * @src: the string to be copied
 * Return: a pointer to the destination or null
*/

char *_strcpy(char *dest, const char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	return (dest);
}

/**
 * tokenize_str -convert a string to an array of tokens separated by a space
 * @str: the string to be tokenized
 * @str_arr: an array holding the tokens produced
 * @max: the size of the resultant array
 * Return: nothing
*/
void tokenize_str(const char *str, char *str_arr[], int max)
{
	char *str_copy = _strcpy((char *)malloc(strlen(str) + 1), str);

	if (str_copy == NULL)
	{
		perror("malloc");
		return;
	}

	char delim[] = " ";
	char *token = strtok(str_copy, delim);
	int token_count = 0;

	while (token != NULL && token_count < max)
	{
		str_arr[token_count] = _strcpy((char *)malloc(strlen(token) + 1), token);
		if (str_arr[token_count] == NULL)
		{
			perror("malloc");
			break;
		}

		token = strtok(NULL, delim);
		token_count++;
	}

	free(str_copy);

	for (int i = token_count; i < max; i++)
		str_arr[i] = NULL;
}
