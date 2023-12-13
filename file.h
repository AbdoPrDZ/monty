#ifndef _FILE_H_
#define _FILE_H_

#include <stdio.h>

int file_exists(const char *filename);
char *file_read(const char *filename);
char **file_read_lines(const char *filename);

#endif /* _FILE_H_ */
