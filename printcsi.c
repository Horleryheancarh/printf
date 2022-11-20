#include "main.h"

/**
 *printchar - writes character to stdout
 *@arg: input character
 *@buffer: pointer to buffer
 *@i: index
 *
 *Return: integer
 */
int printchar(va_list arg, char *buffer, unsigned int i)
{
	char c;

	c = va_arg(arg, int);
	hand_buffer(buffer, c, i);
	return (1);
}

/**
 *printstr - writes string to stdout
 *@arg: input character
 *@buffer: pointer to buffer
 *@i: index
 *
 *Return: integer
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
 *printint - writes integer to stdout
 *@arg: input character
 *@buffer: pointer to buffer
 *@i: index
 *
 *Return: integer
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

/**
 *printprc - writes character to stdout
 *@a: input character
 *@buffer: pointer to buffer
 *@i: index
 *
 *Return: 1;
 */
int printprc(va_list a  __attribute__((unused)), char *buffer, unsigned int i)
{
	hand_buffer(buffer, '%', i);
	return (1);
}

