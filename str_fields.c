#include "main.h"

/**
 * get_precision - gets the precision from the format string
 * @ptr: string(format)
 * @params: struct(parameters)
 * @ap: pointer(argument)
 *
 * Return: new pointer
 */
char *get_precision(char *ptr, params_t *params, va_list ap)
{
	int d = 0;

	if (*ptr != '.')
		return (ptr);
	ptr++;
	if (*ptr == '*')
	{
		d = va_arg(ap, int);
		ptr++;
	}
	else
	{
		while (_isdigit(*ptr))
			d = d * 10 + (*ptr++ - '0');
	}
	params->precision = d;
	return (ptr);
}
