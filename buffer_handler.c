#include "main.h"

/**
 *hand_buffer - add buffer characters
 *@buffer: pointer to buffer
 *@c: character
 *@i: index of pointer to buffer
 *
 *Return: index of pointer to buffer
 */
unsigned int hand_buffer(char *buffer, char c, unsigned int i)
{
	if (i == 1024)
	{
		print_buffer(buffer, i);
		i = 0;
	}
	buffer[i] = c;
	i++;

	return (i);
}
