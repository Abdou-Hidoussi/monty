#include "monty.h"
#include <string.h>

/**
 * op_pall - pall function
 * @stack: the stack
 */
void op_pall(stack_t **stack)
{
	stack_t *s;

	s = *stack;
	while (s != NULL)
	{
		printf("%d\n", (*s).n);
		if (s->next)
		{
			s = s->next;
		}
		else
		{
			return;
		}
	}
}
/**
 * get_int - get int after cammand in string
 * @s: the string
 * @line_number: the line in file
 * Return: the integer
 */
int get_int(char *s, unsigned int line_number)
{
	int i = 4, sum = 0;

	if (s[i] >= '9' && s[i] <= '0')
	{
		printf("L<%d>: usage: push integer\n", line_number);
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		sum = (sum * 10) + (s[i] - 48);
		i++;
	}
	return (sum);
}
/**
 * op_push - push function
 * @stack: the stack
 * @value: the value of the new item
 */
void op_push(stack_t **stack, int value)
{
	stack_t *new, *s;

	s = *stack;
	new = malloc(sizeof(stack_t **));
	new->n = value;
	if (s)
	{
		new->next = s;
		s->prev = new;
		*stack = new;
	}
	else
	{
		*stack = new;
	}
}
/**
 * op_select - push function
 * @s: the line from file
 * @stack: the stack
 * @line_number: the line in file
 * Return: exit status
 */
int op_select(char *s, stack_t **stack, unsigned int line_number)
{
	remove_spaces(s);
	remove_backline(s);

	if (strncmp(s, "push", 3) == 0)
	{
		op_push(stack, get_int(s, line_number));
		return (0);
	}
	else if (strncmp(s, "pall", 3) == 0)
	{
		op_pall(stack);
	}
	else
	{
		printf("L<%d>: unknown instruction <%s>\n", line_number, s);
	}
	return (1);
}
