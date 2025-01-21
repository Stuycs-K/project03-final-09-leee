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
#include <signal.h>

static void sighandler(int signo){
if ( signo == SIGINT ){
  printf("Who you talkin to?\n");
}
}
int main(){
    struct song_node ** library = createPlayList();
    setupPlayList(library);
    // struct song_node* first = selectFile(library, 0);
    // printf("\nfirstval:");
    // mini_print(first);
    // printf("\n");
    signal(SIGINT, sighandler);
    finalPlay(library);
  return 0;
}
