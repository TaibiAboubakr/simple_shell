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

void print_number(int std, int n);/*print_char_str.c*/
int _slen(char *s);/*print_char_str.c*/
int _puts(char *c);/*print_char_str.c*/
int __putchar(char c);/*print_char_str.c*/
int _putchar_err(int std, char c);/*check_file.c*/
int check_file_exist(char *shellname, char *filename, char *er_msg, int count);/*check_file.c*/
int check_file_perm(char *shellname, char *filename, char *err_msg, int count);/*check_file.c*/
int _puts_len(int std, char *str, int len);/*print_char_str.c*/
int exec_cmd(char *cmd, char *args[]);/*exec_command.c*/
int p_err_getline(void);/*p_errors.c*/
void p_err_write(int w);/*p_errors.c*/
void non_interactive_shell(char *argv[]);
char *check_command_path(char *cmd);/*get_cmd_path.c*/
void _free(char *, char *);/*free.c*/
void _free_with_null(char **, char **);/*free.c*/
char **strtok_alloc(char *line, ssize_t read);/*strtok_alloc.c*/
int _puts_std(int std, char *c);/*strtok_alloc.c*/
void _env(void);/*env.c*/
int _strcmp(char *s1, char *s2);/*str_func.c*/
int _strncmp(char *s1, char *s2, int n);/*str_func.c*/
char *_getenv(char *var);/*env.c*/
int check_if_exit(char **args, char *shellname, int count, int exit_code);/*check_is_command.c*//*exit_func.c*/
int _atoi(char *s);/*str_func.c*/
char *_strcpy(char *dest, char *src);/*str_func.c*/
char *_strcat(char *dest, char *src);/*str_func.c*/
char *_strdup(const char *str);/*str_func2.c*/
void print_err_file(char *shellname, char *filename, char *err_msg, int count);/*check_file.c*/
int check_file(char *shellname, char *filename, char **args, int count);/*check_file.c*/
int check_is_env_cd(char **args, char *shellname, int count, int ex_code);/*check_is_command.c*/
int _setenv(char *name, const char *value, int count);/*env.c*/
int _unsetenv(char *name, int count);/*env.c*/
int _cd(char *dest_dir,char *shellname, int count, int check);/*check_is_command.c*/
void print_err_cd(char *shellname, char *dir_name, int count);/*check_is_command.c*/
void free_env(char **old_env);/*env.c*/
void input_file_shell(char *argv[]);/*file_input_shell.c*/
int check_file_exist_argv(char *argv[]);/*file_input_shell.c*/
int _echo(char **args, int exit_code);/*echo_variables.c*/
int _echo_get_var(char **args, int indice);/*echo_variables.c*/
void print_err_oldpwd(char *current_dir);
ssize_t _getline(char **line, size_t *size, FILE *stream);
int check_is_comment(char **args);/*check_is_comment.c*/
/*check_is_env - exit_func.c*/

#endif /* MAIN_H */
