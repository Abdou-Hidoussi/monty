#include "monty.h"
/**
 * file_ln - get file length
 * @s: file line
 * Return: file length
 */
int file_ln(char *s)
{
	FILE *f;
	int i = 0;
	char c;

	f = fopen(s, "r");
	while ((c = fgetc(f)) != EOF)
		if (c == '\n')
			i++;
	fclose(f);
	return (i);
}
/**
 * main - main monty
 * @argc: argument number
 * @argv: array of arguments
 * Return: state of exit
 */
int main(int argc, char *argv[])
{
	FILE *script;
	char *strs;
	int lines;
	stack_t **stack;
	unsigned int i = 1;

	stack = malloc(sizeof(stack_t **));
	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	script = fopen(argv[1], "r");

	if (script == NULL)
	{
		printf("Error: Can't open file <%s>\n", argv[1]);
		return (EXIT_FAILURE);
	}

	lines = file_ln(argv[1]);

	strs = malloc(sizeof(char *) * lines);
	while (fgets(strs, 1024, script) != NULL)
	{
		op_select(strs, stack, i);
		i++;
	}
	fclose(script);
	free(strs);
	return (0);
}

