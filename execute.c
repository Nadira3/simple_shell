#include "main.h"
/**
 * free_buf - frees the array of command-argument pair
 * @buf: array
 * @size: size of array
 */
void free_buf(char **buf, int size)
{
	int j = size;

	while (j >= 0)
		free(buf[j--]);
	free(buf);
}
/**
 * bufcheck - checks if the buffer is empty
 * @buf: buffer
 * Return: 1 if buffer is empty, 0 otherwise
 */
int bufcheck(char *buf)
{
	if (*buf == '\n' || *(skip_spaces(buf)) == '\n')
	{
		free(buf);
		return (1);
	}
	return (0);
}
/**
 * readcheck - checks the return value of read
 * @n: number of bytes read from the file stream
 * @buf: array containing input read from file
 * @is_terminal: value to determine if input is from stdin or pipe
 * Return: -1 if read is unsucessful, 1 if read is sucessful
 * but EOF is reached, 0 otherwise.
 */
int readcheck(int n, char *buf, int is_terminal)
{
	if (n <= 0)
	{
		if (n == 0 && is_terminal)
			_putchar('\n');
		free(buf);
		return (!n ? 1 : -1);
	}
	return (0);
}
/**
 * exitcheck - exit builtin implementation
 * @arg_tokens: array of arguments
 * @buf: buffer containing input stream
 * @i: size of buffer
 * @flag: checks for the return value of exit
 * Return: 0 if no argument is passed, argument valie otherwise
 */
int exitcheck(char **arg_tokens, char *buf, int i, int *flag)
{
	int j;

	if (_strcmp(arg_tokens[0], "exit"))
	{
		if (arg_tokens[1] != NULL)
		{
			j = _atoi(arg_tokens[1]);
			free_buf(arg_tokens, i);
			free(buf);
			return (j);
		}
		free(buf);
		free_buf(arg_tokens, i);
		*flag = 1;
		return (1);
	}
	return (0);
}
/**
 * execute - handles command execution
 * @filepath: filepath
 * @arg_tokens: array of arguments
 * @env: enviroment variable list
 * Return: 0 if execve is unsuccessful, 1 otherwise
 */
int execute(char *filepath, char **arg_tokens, char **env)
{
	pid_t my_pid;

	if (filepath)
	{
		my_pid = fork();
		if (my_pid == 0)
			if ((execve(filepath, arg_tokens, env) == -1))
				return (0);
		wait(NULL);
		return (1);
	}
	return (1);
}

/**
 * changedir - Change directory to given path
 * @path: pointer to new path
 * Return: New path
 */
char *changedir(char *path)
{
	char *prev_dir = NULL;
	if (*path == '-')
	{
		prev_dir = _getenv("PWD");
		if (!chdir(prev_dir))
			return (1);
	}
	else
	{
		char *currentpath = getcwd(NULL, 128);
		setenv_func(&currentpath);
		if (!chdir(path))
			return (1);
	}
	return (0);
}

/**
 * get_pid_and_return_value - Expand $$ and $? variable arguments
 * @commandpattern: Variable pattern to expand
 * Return: Int represent parent ID or last return value
 */
int get_pid_and_return_value(char *commandpattern)
{
	if (_strcmp(commandpattern, "$$"))
	{
		pid_t parentpid = getppid();
		return (parentpid);
	}
	else if (_strcmp(commandpattern, "$?"))
	{
		int processreturnvalue;
		return (processreturnvalue);
	}
	return (1);
}