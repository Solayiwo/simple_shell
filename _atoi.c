#include "shell.h"

/**
 * interactive_mode - Entry point
 * Description: returns true if shell is interactive mode
 * @mode: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */

int interactive_mode(info_t *mode)
{
	return (isatty(STDIN_FILENO) && mode->readfd <= 2);
}

/**
 * is_delimiter - Entry point
 * Description: checks if character is a delimiter
 * @n: character argument to check
 * @delim: delimiter string
 * Return: 1 if true, else 0
 */
int is_delimiter(char n, char *delim)
{
	while (*delim)
		if (*delim++ == n)
			return (1);
	return (0);
}

/**
 * _isalpha - Entry point
 * Description: checks for alphabetic character
 * @n: The character to input
 * Return: 1 if c is alphabetic, else 0.
 */

int _isalpha(int n)
{
	if ((n >= 'a' && n <= 'z') || (n >= 'A' && n <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - Entry point
 * Description: converts a string to an integer
 * @s: string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 */

int _atoi(char *s)
{
	int count, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (count = 0;  s[count] != '\0' && flag != 2; count++)
	{
		if (s[count] == '-')
			sign *= -1;

		if (s[count] >= '0' && s[count] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[count] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
