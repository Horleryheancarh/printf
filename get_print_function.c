#include "main.h"

/**
 *get_print_function - gets the correct function to print the data
 *@s: datatype identifier
 *@index: integer for datatype identifier
 *Return: pointer to a function
 */
int (*get_print_function(const char *s, int index))(va_list, char *, unsigned int)
{
	printt pr[] = {
		{"c", print_char}, {"s", print_str}, {"i", print_int},
		{"d", print_int}, {"b", print_bnr}, {"u", print_unt},
		{"o", print_oct}, {"x", print_hex}, {"X", print_upx},
		{"S", print_usr}, {"p", print_add}, {"li", printlint},
		{"ld", printlint}, {"lu", printlunt}, {"lo", printloct},
		{"lx", printlhex}, {"lX", printlupx}, {"hi", printsint},
		{"hd", printsint}, {"hu", printsunt}, {"ho", printsoct},
		{"hx", printshex}, {"hX", printsupx}, {"#o", printnoct},
		{"#x", printnhex}, {"#X", printnupx}, {"#i", print_int},
		{"#d", print_int}, {"#u", print_unt}, {"+i", printpint},
		{"+d", printpint}, {"+u", print_unt}, {"+o", print_oct},
		{"+x", print_hex}, {"+X", print_upx}, {" i", printspint},
		{" d", printspint}, {" u", print_unt}, {" o", print_oct},
		{" x", print_hex}, {" X", print_upx}, {"R", print_rot},
		{"r", print_rev}, {"%", print_prc}, {"l", print_prc},
		{"h", print_prc}, {" +i", printpint}, {" +d", printpint},
		{"+ i", printpint}, {"+ d", printpint}, {" %", print_prc},
		{NULL, NULL},
	};
	int i = 0, j = 0, first_index;

	first_index = index;
	while (pr[i].arg)
	{
		if (s[index] == pr[i].arg[j])
		{
			if (pr[i].arg[j + 1] != '\0')
				index++, j++;
			else
				break;
		}
		else
		{
			j = 0;
			i++;
			index = first_index;
		}
	}
	return (pr[i].f);
}

/**
 *ct_print_function - counts the number of identifiers
 *@s: datatype identifier
 *@index: integer for datatype identifier
 *Return: pointer to a function
 */
int ct_print_function(const char *s, int index)
{
	printt pr[] = {
		{"c", print_char}, {"s", print_str}, {"i", print_int},
		{"d", print_int}, {"b", print_bnr}, {"u", print_unt},
		{"o", print_oct}, {"x", print_hex}, {"X", print_upx},
		{"S", print_usr}, {"p", print_add}, {"li", printlint},
		{"ld", printlint}, {"lu", printlunt}, {"lo", printloct},
		{"lx", printlhex}, {"lX", printlupx}, {"hi", printsint},
		{"hd", printsint}, {"hu", printsunt}, {"ho", printsoct},
		{"hx", printshex}, {"hX", printsupx}, {"#o", printnoct},
		{"#x", printnhex}, {"#X", printnupx}, {"#i", print_int},
		{"#d", print_int}, {"#u", print_unt}, {"+i", printpint},
		{"+d", printpint}, {"+u", print_unt}, {"+o", print_oct},
		{"+x", print_hex}, {"+X", print_upx}, {" i", printspint},
		{" d", printspint}, {" u", print_unt}, {" o", print_oct},
		{" x", print_hex}, {" X", print_upx}, {"R", print_rot},
		{"r", print_rev}, {"%", print_prc}, {"l", print_prc},
		{"h", print_prc}, {" +i", printpint}, {" +d", printpint},
		{"+ i", printpint}, {"+ d", printpint}, {" %", print_prc},
		{NULL, NULL},
	};
	int i = 0, j = 0, first_index;

	first_index = index;
	while (pr[i].arg)
	{
		if (s[index] == pr[i].arg[j])
		{
			if (pr[i].arg[j + 1] != '\0')
				index++, j++;
			else
				break;
		}
		else
		{
			j = 0;
			i++;
			index = first_index;
		}
	}
	return (j);
}
