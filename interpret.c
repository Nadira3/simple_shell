#include "main.h"
/**
 * _strncmp - compares to string to check if they are an exact match
 * @str1: first string
 * @str2: second string
 * @len: String length
 * Return: 1 if strings match, otherwise 0
 */
int _strncmp(char *str1, char *str2, size_t len)
{
	char *ptr1 = str1, *ptr2 = str2;
	size_t i = 0;

	if (ptr1 && ptr2)
	{
		while (i < len)
		{
			if (*ptr2 != *ptr1)
				return (1);
			ptr1++;
			ptr2++;
			i++;
		}
	}
	return (0);
}
/**
 * _strcmp - compares to string to check if they are an exact match
 * @str1: first string
 * @str2: second string
 * Return: 1 if strings match, otherwise 0
 */
int _strcmp(char *str1, char *str2)
{
	char *ptr1 = str1, *ptr2 = str2;

	if (!str1 || !str2)
		return (0);
	if (ptr1 && ptr2)
	{
		while (*ptr1 || *ptr2)
		{
			if (*ptr2 != *ptr1)
				return (0);
			ptr1++;
			ptr2++;
		}
	}
	return (1);
}
/**
 * setenv_func - setenv builtin implementation
 * @arg_tokens: array of arguments
 * Return: char
 */
char setenv_func(char **arg_tokens)
{
	char *env_key = arg_tokens[1], *env_value = arg_tokens[2], *env_ptr;
	char **env = environ;
	size_t i = 0, value_len = _strlen(env_value), key_len = _strlen(env_key);

	if (!env_key || !env_value)
		return (0);
	while (env[i])
	{
		if (!(_strncmp(env_key, env[i], key_len)))
		{
			env_ptr = env[i] + key_len + 1;
			_strcpy(env_ptr, env_value);
		}
		i++;
	}
	env[i] = malloc(key_len + value_len + 3);
	if (!env[i])
		return (0);
	_strcpy(env[i], env_key);
	_strcat(env[i], "=");
	_strcat(env[i], env_value);
	i++;
	env[i] = NULL;
	return (1);
}

/**
 * exitcheck - exit builtin implementation
 * @arg_tokens: array of arguments
 * @buf: buffer containing input stream
 * @flag: checks for the return value of exit
 * Return: 0 if no argument is passed, argument valie otherwise
 */
int exitcheck(char **arg_tokens, char *buf, int *flag)
{
	int j;
	char *err = "./hsh: 1: exit: Illegal number: ";

	if (_strcmp(arg_tokens[0], "exit"))
	{
		if (arg_tokens[1] != NULL)
		{
			if (arg_tokens[1][0] != '-' && _isnumber(arg_tokens[1]))
			{
				j = _atoi(arg_tokens[1]);
				free_buf(arg_tokens);
				free(buf);
				exit(j);
			}
			else
			{
				write(STDERR_FILENO, err, _strlen(err));
				write(STDERR_FILENO, arg_tokens[1], _strlen(arg_tokens[1]));
				write(STDERR_FILENO, "\n", 1);
				free_buf(arg_tokens);
				free(buf);
				exit(2);
			}
		}
		free(buf);
		free_buf(arg_tokens);
		*flag = 1;
		return (1);
	}
	return (0);
}
/**
 * interpret_func - interpretes the tokenized string by separating into
 * command and arguments and finding its corresponding path and/or
 * executable if it exists
 * @arg_command: array of command-line input in tokenized form
 * Return: pointer to built-in function if present or NULL
 */
char (*interpret_func(char *arg_command))(char **arg)
{
	var_func interpreted_command[] = {
		{"setenv", setenv_func},
		{"env", env_func},
		{NULL, NULL}};
	int i = 0;

	while (interpreted_command[i].str)
	{
		if ((_strcmp(arg_command, interpreted_command[i].str)))
			return (interpreted_command[i].func_ptr);
		i++;
	}
	return (interpreted_command[i].func_ptr);
}
