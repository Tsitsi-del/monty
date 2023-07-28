#include "monty.h"

/**
 * op_func - searches for match between opcode and user input
 * @line: struct of line contents and line num of the script
 * @data: struct of all allocated memory
 *
 * Return: pointer to  matching function
 */
void (*op_func(line_t line, metadata * data))(stack_t **, unsigned int)
{
	unsigned int x = 0;
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", addop},
		{"sub", subop},
		{"div", divop},
		{"mul", mulop},
		{"mod", modop},
		{"nop", nop},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotlop},
		{"rotr", rotrop},
		{"stack", addst},
		{"queue", addqu},
		{NULL, NULL}
	};

	if (check_comment(line))
		return (nop);

	while (ops[x].opcode)
	{
		if (strcmp(ops[x].opcode, line.content[0]) == 0)
		{
			check_push(line, data, ops[x].opcode);
			if (arg.flag == 1 &&
					strcmp(ops[x].opcode, "push") == 0)
			{
				if (line.content)
					free(line.content);
				return (qpush);
			}
			free(line.content);
			return (ops[x].f);
		}

		x++;
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line.number,
			line.content[0]);
	free(line.content);
	free(data->buff);
	free_stack(&(data->stack));
	fclose(data->monty_file);
	free(data);
	exit(EXIT_FAILURE);
}
