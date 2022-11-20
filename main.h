#ifndef _main_h_
#define _main_h_

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

typedef struct print
{
	char *arg;
	int (*f)(va_list, char *, unsigned int);
} printt;

unsigned int hand_buffer(char *, char, unsigned int);
int print_buffer(char *, unsigned int);
int _printf(const char *, ...);
int (*get_print_function(const char *, int))(va_list, char *, unsigned int);
int ct_print_function(const char *, int);
int printstr(va_list, char *, unsigned int);
int printchar(va_list, char *, unsigned int);
int printint(va_list, char *, unsigned int);
int printprc(va_list __attribute__((unused)), char *, unsigned int);


#endif
