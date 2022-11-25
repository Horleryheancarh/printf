#include "main.h"

/**
 *print_char - writes character to stdout
 *@arg: input character
 *@buffer: pointer to buffer
 *@i: index
 *
 *Return: integer
 */
int print_char(va_list arg, char *buffer, unsigned int i)
{
	char c;

	c = va_arg(arg, int);
	hand_buffer(buffer, c, i);
	return (1);
}

/**
 *print_str - writes string to stdout
 *@arg: input character
 *@buffer: pointer to buffer
 *@i: index
 *
 *Return: integer
 */
int print_str(va_list arg, char *buffer, unsigned int i)
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
 *print_int - writes integer to stdout
 *@arg: input character
 *@buffer: pointer to buffer
 *@i: index
 *
 *Return: integer
 */
int print_int(va_list arg, char *buffer, unsigned int i)
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

	return (l + neg);
}

/**
 *print_prc - writes character to stdout
 *@a: input character
 *@buffer: pointer to buffer
 *@i: index
 *
 *Return: 1;
 */
int print_prc(va_list a  __attribute__((unused)), char *buffer, unsigned int i)
{
	hand_buffer(buffer, '%', i);
	return (1);
}


/**
 *print_bnr - prints decimal in binary
 *@arg: input string
 *@buffer: buffer pointer
 *@i: index of buffer
 *
 *Return: integer
 */
int print_bnr(va_list arg, char *buffer, unsigned int i)
{
	int input, count, j, first, isneg;
	char *binary;

	input = va_arg(arg, int);
	isneg = 0;
	if (input == 0)
	{
		i = hand_buffer(buffer, '0', i);
		return (1);
	}

	if (input < 0)
	{
		input = (input * -1) - 1;
		isneg = 1;
	}

	binary = malloc(sizeof(char) * (32 + 1));
	binary = fill_binary_array(binary, input, isneg, 32);
	first = 0;
	for (count = j = 0; binary[j]; j++)
	{
		if (first == 0 && binary[j] == '1')
			first = 1;
		if (first == 1)
		{
			i = hand_buffer(buffer, binary[j], i);
			count++;
		}
	}
	free(binary);
	return (count);
}
