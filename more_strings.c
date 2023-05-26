#include "main.h"
/**
 * _strtok - tokenizes a string
 * @str: string to be separated
 * @delim: list of characters used to separate strings
 * Return: pointer to tokenized string
 */
char *_strtok(char *str, char *delim)
{
	static char *ptr;
	int i, j;
	int str_len, delim_len;
	int found_delim = 0;

	if (str != NULL)
		ptr = str;
	else
	{
		if (ptr == NULL)
			return (NULL);
		str = ptr;
	}
	str_len = _strlen(str);
	delim_len = _strlen(delim);

	for (i = 0; i < str_len; i++)
	{
		for (j = 0; j < delim_len; j++)
		{
			if (str[i] == delim[j])
			{
				str[i] = '\0';
				found_delim = 1;
				break;
			}
		}
		if (found_delim)
		{
			found_delim = 0;
			break;
		}
	}

	ptr = (i < str_len) ? &str[i + 1] : (NULL);
	return (str);
}

/**
 * _strdup - returns a pointer to a newly allocated
 * space in memory
 * @str: string
 * Return: character pointer
 */
char *_strdup(char *str)
{
	int i, j;
	char *str1;

	if (str == NULL)
		return (NULL);
	i = _strlen(str);
	str1 = malloc(i + 1);
	if (str1 == NULL)
		return (NULL);
	for (j = 0; j < i; j++)
		str1[j] = str[j];
	str1[j] = '\0';
	return (str1);
}
/**
 * env_func - prints the environment variables
 * @arg: argument tokens
 * Return: 0 because its not necessary
 */
char env_func(char **arg)
{
	(void)arg;
	char **env_ = environ;
	int i;

	for (i = 0; env_[i]; i++)
		_puts(env_[i]);
	return (0);
}
