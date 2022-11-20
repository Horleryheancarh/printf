#include "main.h"

/**
 *
 *
 */
int printchar(va_list arg, char *buffer, unsigned int i)
{
	char c;
	c = va_arg(arg, int);
	hand_buffer(buffer, c, i);

	return (1);
}

/**
 *
 *
 *
 */
int printstr(va_list arg, char *buffer, unsigned int i)
{
	char *str;
	unsigned int j;
	char nstr[] = "(null)";

	str = va_arg(arg, char *);
	if (str == NULL)
	{
		for (j = 0; nstr[j]; j++)
			i = hand_buffer(buffer, nstr[j], i);

		return (0);
	}
	for (j = 0; str[j]; j++)
		i = hand_buffer(buffer, str[j], i);

	return (i);
}

/**
 *
 *
 *
 *
 */
int printint(va_list arg, char *buffer, unsigned int i)
{
	int input;
	unsigned int j, temp, l, div, neg;

	input = va_arg(arg, int);
	neg = 0;
	if (input < 0)
	{
		j = input * -1;
		i = hand_buffer(buffer, '-', i);
		neg = 1;
	}
	else
	{
		j = input;
	}

	temp = j;
	div = 1;

	while (temp > 9)
	{
		div *= 10;
		temp /= 10;
	}

	for (l = 0; div > 0; div /= 10, l++)
	{
		i = hand_buffer(buffer, ((j / div) % 10) + '0', i);
	}

	return (i + neg);
}




























