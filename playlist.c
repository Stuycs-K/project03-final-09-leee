#include "node.h"
#include "library.h"
#include <dirent.h>
#include <stdio.h>
#include <string.h>
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
    }
    
    //printf("--type: %d\n",entry->d_type);
    //You can use the PATH + filename to get stat data!
  }
  closedir(d);
    print_library(library);
    return 0;
}