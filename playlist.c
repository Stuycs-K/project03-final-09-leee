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
    if (name[strlen(name)-1] == '3' ){
        printf("gotcha: ");
        printf("filename: %s\n",name);
        //snag the file
         struct stat * stat_buffer;
         stat_buffer = malloc(sizeof(struct stat)*1);
         stat(PATH, stat_buffer);//or use &s_buff
         printf("size: %ld \n", stat_buffer->st_size);
         printf("mode : %o \n", stat_buffer->st_mode);
        //free(stat_buffer);
    }
  }
  closedir(d);
    print_library(library);
    return 0;
}