#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
 * @line: the bytecode line
 * @line_number: the bytecode line number
 * @arg: the current command line operation arg
 * @op_func: the current command line operation function
 */
typedef struct command_line_s
{
	char *line;
	unsigned int line_number;
	char *arg;
	void (*op_func)(stack_t **stack, unsigned int line_number);
} command_line_t;

/**
 * struct app_err_s - the app error
 * @type: the error type
 * @error: the error error
 * @line: the bytecode line
 * @line_number: the bytecode line number
 * @filename: the bytecode file name
 */
typedef struct app_err_s
{
	char *type;
	char *error;
	char *line;
	int line_number;
	char *filename;
} app_err_t;

/**
 * struct app_var_s - the app var
 * @current_command_line: the current command line
 * @global_stack: the global stack
 * @stack_mode: the stack mode (FIFO, LIFO)
 * @app_err: the app error
 */
typedef struct app_var_s
{
	command_line_t *current_command_line;
	stack_t *global_stack;
	char *stack_mode;
	app_err_t *app_err;
} app_var_t;

#define FILE_err "FILE_err"
#define SYNTAX_err "SYNTAX_err"
#define MALLOC_err "MALLOC_err"

#define FIFO_T "FIFO"
#define LIFO_T "LIFO"

extern app_var_t app_var;

/* File functions */
/**
 * typeof lines_reader - the typeof file lines reader function
 * @line: the line string
 * @line_number: the line number
 * Return: 1 success, 0 error
 */
typedef int (*lines_reader)(char *, unsigned int);
void file_read_lines(char *filename, lines_reader);

/* Doubly linked list int functions */
stack_t *dll_add(stack_t **head, const int n);
stack_t *dll_add_end(stack_t **head, const int n);
stack_t *dll_pop(stack_t *head);
stack_t *dll_pop_end(stack_t *head);
void *dll_free(stack_t *head);

/* String functions */
char *_strcpy(char *str);
int str_contains_char(char *str, char target);
char *str_cut(char *str, const int s, const int e);
char *str_clean_spaces_se(char *str);
int str_is_int(char *str);
char *str_add_char(char *str, char c);

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

/* Others */
void make_file_err(char *filename);
void make_malloc_err(void);
void make_sntx_err(char *error, unsigned int ln, char *line);
void exit_failure(void);
void exit_with_malloc_err(void);
void exit_with_app_err(void);
void exit_with_sntx_err(void);
void exit_with_file_err(char *filename);
void reset_current_command_line(void);
void *_free(void *ptr);
int execute_command_line(char *line, unsigned int line_number);
void get_operation_func(char *operation_name);

#endif /* _MONTY_H_ */
