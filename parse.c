#include "main.h"
/**
 * parse_input - tokenizes a string
 * @user_input: string
 * Return: tokenized string
 */
char **parse_input(char *user_input)
{
	char **user_input_array, *start_to_write = user_input, *file_path = "/bin/";
	int i = 0, j, len;

	user_input_array = malloc(sizeof(char *) * (numWords(user_input) + 1));
	if (!user_input_array)
		return (0);
	while (*start_to_write)
	{ 
		start_to_write = skipSpaces(start_to_write);
		len = wordlen(start_to_write);
		user_input_array[i] = i == 0 ? malloc(len + 6) : malloc(len + 1); /* find the executable */
		if (!user_input_array[i])
		{
			for (j = i; j > 0; j--)
				free(user_input_array[j]);
			free(user_input_array);
			return (0);
		}
		if (i == 0)
		{
			_strcpyp(user_input_array[i], file_path);
			_strcat(user_input_array[i], start_to_write);
		}
		else
			_strcpyp(user_input_array[i], start_to_write); 
		start_to_write += len;
		i++;
	}
	user_input_array[i] = NULL;
	return (user_input_array);
}
/**
 * _getline - gets a line of input from a file stream
 * @lineptr: pointer to array of words
 * @n: pointer to array containing lenght of buffer
 * @stream: file stream
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	return (0);
}
