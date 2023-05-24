#include "main.h"
void sig_handler(int signum)
{
	char *prompt = "\n$ ";

	(void)signum;

	signal(SIGINT, sig_handler);
	write(STDIN_FILENO, prompt, 3);

}
/**
 * main - entry point of thr program
 * Return: 0
 */
int main(int ac, char **av, char **env)
{
	int i, j, flag = 0, is_terminal = isatty(STDIN_FILENO);
	char *prompt = "$ ", *buf = NULL, *ptr = prompt, **arg_tokens = NULL;
	char (*builtin_func)(char **arg), *prog_name = av[0], *filepath = NULL;
	size_t n = 0, arr_size = 0;
	(void)ac;

	signal(SIGINT, sig_handler);
	while (1)
	{
		if (is_terminal)
			_puts(ptr);
		n = getline(&buf, &arr_size, stdin);
		if (n == -1)
		{
			free(buf);
			perror("getline");
			exit(EXIT_FAILURE);
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
				perror(prog_name);
		}
		if (!(_strcmp(filepath, arg_tokens[0])))
			free(filepath);
		ptr = prompt;
		free_buf(arg_tokens, i);
	}
	free(buf);
	return (0);
}
