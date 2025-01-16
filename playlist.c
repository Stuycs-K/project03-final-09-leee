#include "node.h"
#include "library.h"
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <ctype.h>
#include  <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
struct song_node ** createPlayList(){
  struct song_node ** library = init();
  return library;
}
int setupPlayList(struct song_node ** library){
  //struct song_node * library = malloc(sizeof(struct song_node*));
//go through the mp3 files and add them to library
//num needs to be the number of the mp3file; also when u add it will auto sort so you cant just keep track of it in one place
//also that value int file does nothing as of right now, there is no purpose yet.
//DIRENT
  DIR * d;
  char* PATH = ".";
  d = opendir( PATH );
  struct dirent *entry;

  //Can use as a while boolean
  //since null is the end of the dirent list.
  while(entry = readdir( d )){
    char* name = entry->d_name;

    //char* pathname = "./sample-6s.mp3";
    if (name[strlen(name)-1] == '3' ){
        printf("gotcha: ");
        printf("filename: %s\n",name);
        //snag the file
        char pathname[strlen(name)+sizeof(char)];
        strcpy(pathname, PATH);
        strcat(pathname, "/");
        strcat(pathname, name);
        printf("Path for stat:%s\n", pathname);
          FILE *file = fopen(name, "r");
          if (file == NULL) {
              perror("Error opening file");
              return 1;
          }

          int fd = fileno(file);
          if (fd == -1) {
              perror("Error getting file descriptor");
          } else {
              printf("File descriptor: %d\n", fd);
              add(library, name, "title",fd);
          }


        }

      }
      //files are all opened right now
    closedir(d);

    print_library(library);
    return 0;
}

  int play(struct song_node* start){
    while (start!= NULL){
        char *name = start->filename;
        char *PATH = ".";
        char pathname[strlen(name)+sizeof(char)];
            strcpy(pathname, PATH);
            strcat(pathname, "/");
            strcat(pathname, name);


        //char *filePath = "./sample-6s.mp3";
        char *const args[] = {"mpg123",(char *)pathname,NULL};

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
    play(start->next);
    }

  }
