#include "main.h"

/**
 *_printf - print data
 *@format: input string
 *
 *Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	unsigned int i = 0, len = 0, j = 0;
	va_list all;
	int (*f)(va_list, char *, unsigned int);
	char *buffer;

	va_start(all, format);
	buffer = malloc(sizeof(char) * 1024);
	if (!format || !buffer || (format[i] == '%' && !format[i + 1]))
		return (-1);

	if (!format[i]) return (0);

	for (i = 0; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
			{
				print_buffer(buffer, j), free(buffer), va_end(all);
				return (-1);
			}
			else
			{
				f = get_print_function(format, i + 1);
				if (f == NULL)
				{
					if (format[i + 1] == ' ' && !format[i + 2])
						return (-1);
					hand_buffer(buffer, format[i], j), len++, i--;
				}
				else
				{
					len += f(all, buffer, j);
					i += ct_print_function(format, i + 1);
				}
			} i++;
		}
		else
			hand_buffer(buffer, format[i], j), len++;

		for (j = len; j > 1024; j -= 1024)
			;

	}
	print_buffer(buffer, j), free(buffer), va_end(all);
	return (len);
}
