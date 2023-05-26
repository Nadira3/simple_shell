#include "main.h"

/**
 * sig_handler - Handle signal
 * @signum: Signal number
 */
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
 * @ac: Argument count
 * @av: Argument value
 * @env: Environment to use
 * Return: 0
 */
int main(int ac __attribute__((unused)), char **av, char **env)
{
	int i, n = 0, j, flag = 0, is_terminal = isatty(STDIN_FILENO), exit_ = 0;
	char *p = "$ ", **arg = NULL, (*fun)(char **arg), *name = av[0], *pth = NULL;
	size_t arr_size = 0;

	signal(SIGINT, sig_handler);
	buf = NULL;
	while (1)
	{
		if (is_terminal)
			_puts(p);
		n = getline(&buf, &arr_size, stdin);
		getlinecheck(n, buf);
		if (bufcheck(buf))
			continue;
		buf[n - 1] = '\0';
		arg = parse_input(buf);
		if (!arg)
			perror(name);
		i = num_words(buf);
		pth = path(arg[0]);
		j = exitcheck(arg, buf, i, &flag);
		if (j)
			return (flag ? exit_ : j);
		if (!pth)
		{
			fun = interpret_func(arg[0]);
			if (fun)
				fun(arg);
			else
				perror(name);
		}
		else
			exit_ = execute(pth, arg, env);
		free(pth);
		free_buf(arg, i);
	}
	free(buf);
	return (0);
}
/**
 * getlinecheck - checks the return value of getline
 * @n: return value
 * @buf: memory management
 */
void getlinecheck(int n, char *buf)
{
	if (n == -1)
	{
		free(buf);
		exit(EXIT_SUCCESS);
	}
}
/**
 * get_pid_and_return_value - Expand $$ and $? variable arguments
 * @commandpattern: Variable pattern to expand
 *
 * Return: Int represent parent ID or last return value
 */
int get_pid_and_return_value(char *commandpattern)
{
	if (_strcmp(commandpattern, "$$"))
	{
		return (getppid());
	}
	else if (_strcmp(commandpattern, "$?"))
	{
		return (0);
	}
	return (1);
}
