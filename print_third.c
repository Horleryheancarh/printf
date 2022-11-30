#include "main.h"

/**
 *print_add - writes address to stdout
 *@arg: input characters
 *@buffer: pointer to buffer
 *@i: index
 *
 *Return: integer
 */
int print_add(va_list arg, char *buffer, unsigned int i)
{
	void *add;
	long int input;
	int j, count, first;
	char *hexadecimal, *binary;
	char nill[] = "(null)";

	add = (va_arg(arg, void *));

	if (add == NULL)
	{
		for (j = 0; nill[i]; i++)
			i = hand_buffer(buffer, nill[j], i);
		return (6);
	}
	input = (intptr_t)add;
	binary = malloc(sizeof(char) * (48 + 1));
	binary = fill_binary_array(binary, input, 0, 48);
	hexadecimal = malloc(sizeof(char) * (12 + 1));
	hexadecimal = fill_hex_array(binary, hexadecimal, 0, 12);
	i = hand_buffer(buffer, '0', i);
	i = hand_buffer(buffer, 'x', i);
	for (first = j = 0; hexadecimal[j]; j++)
	{
		if (hexadecimal[j] != '0' && first == 0)
			first = 1;
		if (first)
		{
			i = hand_buffer(buffer, hexadecimal[j], i);
			count++;
		}
	}
	free(binary);
	free(hexadecimal);
	return (count + 2);
}

/**
 * printlhex - prints a long decimal in hexadecimal
 * @arguments: input string
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: number of chars printed
 */
int printlhex(va_list arguments, char *buf, unsigned int ibuf)
{
	long int int_input, i, isnegative, count, first_digit;
	char *hexadecimal, *binary;

	int_input = va_arg(arguments, long int);
	isnegative = 0;
	if (int_input == 0)
	{
		ibuf = hand_buffer(buf, '0', ibuf);
		return (1);
	}
	if (int_input < 0)
	{
		int_input = (int_input * -1) - 1;
		isnegative = 1;
	}

	binary = malloc(sizeof(char) * (64 + 1));
	binary = fill_binary_array(binary, int_input, isnegative, 64);
	hexadecimal = malloc(sizeof(char) * (16 + 1));
	hexadecimal = fill_hex_array(binary, hexadecimal, 0, 16);
	for (first_digit = i = count = 0; hexadecimal[i]; i++)
	{
		if (hexadecimal[i] != '0' && first_digit == 0)
			first_digit = 1;
		if (first_digit)
		{
			ibuf = hand_buffer(buf, hexadecimal[i], ibuf);
			count++;
		}
	}
	free(binary);
	free(hexadecimal);
	return (count);
}

/**
 * printlint - prints a long integer
 * @arguments: input string
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: number of chars printed.
 */
int printlint(va_list arguments, char *buf, unsigned int ibuf)
{
	long int int_input;
	unsigned long int int_in, int_temp, i, div, isneg;

	int_input = va_arg(arguments, long int);
	isneg = 0;
	if (int_input < 0)
	{
		int_in = int_input * -1;
		ibuf = hand_buffer(buf, '-', ibuf);
		isneg = 1;
	}
	else
	{
		int_in = int_input;
	}

	int_temp = int_in;
	div = 1;
	while (int_temp > 9)
	{
		div *= 10;
		int_temp /= 10;
	}
	for (i = 0; div > 0; div /= 10, i++)
	{
		ibuf = hand_buffer(buf, ((int_in / div) % 10) + '0', ibuf);
	}
	return (i + isneg);
}

/**
 * printloct - prints long decimal number in octal
 * @arguments: input number
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: number of chars printed.
 */
int printloct(va_list arguments, char *buf, unsigned int ibuf)
{
	long int int_input, i, isnegative, count, first_digit;
	char *octal, *binary;

	int_input = va_arg(arguments, long int);
	isnegative = 0;
	if (int_input == 0)
	{
		ibuf = hand_buffer(buf, '0', ibuf);
		return (1);
	}
	if (int_input < 0)
	{
		int_input = (int_input * -1) - 1;
		isnegative = 1;
	}

	binary = malloc(sizeof(char) * (64 + 1));
	binary = fill_binary_array(binary, int_input, isnegative, 64);
	octal = malloc(sizeof(char) * (22 + 1));
	octal = fill_long_oct_array(binary, octal);
	for (first_digit = i = count = 0; octal[i]; i++)
	{
		if (octal[i] != '0' && first_digit == 0)
			first_digit = 1;
		if (first_digit)
		{
			ibuf = hand_buffer(buf, octal[i], ibuf);
			count++;
		}
	}
	free(binary);
	free(octal);
	return (count);
}

/**
 * printlunt - prints a long unsigned integer
 * @arguments: number to print
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: number of chars printed.
 */
int printlunt(va_list arguments, char *buf, unsigned int ibuf)
{
	unsigned long int int_in, int_temp, i, div;

	int_in = va_arg(arguments, unsigned long int);
	int_temp = int_in;
	div = 1;
	while (int_temp > 9)
	{
		div *= 10;
		int_temp /= 10;
	}
	for (i = 0; div > 0; div /= 10, i++)
	{
		ibuf = hand_buffer(buf, ((int_in / div) % 10) + '0', ibuf);
	}
	return (i);
}
