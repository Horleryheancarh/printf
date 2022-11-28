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
