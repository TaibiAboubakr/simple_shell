#ifndef MAIN_H
#define MAIN_H

#include <sys/types.h>
#include <stddef.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>
extern char **environ;

void print_number(int n);
int _slen(char *s);
int _puts(char *c);
int __putchar(char c);
int check_file_exist(char *shellname, char *filename, char *er_msg, int count);
int check_file_perm(char *shellname, char *filename, char *err_msg, int count);
int _puts_len(int std, char *str, int len);
void exec_cmd(char *args[]);
void p_err_getline(void);
void p_err_write(void);

#endif /* MAIN_H */
