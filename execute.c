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
	(void)buf;
	if (n <= 0)
	{
		if (n == 0 && is_terminal)
			_putchar('\n');
		return (-1);
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
	pid_t child_pid;
	int status, exit_status;

	if (filepath)
	{
		my_pid = fork();
		if (my_pid == 0)
		{
			if ((execve(filepath, arg_tokens, env) == -1))
				return (0);
		}
		else if (my_pid == -1)
		{
			return (0);
		}
		else
		{
			child_pid = waitpid(my_pid, &status, 0);
			if (child_pid == -1)
				return (0);
			if (WIFEXITED(status))
				exit_status = WEXITSTATUS(status);
			else if (WIFSIGNALED(status))
				exit_status = WTERMSIG(status);
		}
		return (exit_status);
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
			return (0);
	}
	else
	{
		char *currentpath = getcwd(NULL, 128);

		setenv_func(&currentpath);
		if (!chdir(path))
			return (0);
	}
	return (0);
}
