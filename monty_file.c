#include "monty.h"

/**
 * main - Function open monty script file for parsing
 * @argc: command line argument counts number of arguments
 * @argv: command line argument array of arguments
 * Return: EXIT_SUCCESS on Success, EXIT_FAILURE on Fail
 */

int main(int argc, char *argv[])
{
	FILE *monty_file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	monty_file = fopen(argv[1], "r");
	if (monty_file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	file_parse(monty_file);
	return (EXIT_SUCCESS);
}
