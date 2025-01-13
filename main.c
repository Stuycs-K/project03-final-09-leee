#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"
#include "library.h"
#include <ctype.h>

int main(){
  struct song_node ** library = init();

  //go through the mp3 files and add them to library
  

  print_library(library);

  return 0;
}
