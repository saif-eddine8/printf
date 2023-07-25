#include "main.h"

/**
 * print_hex - prints unsigned hex numbers in lowercase
 * @ap:  argument pointer
 * @para:  parameters struct
 *
 * Return: bytes printed
 */
int print_hex(va_list ap, para_t *para)
{
	unsigned long ln;
	int k = 0;
	char *str;

	if (para->l_modifier)
		ln = (unsigned long)va_arg(ap, unsigned long);
	else if (para->h_modifier)
		ln = (unsigned short int)va_arg(ap, unsigned int);
	else
		ln = (unsigned int)va_arg(ap, unsigned int);

	str = convert(ln, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, para);
	if (para->hashtag_flag && ln)
	{
		*--str = 'x';
		*--str = '0';
	}
	para->unsign = 1;
	return (k += print_num(str, para));
}

/**
 * print_HEX - prints unsigned hex numbers in UPPERCASE
 * @ap: argument pointer
 * @para: parameters struct
 *
 * Return: bytes printed
 */
int print_HEX(va_list ap, para_t *para)
{
	unsigned long ln;
	int k = 0;
	char *str;

	if (para->l_modifier)
		ln = (unsigned long)va_arg(ap, unsigned long);
	else if (para->h_modifier)
		ln = (unsigned short int)va_arg(ap, unsigned int);
	else
		ln = (unsigned int)va_arg(ap, unsigned int);

	str = convert(ln, 16, CONVERT_UNSIGNED, para);
	if (para->hashtag_flag && ln)
	{
		*--str = 'X';
		*--str = '0';
	}
	para->unsign = 1;
	return (k += print_num(str, para));
}
/**
 * print_binary - prints unsigned binary number
 * @ap: argument pointer
 * @para: parameters struct
 *
 * Return: bytes printed
 */
int print_binary(va_list ap, para_t *para)
{
	unsigned int n = va_arg(ap, unsigned int);
	char *str = convert(n, 2, CONVERT_UNSIGNED, para);
	int k = 0;

	if (para->hashtag_flag && n)
		*--str = '0';
	para->unsign = 1;
	return (k += print_num(str, para));
}

/**
 * print_octal - prints unsigned octal numbers
 * @ap: argument pointer
 * @para: parameters struct
 *
 * Return: bytes printed
 */
int print_octal(va_list ap, para_t *para)
{
	unsigned long ln;
	char *str;
	int k = 0;

	if (para->l_modifier)
		ln = (unsigned long)va_arg(ap, unsigned long);
	else if (para->h_modifier)
		ln = (unsigned short int)va_arg(ap, unsigned int);
	else
		ln = (unsigned int)va_arg(ap, unsigned int);
	str = convert(ln, 8, CONVERT_UNSIGNED, para);

	if (para->hashtag_flag && ln)
		*--str = '0';
	para->unsign = 1;
	return (k += print_num(str, para));
}
