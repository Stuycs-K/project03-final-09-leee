#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"
#include "library.h"
#include "playlist.h"
#include <ctype.h>
#include  <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(){
            // createPlayList();
            // printf("UI:");
            // //fork and execvp
    createPlayList();
    /*
    char *filePath = "./sample-6s.mp3";
    char *const args[] = {"mpg123",(char *)filePath,NULL};

    pid_t pid = fork();

    if (pid == -1) {//fail
        perror("fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process (executes mpg123)
        if (execvp("mpg123", args) == -1) {
            // If execvp fails
            perror("execvp failed");
            exit(EXIT_FAILURE);
        }
    } else {
        printf("Playing the song...\n");
        wait(NULL);
        printf("Finished playing the song.\n");
    }
    */
  return 0;
}
