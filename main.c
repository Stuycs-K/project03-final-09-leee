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
    struct song_node ** library = createPlayList();
    setupPlayList(library);
    // struct song_node* first = selectFile(library, 0);
    // printf("\nfirstval:");
    // mini_print(first);
    // printf("\n");
    finalPlay(library);
  return 0;
}
