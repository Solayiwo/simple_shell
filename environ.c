#include "shell.h"

/**
 * my_env - Entry point
 * Description: prints the current environment
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */

int my_env(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * *get_env - Entry point
 * Description: gets the value of an environ variable
 * @info: Structure containing potential arguments. Used to maintain
 * @name: env var name
 * Return: the value
 */

char *get_env(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * my_setenv - Entry point
 * Description: Initialize a new environment variable,
 * or modify an existing one
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 *  Return: Always 0
 */

int my_setenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * my_unsetenv - Entry point
 * Description: Remove an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */

int my_unsetenv(info_t *info)
{
	int n;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (n = 1; n <= info->argc; n++)
		_unsetenv(info, info->argv[n]);

	return (0);
}

/**
 * populate_env_list - Entry point
 * Description: populates env linked list
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */

int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t num;

	for (num = 0; environ[num]; num++)
		add_node_end(&node, environ[num], 0);
	info->env = node;
	return (0);
}
