#include "main.h"
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
		{NULL, NULL}
	};
	int i = 0;

	while (interpreted_command[i].str)
	{
		if ((_strcmp(arg_command, interpreted_command[i].str)))
			return (interpreted_command[i].func_ptr);
		i++;
	}
	return (interpreted_command[i].func_ptr);
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
	if(!env[i])
		return (0);
	_strcpy(env[i], env_key);
	_strcat(env[i], "=");
	_strcat(env[i], env_value);
	i++;
	env[i] = NULL;
	return (1);
}
