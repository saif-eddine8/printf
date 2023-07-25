#include "main.h"

/**
 * print_char - prints char passed
 * @ap: argument pointer
 * @para: parameters struct
 *
 * Return: number of characters printed
 */
int print_char(va_list ap, para_t *para)
{
	char pad_ch = ' ';
	unsigned int pad = 1, sum = 0, chr = va_arg(ap, int);

	if (para->minus_flag)
		sum += _putchar(chr);
	while (pad++ < para->width)
		sum += _putchar(pad_ch);
	if (!para->minus_flag)
		sum += _putchar(chr);
	return (sum);
}

/**
 * print_int - prints integer
 * @ap: argument (pointer)
 * @para:  parameters struct
 *
 * Return: number characters printed
 */
int print_int(va_list ap, para_t *para)
{
	long l;

	if (para->l_modifier)
		l = va_arg(ap, long);
	else if (para->h_modifier)
		l = (short int)va_arg(ap, int);
	else
		l = (int)va_arg(ap, int);
	return (print_num(convert(l, 10, 0, para), para));
}

/**
 * print_string - prints a string
 * @ap: argument pointer
 * @para: parameters struct
 *
 * Return: number characters printed
 */
int print_string(va_list ap, para_t *para)
{
	char *string = va_arg(ap, char *), pad_ch = ' ';
	unsigned int pad = 0, sum = 0, i = 0, k;

	(void)para;
	switch ((int)(!string))
		case 1:
			string = NULL_STRING;

	k = pad = _strlen(string);
	if (para->precision < pad)
		k = pad = para->precision;

	if (para->minus_flag)
	{
		if (para->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				sum += _putchar(*string++);
		else
			sum += _puts(string);
	}
	while (k++ < para->width)
		sum += _putchar(pad_ch);
	if (!para->minus_flag)
	{
		if (para->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				sum += _putchar(*string++);
		else
			sum += _puts(string);
	}
	return (sum);
}

/**
 * print_percent - prints string
 * @ap: argument pointer
 * @para: the parameters struct
 *
 * Return: number chars printed
 */
int print_percent(va_list ap, para_t *para)
{
	(void)ap;
	(void)para;
	return (_putchar('%'));
}

/**
 * print_S - custom format specifier
 * @ap: argument pointer
 * @para: the parameters struct
 *
 * Return: number chars printed
 */
int print_S(va_list ap, para_t *para)
{
	char *string = va_arg(ap, char *);
	char *hex_char;
	int sum = 0;

	if ((int)(!string))
		return (_puts(NULL_STRING));
	for (; *string; string++)
	{
		if ((*string > 0 && *string < 32) || *string >= 127)
		{
			sum += _putchar('\\');
			sum += _putchar('x');
			hex_char = convert(*string, 16, 0, para);
			if (!hex_char[1])
				sum += _putchar('0');
			sum += _puts(hex_char);
		}
		else
		{
			sum += _putchar(*string);
		}
	}
	return (sum);
}
