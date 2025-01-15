#include "node.h"
#include "library.h"
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
int createPlayList(){
    struct song_node ** library = init();
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
          }  
        
          fclose(file);  

        
        //  struct stat * stat_buffer;
        //  stat_buffer = malloc(sizeof(struct stat)*1);
        //  stat(pathname, stat_buffer);//or use &s_buff
        //  printf("size: %ld \n", stat_buffer->st_size);
        //  printf("mode : %o \n", stat_buffer->st_mode);
        // free(stat_buffer);
    }
  }
  closedir(d);
    print_library(library);
    return 0;
}

