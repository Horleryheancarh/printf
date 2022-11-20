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
		{"c", printchar},
		{"s", printstr},
		{"i", printint},
		{NULL, NULL}
	};
	int j = 0, k = 0, index;

	index = i;
	while (p[j].arg)
	{
		if (s[i] == p[j].arg[k])
		{
			if (p[j].arg[k + 1] != '\0')
				i++, j++;
			else
				break;
		}
		else
		{
			k = 0, j++;
			i = index;
		}
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
                {"c", printchar},
                {"s", printstr},
                {"i", printint},
                {NULL, NULL}
        };
        int j = 0, k = 0, index;

        index = i;
        while (p[j].arg)
        {
                if (s[i] == p[j].arg[k])
                {
                        if (p[j].arg[k + 1] != '\0')
                                i++, j++;
                        else
                                break;
                }
                else
                {
                        k = 0, j++;
                        i = index;
                }
        }
        return (j);
}

