#include "monty.h"

/**
 * file_parse - function reads and breaks file in components
 * @monty_file: script to be read
 * Return: NULL
 */

void file_parse(FILE *monty_file)
{
	size_t size = 0;
	line_t line;
	metadata *data = NULL;

	data = malloc(sizeof(metadata));
	if (data == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	line.num = 0;
	line.content = NULL;

	data->monty_file = monty_file;
	data->stack = NULL;
	data->buff = NULL;

	while (getline(&(data->buff), &size, data->monty_file) != -1)
	{
		line.num++;
		parseline(&line, data->buff);
		if (line.content)
		{
			get_opcode_func(line, data)(&(data->stack), line.num);
		}
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
/**
 * imagine we have a piece of paper with lots of words written on it
 * We have a small box we can put words inside, but the box can only hold two words, so we have to make sure the box is ready and hold two words
 * we take the first word and put it in box
 * we take the second word put it in a box right next to the first word
 *
