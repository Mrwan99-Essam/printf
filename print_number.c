#include "main.h"

/**
 * _isdigit - function check if character is digit
 * @c: character to check
 *
 * Return: 1 if digit, 0 if not
*/

int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - returns length of string
 * @s: string to check
 *
 * Return: integer of string length
*/

int _strlen(char *s)
{
	int i = 0;

	while (*s++)
		i++;
	return (i);
}

/**
 * print_number - function print number with options
 * @str: base number string
 * @params: parameter struct
 *
 * Return: characters printed
*/

int print_number(char *str, params_t *params)
{
	unsigned int num = _strlen(str);
	int negative = (!params->unsign && *str == '-');

	if (!params->precision && *str == '0' && !str[1])
		str = "";
	if (negative)
	{
		str++;
		num--;
	}
	if (params->precision != UINT_MAX)
		while (num++ < params->precision)
			*--str = '0';

	if (negative)
		*--str = '-';

	if (!params->minus_flag)
		return (print_number_right_shift(str, params));
	else
		return (print_number_left_shift(str, params));
}

/**
 * print_number_right_shift - function print number with options
 * @str: base number string
 * @params: parameter struct
 *
 * Return: chars printed
*/

int print_number_right_shift(char *str, params_t *params)
{
	unsigned int num = 0, negative1, negative2, i = _strlen(str);
	char pad_char = ' ';

	if (params->zero_flag && !params->minus_flag)
		pad_char = '0';
	negative1 = negative2 = (!params->unsign && *str == '-');

	if (negative1 && i < params->width && pad_char == '0' && !params->minus_flag)
		str++;
	else
		negative1 = 0;
	if ((params->plus_flag && !negative2) ||
			(!params->plus_flag && params->space_flag && !negative2))
		i++;
	if (negative1 && pad_char == '0')
		num += _putchar('-');
	if (params->plus_flag && !negative2 && pad_char == '0' && !params->unsign)
		num += _putchar('+');
	else if (!params->plus_flag && params->space_flag && !negative2 &&
			!params->unsign && params->zero_flag)
		num += _putchar(' ');
	while (i++ < params->width)
		num += _putchar(pad_char);
	if (negative1 && pad_char == ' ')
		num += _putchar('-');
	if (params->plus_flag && !negative2 && pad_char == ' ' && !params->unsign)
		num += _putchar('+');
	else if (!params->plus_flag && params->space_flag && !negative2 &&
			!params->unsign && !params->zero_flag)
		num += _putchar(' ');
	num += _puts(str);
	return (num);
}

/**
 * print_number_left_shift - function print number with options
 * @str: base string number
 * @params: parameter struct
 *
 * Return: chars printed
*/

int print_number_left_shift(char *str, params_t *params)
{
	unsigned int n = 0, neg, neg2, i = _strlen(str);
	char pad_char = ' ';

	if (params->zero_flag && !params->minus_flag)
		pad_char = '0';
	neg = neg2 = (!params->unsign && *str == '-');
	if (neg && i < params->width && pad_char == '0' && !params->minus_flag)
		str++;
	else
		neg = 0;

	if (params->plus_flag && !neg2 && !params->unsign)
		n += _putchar('+'), i++;
	else if (params->space_flag && !neg2 && !params->unsign)
		n += _putchar(' '), i++;
	n += _puts(str);

	while (i++ < params->width)
		n += _putchar(pad_char);
	return (n);
}


