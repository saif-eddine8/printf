#include "main.h"

/**
 * print_from_to - prints a series of char addressess
 * @begin: beginning address
 * @end: termination address
 * @except:  address to skip
 *
 * Return: sum of bytes printed
 */
int print_from_to(char *begin, char *end, char *except)
{
	int sum = 0;

	while (start <= stop)
	{
		if (start != except)
			sum += _putchar(*start);
		start++;
	}
	return (sum);
}

/**
 * print_rev - prints given string in reverse
 * @ap: string passed to be printed
 * @para: the parameters struct
 *
 * Return: number bytes printed
 */
int print_rev(va_list ap, para_t *para)
{
	char *str = va_arg(ap, char *);
	(void)para;
	int len, sum = 0;

	if (str)
	{
		for (len = 0; *str; str++)
			len++;
		str--;
		for (; len > 0; len--, str--)
			sum += _putchar(*str);
	}
	return (sum);
}

/**
 * print_rot13 - prints given string in rot13
 * @ap: string passed
 * @para: struct
 *
 * Return: total value of bytes printed
 */
int print_rot13(va_list ap, para_t *para)
{
	int i, index;
	char arr[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(ap, char *);
	(void)para;
	int count = 0;

	i = 0;
	index = 0;
	while (a[i])
	{
		if ((a[i] >= 'A' && a[i] <= 'Z')
		    || (a[i] >= 'a' && a[i] <= 'z'))
		{
			index = a[i] - 65;
			count += _putchar(arr[index]);
		}
		else
			count += _putchar(a[i]);
		i++;
	}
	return (count);
}
