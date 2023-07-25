#include "main.h"

/**
 * print_from_to - function that prints a range of char address
 * @start: starting address
 * @stop: stop address
 * @except: except address
 *
 * Return: number of bytes printed
*/

int print_from_to(char *start, char *stop, char *except)
{
	int total = 0;

	while (start <= stop)
	{
		if (start != except)
			total += _putchar(*start);
		start++;
	}
	return (total);
}

/**
 * print_rev - function that print string in reverse
 * @ap: string
 * @params: parameters struct
 *
 * Return: number bytes printed
*/

int print_rev(va_list ap, params_t *params)
{
	int length, total = 0;
	char *str = va_arg(ap, char *);
	(void)params;

	if (str)
	{
		for (length = 0; *str; str++)
			length++;
		str--;
		for (; length > 0; length--, str--)
			total += _putchar(*str);
	}
	return (total);
}

/**
 * print_rot13 - function prints string in rot13
 * @ap: string
 * @params: parameters struct
 *
 * Return: number of printed bytes
*/

int print_rot13(va_list ap, params_t *params)
{
	int i, index;
	int counter = 0;
	char arr[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM	nopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(ap, char *);
	(void)params;

	i = 0;
	index = 0;
	while (a[i])
	{
		if ((a[i] >= 'A' && a[i] <= 'Z')
				|| (a[i] >= 'a' && a[i] <= 'z'))
		{
			index = a[i] - 65;
			counter += _putchar(arr[index]);
		}
		else
			counter += _putchar(a[i]);
		i++;
	}
	return (counter);
}

