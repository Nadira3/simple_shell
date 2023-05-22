#include "main.h"
/**
 * skip_spaces - skips spaces
 * @str: string argument
 * Return: pointer to next character in the string
 */
char *skip_spaces(char *str)
{
	if (str)
	{
		while (*str)
		{
			if (*str != ' ')
				break;
			str++;
		}
	}
	return (str);
}

/**
 * num_words - finds the number of words in a string
 * @str: string
 * Return: number of words
 */
int num_words(char *str)
{
	int i = 0;
	char *ptr;

	if (str)
	{
		ptr = str;
		while (*ptr)
		{
			if (*ptr != ' ' && (*(ptr + 1) == ' ' || *(ptr + 1) == '\0'))
				i++;
			ptr++;
		}
	}
	return (i);
}

/**
 * _atoi - changes strings to to integers
 * @s: string pointer
 * Return: integer
 */
int _atoi(char *s)
{
	int i, minus = 0;
	int n = _strlen(s);
	unsigned int num = 0;

	for (i = 0; i < n; i++)
	{
		if (s[i] == 45)
			minus++;
		if (s[i] >= 48 && s[i] < 58)
		{
			num = num * 10 + (s[i] - 48);
			if (!(s[i + 1] >= 48 && s[i + 1] < 58))
				break;
		}
	}
	if (!(minus % 2))
		return (num);
	else
		return (-num);
}
/**
 * _getenv - gets the value of an environment variable using its key
 * @key: key of environment variable
 * Return: pointer to value of key
 */
char* _getenv(char* key) 
{
	extern char **environ;
	char* env_var;
	char* var_name;
	char* value;
	int i, j, key_len, value_len, k = 0;

	if (key == NULL)
		return NULL;

	for (i = 0; environ[i] != NULL; i++) 
	{
		env_var = environ[i];
		key_len = strlen(key);
		var_name = malloc(key_len + 1);
	/* a strncmp works better here but i forgot, cant rewrite, lol */
		if (!var_name)
			return (0);
		for (j = 0; j < key_len; j++)
			var_name[j] = environ[i][j];
		var_name[j++] = '\0';
		if (var_name != NULL && _strcmp(var_name, key) == 1)
		{
			value_len = strlen(environ[i]);
			value = malloc(value_len + 1);
			if (!value)
				return (0);
			while (j <= value_len)
				value[k++] = environ[i][j++];
			value[k] = '\0';
			free(var_name);
			return (value);
		}
		free(var_name);
	}
	return (NULL);
}
