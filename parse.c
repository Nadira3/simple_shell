#include "main.h"

/**
 * path - Path to navigate to
 * @command: Path to redirect to
 * Return: NULL if error, path if not
 */
char *path(char *command)
{
	char *filepath = _getenv("PATH"), *env_path = NULL;
	char *path_copy = _strdup(filepath), *token = _strtok(path_copy, ":");
	size_t env_path_len;

	if (!command)
		return (NULL);
	while (token != NULL)
	{
		if (*command == '/' || *command == '.')
		{
			free(filepath);
			free(path_copy);
			env_path = access(command, X_OK) != 0 ? NULL : _strdup(command);
			return (env_path);
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
		if (*start_to_write == '\0' || *start_to_write == '#')
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
