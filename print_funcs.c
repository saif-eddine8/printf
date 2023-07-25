#include "main.h"

/**
 * print_char - prints char passed
 * @ap: argument pointer
 * @params: parameters struct
 *
 * Return: number of characters printed
 */
int print_char(va_list ap, params_t *params)
{
	char pad_ch = ' ';
	unsigned int pad = 1, sum = 0, chr = va_arg(ap, int);

	if (params->minus_flag)
		sum += _putchar(chr);
	while (pad++ < params->width)
		sum += _putchar(pad_ch);
	if (!params->minus_flag)
		sum += _putchar(chr);
	return (sum);
}

/**
 * print_int - prints integer
 * @ap: argument (pointer)
 * @params:  parameters struct
 *
 * Return: number characters printed
 */
int print_int(va_list ap, params_t *params)
{
	long l;

	if (params->l_modifier)
		l = va_arg(ap, long);
	else if (params->h_modifier)
		l = (short int)va_arg(ap, int);
	else
		l = (int)va_arg(ap, int);
	return (print_number(convert(l, 10, 0, params), params));
}

/**
 * print_string - prints a string
 * @ap: argument pointer
 * @params: parameters struct
 *
 * Return: number characters printed
 */
int print_string(va_list ap, params_t *params)
{
	char *string = va_arg(ap, char *), pad_ch = ' ';
	unsigned int pad = 0, sum = 0, i = 0, k;

	(void)params;
	switch ((int)(!string))
		case 1:
			string = NULL_STRING;

	k = pad = _strlen(string);
	if (params->precision < pad)
		k = pad = params->precision;

	if (params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				sum += _putchar(*string++);
		else
			sum += _puts(string);
	}
	while (k++ < params->width)
		sum += _putchar(pad_ch);
	if (!params->minus_flag)
	{
		if (params->precision != UINT_MAX)
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
 * @params: the parameters struct
 *
 * Return: number chars printed
 */
int print_percent(va_list ap, params_t *params)
{
	(void)ap;
	(void)params;
	return (_putchar('%'));
}

/**
 * print_S - custom format specifier
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */
int print_S(va_list ap, params_t *params)
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
			hex_char = convert(*string, 16, 0, params);
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
