#include "main.h"

/**
 *print_unt - writes char to stdout
 *@arg: input characters
 *@buffer: pointer to buffer
 *@i: index
 *
 *Return: integer
 */
int print_unt(va_list arg, char *buffer, unsigned int i)
{
	unsigned int input, temp, j, div;

	input = va_arg(arg, unsigned int);
	temp = input;
	div = 1;

	while (temp > 0)
	{
		div *= 10;
		temp /= 10;
	}

	for (j = 0; div > 0; div /= 10, j++)
	{
		i = hand_buffer(buffer, ((input / div) % 10) + '0', i);
	}

	return (j);
}

/**
 *print_upx - writes char to stdout
 *@arg: input characters
 *@buffer: pointer to buffer
 *@i: index
 *
 *Return: integer
 */
int print_upx(va_list arg, char *buffer, unsigned int i)
{
	int input, isneg, count, first, j;
	char *hexadecimal, *binary;

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

	hexadecimal = malloc(sizeof(char) * (8 + 1));
	hexadecimal = fill_hex_array(binary, hexadecimal, 1, 8);

	for (first = j = count = 0; hexadecimal[j]; j++)
	{
		if (hexadecimal[j] != '0' && first == 0)
			first = 1;
		if (first)
		{
			i = hand_buffer(buffer, hexadecimal[j], j);
			count++;
		}
	}

	free(binary);
	free(hexadecimal);
	return (count);
}

/**
 *print_usr - writes char to stdout
 *@arg: input characters
 *@buffer: pointer to buffer
 *@i: index
 *
 *Return: integer
 */
int print_usr(va_list arg, char *buffer, unsigned int i)
{
	unsigned char *s;
	char *hex, *binary;
	unsigned int j, sum, op;

	s = va_arg(arg, unsigned char *);
	binary = malloc(sizeof(char) * (32 + 1));
	hex = malloc(sizeof(char) * (8 + 1));

	for (sum = j = 0; s[j]; j++)
	{
		if (s[j] < 32 || s[j] >= 127)
		{
			i = hand_buffer(buffer, '\\', i);
			i = hand_buffer(buffer, 'x', i);

			op = s[j];

			binary = fill_binary_array(binary, op, 0, 32);
			hex = fill_hex_array(binary, hex, 1, 8);

			i = hand_buffer(buffer, hex[6], i);
			i = hand_buffer(buffer, hex[7], i);

			sum += 3;
		}
		else
			i = hand_buffer(buffer, s[j], i);
	}

	free(binary);
	free(hex);
	return (i + sum);
}

/**
 *print_oct - converts binary to octal
 *@arg: input character
 *@buffer: pointer to buffer
 *@i: index
 *
 *Return: integer
 */
int print_oct(va_list arg, char *buffer, unsigned int i)
{
	int input, j, isneg, count, first;
	char *octal, *binary;

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
	octal = malloc(sizeof(char) * (11 + 1));
	octal = fill_oct_array(binary, octal);

	for (first = j = count = 0; octal[j]; j++)
	{
		if (octal[j] != '0' && first == 0)
			first = 1;
		if (first)
		{
			i = hand_buffer(buffer, octal[j], i);
			count++;
		}
	}
	free(binary);
	free(octal);
	return (count);
}

/**
 *print_hex - writes char to stdout
 *@arg: input character
 *@buffer: pointer to buffer
 *@i: index
 *
 *Return: integer
 */
int print_hex(va_list arg, char *buffer, unsigned int i)
{
	int input, j, isneg, count, first;
	char *hexadecimal, *binary;

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

	hexadecimal = malloc(sizeof(char) * (8 + 1));
	hexadecimal = fill_hex_array(binary, hexadecimal, 0, 8);

	for (first = j = count = 0; hexadecimal[j]; j++)
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
	return (count);
}
