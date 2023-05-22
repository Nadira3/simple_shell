#include "main.h"
/**
 * _strlen - finds the length of a string
 * @str: string
 * Return: the length of the string
 */
int _strlen(char *str)
{
	if (!*str)
		return (0);
	return (1 + _strlen(str + 1));
}
/**
 * wordlen - finds the lengthbof a word in a string
 * @str: string
 * Return: the length of a word
 */
int wordlen(char *str)
{
	if (*str == ' ' || !*str)
		return (0);
	return (1 + wordlen(str + 1));
}
/**
 * _strcpy - copies the content of a str2 to str1
 * @str1: firsy string
 * @str2: second string
 * Return: str1
 */
char *_strcpy(char *str1, char *str2)
{
	char *ptr1 = str1, *ptr2 = str2;
	while (*ptr2)
	{
		*ptr1 = *ptr2;
		ptr1++;
		ptr2++;
	}
	*ptr1 = '\0';
	return (str1);
}
/**
 * _strcpyp - copies a word to a buffer
 * @str1: buffer
 * @str2: word pointer
 * Return: buffer
 */
char *_strcpyp(char *str1, char *str2)
{
	char *ptr1 = str1, *ptr2 = str2;
	while (*ptr2 && *ptr2 != ' ')
	{
		*ptr1 = *ptr2;
		ptr1++;
		ptr2++;
	}
	*ptr1 = '\0';
	return (str1);
}
/**
 * _strcat - concatenates a string
 * @str1: first string
 * @str2: second string
 * Return: str1
 */
char *_strcat(char *str1, char *str2)
{
	char *ptr1 = str1, *ptr2 = str2;

	while (*ptr1)
		ptr1++;
	_strcpyp(ptr1, ptr2);
	return (str1);
}
