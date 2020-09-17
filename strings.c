#include "monty.h"
/**
 * remove_spaces - remove spaces from a string
 * @s: the string
 */
void remove_spaces(char *s)
{
const char *d = s;

do {
while (*d == ' ')
{
++d;
}
} while ((*s++ = *d++));
}
/**
 * remove_backline - remove back line from a string
 * @s: the string
 */
void remove_backline(char *s)
{
const char *d = s;

do {
while (*d == '\n')
{
++d;
}
} while ((*s++ = *d++));
}
