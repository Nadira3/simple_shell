#include "main.h"
/**
 * _putchar - prints a character to standard output
 * @c: character
 * Return: 0
 */
int _putchar(char c)
{
	write(1, &c, 1);
	return (0);
}
/**
 * _puts - prints a string to standard output
 * @str: string
 * Return: 0
 */
int _puts(char *str)
{
	int i = 0;

	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
	return (0);
}
