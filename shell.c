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
 * main - entry point of thr program
 * Return: 0
 */
int main(void)
{
	char *prompt = "$ ", *buf, *ptr = prompt, **arg_tokens;
	char **env = {NULL};
	size_t n = 0, m = 0;
	int i, j;
	pid_t my_pid;

	while (1)
	{
		while (*ptr)
			_putchar(*(ptr++));
		buf = malloc(BUFSIZ);
		n = read(STDIN_FILENO, buf, BUFSIZE);
		if (n == -1)
			return (1);
		buf[n - 1] = '\0'; 
		arg_tokens = parse_input(buf); /* check if parse_input equals to 0 */
		for (i = 0; i < numWords(buf); i++)
			printf("%s", arg_tokens[i]);
		my_pid = fork();
		if (my_pid == 0)
		{
			if ((execve(arg_tokens[0], arg_tokens, env)) == -1)
				perror("execve");
		}
		wait(NULL);
		free(buf);
		j = i;
		while (j > 0)
			free(arg_tokens[j--]);
		free(arg_tokens);
		ptr = prompt;
	}
	return (0);
}
