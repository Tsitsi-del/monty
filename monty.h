#ifndef MONTY_H
#define MONTY_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include <stdbool.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct line - contents of lines in strcut
 * @content: array of tokens read from each line
 * @num: line number
 */
typedef struct line
{
	unsigned int num;
	char **content;
} line_t;

/**
 * struct meta_s - data information in a file
 * @buff: buffer storing contents of the script
 * @stack: stack
 * @monty_file: sript file to be read
 */
typedef struct meta_s
{
	char *buff;
	stack_t *stack;
	FILE *monty_file;
} metadata;
/**
 * struct arg_s - arguments in struct
 * @arg: argument
 * @flag: instruction
 */
typedef struct arg_s
{
	int arg;
	int flag;
} arg_t;

extern arg_t arg;

void file_parse(FILE *monty_file);
void parseline(line_t *line, char *buff);
int main(int argc, char *argv[]);
void push(stack_t **stack, unsigned int num_line);
void free_stack(stack_t **stack);
void nop(stack_t **stack, unsigned int num_line);
int _isalpha(int cha);
void pall(stack_t **stack, unsigned int num_line);
void pop(stack_t **stack, unsigned int num_line);
void swap(stack_t **stack, unsigned int num_line);
void pstr(stack_t **stack, unsigned int num_line);
void pchar(stack_t **stack, unsigned int num_line);
void pint(stack_t **stack, unsigned int num_line);
void qpush(stack_t **stack, unsigned int num_line);
void rotrop(stack_t **stack, unsigned int num_line);
void rotlop(stack_t **stack, unsigned int num_line);
void rot1(stack_t **stack, unsigned int num_line);
void modop(stack_t **stack, unsigned int num_line);
void mulop(stack_t **stack, unsigned int num_line);
void addop(stack_t **stack, unsigned int num_line);
void subop(stack_t **stack, unsigned int num_line);
void divop(stack_t **stack, unsigned int num_line);
void addqu(stack_t **stack, unsigned int num_line);
void addst(stack_t **stack, unsigned int num_line);
void (*op_func(line_t line, metadata *data))(stack_t **, unsigned int);
bool check_comment(line_t line);
bool check_args(char *token);
void check_push(line_t line, metadata *data, char *opcode);

#endif
