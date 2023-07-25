#include "main.h"

/**
 * get_specifier - searches for the format function
 * @str: format string
 *
 * Return: num of bytes printed
 */
int (*get_specifier(char *str))(va_list ap, para_t *para)
{
	specifier_t spcfiers[] = {
		{"c", print_char},
		{"m", print_int},
		{"indx", print_int},
		{"str", print_string},
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
	int indx = 0;

	while (spcfiers[indx].specifier)
	{
		if (*str == spcfiers[indx].specifier[0])
		{
			return (spcfiers[indx].f);
		}
		indx++;
	}
	return (NULL);
}

/**
 * get_print_func - finds the format func
 * @str: the format string
 * @ap: argument pointer
 * @para: the parameters struct
 *
 * Return: the number of bytes printed
 */
int get_print_func(char *str, va_list ap, para_t *para)
{
	int (*f)(va_list, para_t *) = get_specifier(str);

	if (f)
		return (f(ap, para));
	return (0);
}

/**
 * get_flag - finds the flag func
 * @str: format string
 * @para: parameters struct
 *
 * Return: if flag was valid,else don't
 */
int get_flag(char *str, para_t *para)
{
	int indx = 0;

	switch (*str)
	{
		case '+':
			indx = para->plus_flag = 1;
			break;
		case ' ':
			indx = para->space_flag = 1;
			break;
		case '#':
			indx = para->hashtag_flag = 1;
			break;
		case '-':
			indx = para->minus_flag = 1;
			break;
		case '0':
			indx = para->zero_flag = 1;
			break;
	}
	return (indx);
}

/**
 * get_modifier - finds the modifier func
 * @str: the format string
 * @para: the parameters struct
 *
 * Return: if modifier was valid
 */
int get_modifier(char *str, para_t *para)
{
	int indx = 0;

	switch (*str)
	{
	case 'h':
		indx = para->h_modifier = 1;
		break;
	case 'l':
		indx = para->l_modifier = 1;
		break;
	}
	return (indx);
}

/**
 * get_width - gets the width from the format string
 * @str: format string
 * @para: parameters struct
 * @ap: argument pointer
 *
 * Return: new pointer
 */
char *get_width(char *str, para_t *para, va_list ap)
{
	int m = 0;

	if (*str == '*')
	{
		m = va_arg(ap, int);
		str++;
	}
	else
	{
		while (_isdigit(*str))
			m = m * 10 + (*str++ - '0');
	}
	para->width = m;
	return (str);
}
