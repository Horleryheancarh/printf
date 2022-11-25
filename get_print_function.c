#include "main.h"

/**
 *get_print_function - gets the correct function to print the data
 *@s: datatype identifier
 *@i: indexof identifier
 *
 *Return: pointer to a function
 */
int (*get_print_function(const char *s, int i))(va_list, char *, unsigned int)
{
	printt p[] = {
		{"c", print_char},
		{"s", print_str},
		{"i", print_int},
		{"d", print_int},
		{"%", print_prc},
		{"b", print_bnr},
		{NULL, NULL}
	};
	int j = 0;

	while (p[j].arg)
	{
		if (s[i] == p[j].arg[0])
			break;
		j++;
	}
	return (p[j].f);
}

/**
 *ct_print_function - counts the number of identifiers
 *@s: datatype identifier
 *@i: indexof identifier
 *
 *Return: pointer to a function
 */
int ct_print_function(const char *s, int i)
{
	printt p[] = {
		{"c", print_char},
		{"s", print_str},
		{"i", print_int},
		{"d", print_int},
		{"%", print_prc},`
		{"b", print_bnr},
		{NULL, NULL}
	};

	int j = 0;

	while (p[j].arg)
	{
		if (s[i] == p[j].arg[0])
			break;
		j++;
	}
	return (j);
}
