#include "main.h"

/**
 * _strlen - Returns the length of a string.
 * @s: The string to be measured.
 *
 * Return: The length of the string.
 */
int _strlen(char *s)
{
	int len = 0;

	if (*s)
	{
		len++;
		len += _strlen(s + 1);
	}

	return (len);
}

/**
 * _strcmp - compares two string
 * @s1: string one
 * @s2: string two
 * Return: 1 (Same), 0 (Not same)
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (s2[i] != '\0')
		return (0);
	return (1);
}

/**
 * _puts - Prints a string, followed by a new line.
 * @s: The string to be printed.
 */
void _puts(char *s)
{
	if (*s)
	{
		_putchar(*s);
		_puts(s + 1);
	}
}

/**
 *_strcpy - copies the string pointed to by src
 * including the terminating null byte (\0)
 * to the buffer pointed to by dest
 * @dest: pointer to the buffer in which we copy the string
 * @src: string to be copied
 * Return: the pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
	int len, i;

	len = 0;
	while (src[len] != '\0')
	{
		len++;
	}
	for (i = 0; i < len; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
