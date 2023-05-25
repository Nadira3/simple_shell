#include "main.h"
char *buf;
void sig_handler(int signum)
{
	(void)signum;

	signal(SIGINT, sig_handler);
	free(buf);
	_putchar(10);
	exit(EXIT_SUCCESS);
}
/**
 * main - entry point of thr program
 * Return: 0
 */
int main(int ac, char **av, char **env)
{
	int i, j, flag = 0, is_terminal = isatty(STDIN_FILENO);
	char *prompt = "$ ", *ptr = prompt, **arg_tokens = NULL;
	char (*builtin_func)(char **arg), *prog_name = av[0], *filepath = NULL;
	ssize_t n = 0;
	size_t arr_size = 0;
	(void)ac;

	signal(SIGINT, sig_handler);
	buf = NULL;
	while (1)
	{
		if (is_terminal)
			_puts(ptr);
		n = getline(&buf, &arr_size, stdin);
		if (n == -1)
		{
			free(buf);
			exit(EXIT_SUCCESS);
		}
		if (bufcheck(buf))
			continue;
		buf[n - 1] = '\0';
		if (!(arg_tokens = parse_input(buf)))
			perror(prog_name);
		i = num_words(buf);
		filepath = path(arg_tokens[0]);
		j = exitcheck(arg_tokens, buf, i, &flag);
		if (j)
			return (flag ? 0 : j);
		if (filepath)
		{
			if (!(execute(filepath, arg_tokens, env)))
				perror(prog_name);
		}
		else
		{
			builtin_func = interpret_func(arg_tokens[0]);
			if (builtin_func)
				builtin_func(arg_tokens);
			else
			{
				free_buf(arg_tokens, i);
				free(buf);
				perror(prog_name);
				exit(EXIT_FAILURE);
			}
		}
		free(filepath);
		ptr = prompt;
		free_buf(arg_tokens, i);
	}
	free(buf);
	return (0);
}
