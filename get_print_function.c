#include "main.h"

/**
 *get_print_function - gets the correct function to print the data
 *@s: datatype identifier
 *
 *Return: pointer to a function
 */
int (*get_print_function(char s))(va_list, char *, unsigned int)
{
	printt p[] = {
		{"c", print_char}, {"u", print_unt},
		{"s", print_str}, {"o", print_oct},
		{"i", print_int}, {"x", print_hex},
		{"d", print_int}, {"X", print_upx},
		{"%", print_prc}, {"S", print_usr},
		{"b", print_bnr}, {"p", print_add},
		{NULL, NULL}
	};
	int j = 0;

	while (p[j].arg)
	{
		if (s == p[j].arg[0])
			break;
		j++;
	}
	return (p[j].f);
}

/**
 *ct_print_function - counts the number of identifiers
 *@s: datatype identifier
 *
 *Return: pointer to a function
 */
int ct_print_function(char s)
{
	printt p[] = {
		{"c", print_char}, {"u", print_unt},
		{"s", print_str}, {"o", print_oct},
		{"i", print_int}, {"x", print_hex},
		{"d", print_int}, {"X", print_upx},
		{"%", print_prc}, {"S", print_usr},
		{"b", print_bnr}, {"p", print_add},
		{NULL, NULL}
	};

	int j = 0;

	while (p[j].arg)
	{
		if (s == p[j].arg[0])
			break;
		j++;
	}
	return (j);
}
