#include "monty.h"
#include <stdio.h>
/**
 * file_parse - function reads and breaks file in components
 * @monty_file: script to be read
 * Return: NULL
 */

void file_parse(FILE *monty_file)
{
	size_t size = 0;
	metadata *data = NULL;
	line_t line;

	data = malloc(sizeof(metadata));
	if (data == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	line.num = 0;
	line.content = NULL;

	data->monty_file =monty_file;
	data->stack = NULL;
	data->buff = NULL;

	while (getline(&(data->buff), &size, data->monty_file) != -1)
	{
		line.num++;
		parseline(&line, data->buff);
		if (line.content)
			op_func(line, data)(&(data->stack), line.num);
	}

	free(data->buff);
	free_stack(&(data->stack));
	fclose(data->monty_file);
	free(data);
}

/**
 * parseline - function to tokenize a line
 * @line: line contents and numbers stored in struct
 * @buff: text read from script file stored in buffer
 * Return: Null
 */

void parseline(line_t *line, char *buff)
{
	unsigned int x;
	char *tok = NULL;

	line->content = malloc(sizeof(char *) * 3);
	if (line->content == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	tok = strtok(buff, " '\n'");

	for (x = 0; tok && x < 2; x++)
	{
		line->content[x] = tok;
		tok = strtok(NULL, " \n");
	}
	line->content[x] = NULL;
}
