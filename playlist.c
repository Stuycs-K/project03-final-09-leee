#include "node.h"
#include "library.h"

int createPlayList(){
      struct song_node ** library = init();
//go through the mp3 files and add them to library
      print_library(library);
}