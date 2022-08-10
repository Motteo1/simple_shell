#ifndef SHELL
#define SHELL

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <wait.h>
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>

/**
 * struct list - linked list for environmental variables
 * @var: holds environmental variable string
 * @next: points to next node
 */
typedef struct list
{
	char *var;
	struct list *next;

} list_t;

/* function prototypes */
size_t get_line(char **str);
int t_strlen(char *str, int pos, char delm);
char **_str_tok(char *str, char *delm);
void c_exit(char **str, list_t *env);
int _execve(char **s, list_t *env, int num);
int path_execute(char *command, vars_t *vars);
char *find_path(char **env);
void check_for_path(vars_t *vars);
int execute_cwd(vars_t *vars);
int check_for_dir(char *str);

#endif
