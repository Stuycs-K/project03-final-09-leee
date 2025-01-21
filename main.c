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
  struct song_node ** library = createPlayList();
  printf("RESETING PLAYLIST\n");
  setupPlayList(library);
  printf("\nNEW PLAYLIST\n");
  print_library(library);
  printf("===========\n");
}
}


int finalPlay(struct song_node** library){
  int num = 0;
  //while (num == 0){
  while (selectFile(library, num) != NULL){
    signal(SIGINT, sighandler);
    struct song_node* first = selectFile(library, num);
    printf("\nMP3 File:");
    mini_print(first);
    printf("\n");
    play(selectFile(library,num));
    printf("\n\n\n");
    num++;
  }
}


int main(){
    struct song_node ** library = createPlayList();
    setupPlayList(library);
    finalPlay(library);
  return 0;
}
