#include "main.h"

/**
 *fill_binary_array - convert decimal to binary
 *@binary: pointer to binary
 *@input: input number
 *@isneg: negative?
 *@limit: size of the binary
 *
 *Return: pointer to array
 */
char *fill_binary_array(char *binary, long int input, int isneg, int limit)
{
	int i;

	for (i = 0; i < limit; i++)
		binary[i] = '0';
	binary[limit] = '\0';
	for (i = limit - 1; input > 1; i--)
	{
		if (input == 2)
			binary[i] = '0';
		else
			binary[i] = (input % 2) + '0';
		input /= 2;
	}

	if (input != 0)
		binary[i] = '1';
	if (isneg)
	{
		for (i = 0; binary[i]; i++)
			if (binary[i] == '0')
				binary[i] = '1';
			else
				binary[i] = '0';
	}
	return (binary);
}

/**
 *fill_hex_array - converts binary to hexadecimal
 *@binary: binary array
 *@hex: hexadecimal array
 *@isup: integer to determine the case
 *@limit: size of hexadecimal
 *
 *Return: hexadecimal array
 */
char *fill_hex_array(char *binary, char *hex, int isup, int limit)
{
	int op, i, j, letter;

	hex[limit] = '\0';
	if (isup)
		letter = 55;
	else
		letter = 87;

	for (i = (limit * 4) - 1; i >= 0; i--)
	{
		for (op = 0, j = 1; j <= 8; j *= 2, i--)
			op = ((binary[i] - '0') * j) + op;
		i++;

		if (op < 10)
			hex[i / 4] = op + 48;
		else
			hex[i / 4] = op + letter;
	}

	return (hex);
}

/**
 *fill_oct_array - converts binary to octal
 *@binary: binary array
 *@octal: octal array
 *
 *Return: octal array
 */
char *fill_oct_array(char *binary, char *octal)
{
	int op, i, j, oct, limit;

	octal[11] = '\0';
	for (i = 31, oct = 10; i >= 0; i--, oct--)
	{
		if (i > 1)
			limit = 4;
		else
			limit = 2;

		for (op = 0, j = 1; j <= limit; j *= 2, i--)
			op = ((binary[i] - '0') * j) + op;
		i++;
		octal[oct] = op + '0';
	}
	return (octal);
}
