#include "ft_pipex.h"

void    ft_pipex(int argc, char **argv)
{
        int     infile;
        int     outfile;
        int     end[2];
        pid_t   id;

        if ((infile = open(argv[1], O_RDONLY)) == -1)
            ft_exit("FAIL! Can't open the input file.");
        if ((outfile = open(argv[2], O_RDONLY, O_CREAT, O_WRONLY)) == -1)
            ft_exit("FAIL! Can't open the output file.");
        if ((pipe(end) == -1))
            ft_exit("FAIL! Can't work with Pipe.");
        if ((id = fork()) == -1)
            ft_exit("FAIL! Can't work with Fork.");
        if (id == 0)
            ft_child(end, infile, argv[2]);
        else
            ft_parent(end, outfile, argv[3]);
}


void    ft_child(int end[2], int infile, char *cmd1)
{
    char **cmd;

    cmd = ft_split(cmd1, ' ');
    if (dup2(infile, 0) == -1)
        ft_exit("FAIL! Can't copy file descripter");
    if (dup2(end[0], 1) == -1)
        ft_exit("FAIL! Can't copy STDOUT");
    if (cmd[0][0] == '/')
    {
        if (execve(cmd[0], cmd, environ) == -1)
            ft_exit("Wrong address of command.");
    }
    else
        ft_exec_get(cmd[0], cmd);
    
}

void    ft_exec_get(char *cmd, char **command)
{
    int i;
    char **path;
    char *tmp;
    char *new;
    path = NULL;
    i = 0;
    while (environ[i])
    {
        if (environ[i][1] == 'P' && environ[i][2] == 'A')
        {
            path = ft_split(environ[i] + 5, ':');
            break ;
        }
        i++;
    }
    i = 0;
    while (path[i])
    {
        tmp = ft_strjoin(path[i], "/");
        new = ft_strjoin(tmp, cmd);
        execve(new, command, environ);
        free(tmp);
        free(new);
        i++;
    }
    ft_free(path);
}

void    ft_parent(int end[2], int outfile, char *cmd2)
{
    char **cmd;

    cmd = ft_split(cmd2, ' ');
    wait(NULL);
    if (dup2(outfile, 1) == -1)
        ft_exit("FAIL! Can't copy file descripter");
    if (dup2(end[1], 1) == -1)
        ft_exit("FAIL! Can't copy STDOUT");
    if (cmd[0][0] == '/')
    {
        if (execve(cmd[0], cmd, environ) == -1)
            ft_exit("Wrong address of command.");
    }
    else
        ft_exec_get(cmd[0], cmd);
    ft_free(&cmd2);
}

void    ft_exit(char *str)
{
    ft_putstr(str);
    return ;
}

void    ft_free(char **cmd)
{
    int i;

    i = 0;
    while (cmd[i])
    {
        free(cmd[i]);
        i++;
    }
}
