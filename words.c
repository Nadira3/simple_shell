#include "main.h"
/**
 * skipSpaces - skips spaces
 * @str: string argument
 * Return: pointer to next character in the string
 */
char *skipSpaces(char *str)
{
	while (*str)
	{
		if (*str != ' ')
			break;
		str++;
	}
	return (str);
}
/**
 * numWords - finds the number of words in a string
 * @str: string
 * Return: number of words
 */
int numWords(char *str)
{
	int i = 0;
	char *ptr = str;

	while (*ptr)
	{
		if (*ptr != ' ' && (*(ptr + 1) == ' ' || *(ptr + 1) == '\0'))
			i++;
		ptr++;
	}
	return (i);
}
