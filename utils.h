#ifndef _UTILS_H_
#define _UTILS_H_

#include <stdio.h>
#include <stdarg.h>

void exit_with_error(const char *error, ...);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

#endif /* _UTILS_H_ */
