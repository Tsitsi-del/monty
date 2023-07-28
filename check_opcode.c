#include "monty.h"

static arg_t arg = {0, 0};

/**
 * check_comment - function that checks if line is a comment
 * @line: struct of line contents and line number
 *
 * Return: true if comment, else false
 */
bool check_comment(line_t line)
{
	if (line.content[0] == NULL)
	{
		free(line.content);
		return (true);
	}

	if (line.content[0][0] == '#')
	{
		free(line.content);
		return (true);
	}

	return (false);
}

/**
 * check_args - function verifies if argument is valid
 * @token: argument to be checked
 *
 * Return: true if valid argument, else false
 */
bool check_args(char *token)
{
	unsigned int x;

	if (token == NULL)
		return (false);

	for (x = 0; token[x]; x++)
	{
		if (token[0] == '-')
			continue;
		if (token[x] < '0' || token[x] > '9')
		{
			return (false);
		}
	}

	return (true);
}

/**
 * check_push - function check if push opcode is being used
 * @line: struct of line contents and line number
 * @opcode: the opcode to compare
 * @data: struct containing all allocated memory
 *
 * Return: Null
 */
void check_push(line_t line, metadata *data, char *opcode)
{
	if ((strcmp(opcode, "push") == 0) && !argument_check(line.content[1]))
	{
		free(line.content);
		fprintf(stderr, "L%d: usage: push integer\n", line.number);
		free(data->buff);
		free_stack(&(data->stack));
		fclose(data->monty_file);
		free(data);
		exit(EXIT_FAILURE);
	}
	else if (strcmp(opcode, "push") == 0)
		arg.arg = atoi(line.content[1]);
}
