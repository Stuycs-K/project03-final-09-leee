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
    struct song_node* first = selectFile(library, 4);
    printf("\n");
    mini_print(first);
  return 0;
}
