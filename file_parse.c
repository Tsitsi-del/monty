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
 * Imagine you have a book monty_file where yo can read from
 * we have a little note book caaled line to keep track of the lines we read from the book
 * We have a special notebook called data to remember some important information while reading
 * We ensure notebook data has enough space to write everything we need
 * Check if the space is enough in the notebook data
 * if no space we say oops we cant read the book because theres no space to remember things
 * we prepare a special page inside the line botebook to write down the line we read another to write down what we see in each line
 * Open the MONTY BOOK start reading each line, one by one
 * turning to a new page in the line notebook and write down the number and what we seee on that line
 * after reading each line we try to understand what it says
 * a line might say push 5 means we should push 5 into a special box called stack
 * when we finish reading the entire book and by doing what each line say e.g push 15 we close and we also close line notebook and clean all pages we used to remember.
 */

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
