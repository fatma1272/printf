#include "main.h"
/**
 * _puts - prints a string with newline
 * @str: string to print
 * Return: void
 */

int _puts(char *str)
{
	char *a = str;

	while (*str)
		_putchar(*str++);
	return (str - a);
}

/**
 * _putchar - writes the character c to (stdout)
 * @c: character to print
 * Return: 1 on success
 * -1 on error
 */

int _putchar(int c)
{
	static int i;
	static char buf[OUYPUT_BUF_SIZE];

	if (c == BUF_FLUSH || i >= OUYPUT_BUF_SIZE)
		{
			write(1, buf, i);
			i = 0;
		}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

