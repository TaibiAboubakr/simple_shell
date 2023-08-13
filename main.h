#ifndef MAIN_H
#define MAIN_H

#define _GNU_SOURCE
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

void print_number(int std, int n);
int _slen(char *s);
int _puts(char *c);
int __putchar(char c);
int _putchar_err(int std, char c);
int check_file_exist(char *shellname, char *filename, char *er_msg, int count);
int check_file_perm(char *shellname, char *filename, char *err_msg, int count);
int _puts_len(int std, char *str, int len);
int exec_cmd(char *cmd, char *args[]);
int p_err_getline(void);
void p_err_write(void);
void non_interactive_shell(char *argv[]);
char *check_command_path(char *cmd);
void _free(char *, char *);
void _free_with_null(char **, char **);
char **strtok_alloc(char *line, ssize_t read);
int _puts_std(int std, char *c);
void _env(void);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, int n);
char *_getenv(char *var);

#endif /* MAIN_H */
