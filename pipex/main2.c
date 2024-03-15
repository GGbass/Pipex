/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 23:03:23 by gongarci          #+#    #+#             */
/*   Updated: 2024/02/05 23:03:23 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv, char **env)
{
    char *cmd[2];
    int fd[2];

    if (argc !=  5) {
        fprintf(stderr, "Invalid number of arguments\n");
        return  1;
    }

    cmd[0] = argv[2];
    cmd[1] = argv[3];

    if (pipe(fd) == -1) {
        perror("pipe");
        return  1;
    }

    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        return  1;
    }

    if (pid ==  0) {
        // Child process
        close(fd[1]); // Close the write end of the pipe
        dup2(fd[0], STDIN_FILENO); // Redirect stdin to read from the pipe
        execlp(cmd[0], cmd[0], cmd[1], NULL); // Execute the command
        perror("execlp");
        return  1;
    } else {
        // Parent process
        close(fd[0]); // Close the read end of the pipe
        const char *message = "This is a message for the child process";
        write(fd[1], message, strlen(message)); // Write to the pipe
        close(fd[1]); // Close the write end of the pipe
        wait(NULL); // Wait for the child process to finish
    }

    return  0;
}
