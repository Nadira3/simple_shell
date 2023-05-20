#include "main.h"
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
 *
char (*interpret_func(char *arg_command))(char *arg)
{
	var_func interpreted_command[] = {
		{"cd", cd_func},
		{"exit", exit_func},
		{"setenv", setenv_func},
		{"unsetenv", unsetenv_func},
		{NULL, NULL}
	};
	int i = 0;

	while (interpreted_command[i].str)
	{
//		if (!(_strcmp(arg_command, interpreted_command[i].str)))
			return (interpreted_command[i].func_ptr);
	}
	return (interpreted_command[i].func_ptr);
}
char *setenv_func(char *arg)
{
}*/
