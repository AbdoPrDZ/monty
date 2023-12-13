#ifndef _LISTS_H_
#define _LISTS_H_

#include <stdio.h>
#include <stdlib.h>

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

stack_t *dll_add(stack_t **head, const int n);
stack_t *dll_get_at_index(stack_t **head, unsigned int index);
stack_t *dll_pop(stack_t *head);
void dll_free(stack_t *head);

#endif /* _LISTS_H_ */
