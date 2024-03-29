#include "shell.h"

/**
 * history_list - Entry point
 * Description: displays the history list, one command by line, preceded
 * with line numbers, starting at 0.
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 *  Return: Always 0
 */

int history_list(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - Entry point
 * Description: sets alias to string
 * @info: parameter struct
 * @str: the string alias
 * Return: Always 0 on success, 1 on error
 */

int unset_alias(info_t *info, char *str)
{
	char *p, c;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = c;
	return (ret);
}

/**
 * set_alias - Entry point
 * Description: sets alias to string
 * @info: parameter struct
 * @str: the string alias
 * Return: Always 0 on success, 1 on error
 */

int set_alias(info_t *info, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - Entry point
 * Description: prints an alias string
 * @node: the alias node
 * Return: Always 0 on success, 1 on error
 */

int print_alias(list_t *node)
{
	char *p = NULL, *q = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (q = node->str; q <= p; q++)
			_putchar(*q);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * my_alias - mimics the alias builtin (man alias)
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int my_alias(info_t *info)
{
	int n = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (n = 1; info->argv[n]; n++)
	{
		p = _strchr(info->argv[n], '=');
		if (p)
			set_alias(info, info->argv[n]);
		else
			print_alias(node_starts_with(info->alias, info->argv[n], '='));
	}

	return (0);
}
