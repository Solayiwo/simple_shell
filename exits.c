#include "shell.h"

/**
 * *_strncpy - Entry point
 * Description: copies a string
 * @dest: the destination string to be copied to
 * @src: the source string
 * @n: the amount of characters to be copied
 * Return: the concatenated string
 */

char *_strncpy(char *dest, char *src, int n)
{
	int j, k;
	char *s = dest;

	j = 0;
	while (src[j] != '\0' && j < n - 1)
	{
		dest[j] = src[j];
		j++;
	}
	if (j < n)
	{
		k = j;
		while (k < n)
		{
			dest[k] = '\0';
			k++;
		}
	}
	return (s);
}

/**
 * *_strncat - Entry point
 * Description: concatenates two strings
 * @dest: first string
 * @src: second string
 * @n: the amount of bytes to be maximally used
 * Return: the concatenated string
 */

char *_strncat(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (s);
}

/**
 * *_strchr - Entry point
 * Description: locates a character in a string
 * @s: string to be parsed
 * @c: character to look for
 * Return: (s) a pointer to the memory area s
 */

char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
