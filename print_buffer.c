#include "main.h"

/**
 *print_buffer - prints buffer
 *@buffer: pointer to buffer
 *@n: number of bytes
 *
 *Return: number of bytes
 */
int print_buffer(char *buffer, unsigned int n)
{
	return (write(1, buffer, n));
}
