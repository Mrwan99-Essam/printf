#include "main.h"

/**
 * get_specifier - function that find format of function
 * @s: string format
 *
 * Return: number of bytes printed
*/

int (*get_specifier(char *s))(va_list ap, params_t *params)
{
	specifier_t specifiers[] = {
		{"c", print_char},
		{"d", print_int},
		{"i", print_int},
		{"s", print_string},
		{"%", print_percent},
		{"b", print_binary},
		{"o", print_octal},
		{"u", print_unsigned},
		{"x", print_hex},
		{"X", print_HEX},
		{"p", print_address},
		{"S", print_S},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL}
	};
	int i = 0;

	while (specifiers[i].specifier)
	{
		if (*s == specifiers[i].specifier[0])
		{
			return (specifiers[i].f);
		}
		i++;
	}
	return (NULL);
}

/**
 * get_print_func - function that find format of func
 * @s: format string
 * @ap: argument pointer
 * @params: parameters struct
 *
 * Return: number of bytes printed
*/

int get_print_func(char *s, va_list ap, params_t *params)
{
	int (*fun)(va_list, params_t *) = get_specifier(s);

	if (fun)
		return (fun(ap, params));
	return (0);
}

/**
 * get_flag - function that find flag function
 * @s: format string
 * @params: parameters struct
 *
 * Return: valid flag
*/

int get_flag(char *s, params_t *params)
{
	int i = 0;

	switch (*s)
	{
		case '+':
			i = params->plus_flag = 1;
			break;
		case ' ':
			i = params->space_flag = 1;
			break;
		case '#':
			i = params->hashtag_flag = 1;
			break;
		case '-':
			i = params->minus_flag = 1;
			break;
		case '0':
			i = params->zero_flag = 1;
			break;
	}
	return (i);
}

/**
 * get_modifier - function that find modifier function
 * @s: format string
 * @params: parameters struct
 *
 * Return: valid modifier
*/

int get_modifier(char *s, params_t *params)
{
	int i = 0;

	switch (*s)
	{
		case 'h':
			i = params->h_modifier = 1;
			break;
		case 'l':
			i = params->l_modifier = 1;
			break;
	}
	return (i);
}

/**
 * get_width - function that get width from format string
 * @s: format string
 * @params: parameters struct
 * @ap: argument pointer
 *
 * Return: new pointer
*/

char *get_width(char *s, params_t *params, va_list ap)
{
	int w = 0;

	if (*s == '*')
	{
		w = va_arg(ap, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			w = w * 10 + (*s++ - '0');
	}
	params->width = w;
	return (s);
}
