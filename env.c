#include <stdio.h>
#include <string.h>
#include <stdlib.h>
extern char **environ;
typedef struct env_var
{
	char *key;
	char equals;
	char *value;
	struct env_var *next;
} env_vars;
env_vars *add_node_end(env_vars **head, char *key, char *value);
char *getvalue(char *env_i)
{
	int i = 0, value_len;
	char *value, *value_ptr;

	while (env_i[i] != '=')
		i++;
	value_ptr = &env_i[++i];
	value_len = strlen(value_ptr);
	value = malloc(value_len + 2);
	if (!value)
		return (0);
	strcpy(value, value_ptr);
	strcat(value, "\n");
	return (value);
}
char *getkey(char *env_i)
{
	int i  = 0;
	char *key;

	while (env_i[i] != '=')
		i++;
	key = malloc(i + 1);
	if (!key)
		return (0);
	i = 0;
	while (env_i[i] != '=')
	{
		key[i] = env_i[i];
		i++;
	}
	key[i] = '\0';
	return (key);
}
env_vars *make_env(char **env)
{
	env_vars *env_list = NULL;
	char *key, *value;
	int i = 0;

	env = environ;
	while (env[i])
	{
		key = getkey(env[i]);
		value = getvalue(env[i]);
		add_node_end(&env_list, key, value);
		i++;
		free(key);
		free(value);
	}
	return (env_list);

}
/**
 * list_len - finds the number of elements in a list
 * @h: pointer to list
 * Return: the number of elements
 */
int list_len(env_vars *h)
{
	int count = 0;

	if (h)
	{
		while (h)
		{
			count++;
			h = h->next;
		}
	}
	return (count);
}
/**
 * add_node_end - adds node to the end of a list
 * @head: pointer to list
 * @str: string to be copied
 * Return: pointer to new node
 */
env_vars *add_node_end(env_vars **head, char *key, char *value)
{
	env_vars *new;
	env_vars *temp;

	new = malloc(sizeof(env_vars));
	if (new == NULL)
		return (new);
	new->key = strdup(key);
	new->equals = '=';
	new->value = strdup(value);
	new->next = NULL;
	if (*head == NULL)
		*head = new;
	else
	{
		temp = *head;
		if (list_len(temp) > 1)
		{
			while (temp->next)
				temp = temp->next;
		}
		temp->next = new;
	}
	return (new);
}
int print_list(env_vars *h)
{
	int count = 0;
	env_vars *ptr;

	if (h)
	{
		ptr = (env_vars *)h;
		while (ptr)
		{
			count++;
			if (ptr->key == NULL || ptr->value == NULL)
				printf("[%d] %s\n", 0, "(nil)");
			else
				printf("%s%c%s", ptr->key, ptr->equals, ptr->value);
			ptr = ptr->next;
		}
	}
	return (count);
}
int main(void)
{
	char **env = environ;
	env_vars *envy = make_env(env);
	print_list(envy);
	return (0);
}
/**
 * setenv_func - setenv builtin implementation
 * @arg_tokens: array of arguments
 * Return: char
 *
char setenv_func(char **arg_tokens)
{
	size_t i = 0, value_len = _strlen(env_value), key_len = _strlen(env_key);
	char *env_key = arg_tokens[1], *env_value = arg_tokens[2], *env_ptr;
	env_vars *env_list = make_env(environ);
	env_vars *node = env_list;

	if (!env_key || !env_value)
		return (0);
	while (node != NULL)
	{
		if (strcmp(node->key, env_key) == 0) 
		{
			free(node->value);
			node->value = strdup(env_value);
			break;
		}
		node = node->next;
	}
	if (node == NULL)
		add_node_end(&env_list, env_key, env_value);
	environ = create_environ_array(env_list);

}*/
