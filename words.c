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
