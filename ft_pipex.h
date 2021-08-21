#ifndef FT_PIPEX_H
#define FT_PIPEX_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <fcntl.h>
#include <sys/types.h>
#include "Libft/libft.h"

void    ft_pipex(int argc, char **argv);
void    ft_check_errors(int argc, char **argv, int end[2], pid_t    pid);
void    ft_exit(char *str);
void    ft_child(int end[2], int infile, char *cmd1);
void    ft_parent(int end[2], int outfile, char *cmd2);
void    ft_exec_get(char *cmd, char **command);
void    ft_free(char **cmd);


char *const * environ;

#endif