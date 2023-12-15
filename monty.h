#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

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
 * struct command_line_s - the current line options
 * @arg: the current command line operation arg
 * @op_func: the current command line operation function
 */
typedef struct command_line_s
{
	char *arg;
	void (*op_func)(stack_t **stack, unsigned int line_number);
} command_line_t;

extern command_line_t *current_command_line;
extern stack_t *global_stack;
extern char *stack_mode;

/* Doubly linked list int functions */
stack_t *dll_add(stack_t **head, const int n);
stack_t *dll_add_end(stack_t **head, const int n);
stack_t *dll_pop(stack_t *head);
stack_t *dll_pop_end(stack_t *head);
void dll_free(stack_t *head);

/* File functions */
char *file_read(const char *filename);
typedef void (*lines_reader)(const char *, unsigned int);
void file_read_lines(const char *filename, lines_reader);

/* String functions */
char *_strcpy(const char *str);
char *str_rev(const char *str);
int str_contains_char(const char *str, const char target);
char *str_cut(const char *str, const int s, const int e);
char *str_clean_spaces_se(const char *str);
int str_is_int(char *str);
char *str_add_char(const char *str, char c);

/* Others */
void exit_with_malloc_error(void);
void exit_with_sntx_error(const char *error, unsigned int line_number);
void exit_with_file_error(const char *filename);
void execute_command_line(const char *line, unsigned int line_number);
void get_operation_func(const char *operation_name);

/* Operations functions */
void op_push(stack_t **stack, unsigned int line_number);
void op_pall(stack_t **stack, unsigned int line_number);
void op_pint(stack_t **stack, unsigned int line_number);
void op_pop(stack_t **stack, unsigned int line_number);
void op_swap(stack_t **stack, unsigned int line_number);
void op_add(stack_t **stack, unsigned int line_number);
void op_nop(stack_t **stack, unsigned int line_number);
void op_sub(stack_t **stack, unsigned int line_number);
void op_div(stack_t **stack, unsigned int line_number);
void op_mul(stack_t **stack, unsigned int line_number);
void op_mod(stack_t **stack, unsigned int line_number);
void op_pchar(stack_t **stack, unsigned int line_number);
void op_pstr(stack_t **stack, unsigned int line_number);
void op_rotl(stack_t **stack, unsigned int line_number);
void op_rotr(stack_t **stack, unsigned int line_number);
void op_stack(stack_t **stack, unsigned int line_number);
void op_queue(stack_t **stack, unsigned int line_number);

#endif /* _MONTY_H_ */
