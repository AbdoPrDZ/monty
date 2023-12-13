#ifndef _STRING_H_
#define _STRING_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *_strcpy(const char *str);
char *str_rev(const char *str);
int str_contains_char(const char *str, const char target);
char *str_cut(const char *str, const int s, const int e);
char *str_clean_spaces_se(const char *str);
int str_is_int(char *str);

#endif /* _STRING_H_ */
