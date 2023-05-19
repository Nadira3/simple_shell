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
	while (*str)
	{
		_putchar(*str);
		str++;
	}
	return (0);
}
/**
 * main - entry point of thr program
 * Return: 0
 */
int main(int ac, char **av, char **envp)
{
	char *prompt = "$ ", *buf, *ptr = prompt, **arg_tokens;
	char *prog_name = av[0];
	size_t n = 0;
	(void)ac;
	int i, j, is_terminal = isatty(STDIN_FILENO);
	pid_t my_pid; /* handle test case echo '/bin/ls' | ./shell */

	while (1)
	{
		if (is_terminal)
			_puts(ptr);
		if (!(buf = malloc(BUFSIZ)))
			return (-1);
		n = read(STDIN_FILENO, buf, BUFSIZE);
		if (n <= 0)
		{
			if (n == 0 && is_terminal)
				_putchar('\n');
			return (1);
		}
		buf[n - 1] = '\0';
		if (!(arg_tokens = parse_input(buf)))
			perror(prog_name);
		i = num_words(buf);
		if (access(arg_tokens[0], X_OK) != -1)
		{
			my_pid = fork();
			if (my_pid == 0)
				if ((execve(arg_tokens[0], arg_tokens, envp) == -1))
						perror(prog_name);
			wait(NULL);
		}
		else
			perror(prog_name);
		free(buf);
		j = i;
		while (j >= 0)
			free(arg_tokens[j--]);
		free(arg_tokens);
		ptr = prompt;
	}
	return (0);
}
