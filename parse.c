#include "main.h"

char *path(char *command)
{
	char *filepath = _getenv("PATH"), *env_path = NULL;
	char *path_copy = _strdup(filepath), *token = _strtok(path_copy, ":");
	size_t env_path_len;

	while (token != NULL)
	{
		if (*command == '/')
		{
			free(filepath);
			free(path_copy);
			return (command);
		}
		env_path_len = _strlen(token) + _strlen(command) + 2;
		env_path = malloc(env_path_len);
		if (env_path == NULL)
		{
			free(filepath);
			free(path_copy);
			return (NULL);
		}
		_strcpy(env_path, token);
		_strcat(env_path, "/");
		_strcat(env_path, command);
		if (access(env_path, X_OK) == 0)
		{
			free(filepath);
			free(path_copy);
			return (env_path);
		}
		free(env_path);
		env_path = NULL;
		token = _strtok(NULL, ":");
	}
	free(path_copy);
	free(filepath);
	return (env_path);
}

/**
 * parse_input - tokenizes a string
 * @user_input: string
 * Return: tokenized string
 */
char **parse_input(char *user_input)
{
	char **user_input_array = NULL, *start_to_write = user_input;
	int i = 0, j, len;

	user_input_array = malloc(sizeof(char *) * (num_words(user_input) + 1));
	if (!user_input_array)
		return (0);
	while (*start_to_write)
	{ 
		start_to_write = skip_spaces(start_to_write);
		if (*start_to_write == '\0')
			break;
		len = wordlen(start_to_write);
		user_input_array[i] = malloc(len + 1); 
		if (!user_input_array[i])
		{
			for (j = i; j > 0; j--)
				free(user_input_array[j]);
			free(user_input_array);
			return (0);
		}
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
/**ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t num_copied = 0;
	
	if (*n <= 0)
		return (1);

	while (*stream != '\n')
	{
		**lineptr = *stream;
		*lineptr++;
		stream++;
		num_copied++;

		if (num_copied == *n)
		{
			char **temp_buf = malloc(*n);
			if (temp_buf == NULL)
				return (-1);

			size_t i = 0;
			// Save in temp_buf
			while (i < *n)
			{
				**temp_buf = **lineptr;
				*temp_buf++;
				*lineptr++;
				i++;
			}
			// Increase buff and copy from temp to buff
			
			**lineptr = malloc(*n * 2);

			if (lineptr == NULL)
				return (-1);

			size_t j = 0;
			while (j < n)
			{
				**lineptr = **temp_buf;
				*temp_buf++;
				*lineptr++;
				j++;
			}
			free(temp_buf);
		}
	}
	lineptr[num_copied + 1] = '\n';
	*n = num_copied;
	return (*n);
}*/
