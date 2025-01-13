#include "node.h"
#include "library.h"
#include <dirent.h>
int createPlayList(){
    struct song_node ** library = init();
//go through the mp3 files and add them to library
int num = 0;
//num needs to be the number of the mp3file; also when u add it will auto sort so you cant just keep track of it in one place
//also that value int file does nothing as of right now, there is no purpose yet. 
    add(library,"artist","sample",num);
    print_library(library);
    return 0;
}