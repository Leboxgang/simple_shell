#ifndef MAIN_H
#define MAIN_H

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int create_process(char *str);
char **string_tokens(char *str, char *delimiter);
void print_tokens(char **tokens);
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include <stdlib.h>

#endif
