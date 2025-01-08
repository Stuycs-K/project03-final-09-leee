#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "node.h"
#include "library.h"
#include "node.h"
struct song_node ** init(){
  struct song_node ** library = malloc(sizeof(struct song_node*)*27);
  for(int i = 0; i < 27; i++){
    library[i] = NULL;
  }
  return library;
}

void add(struct song_node ** library, char* artist, char* title){
  char letter = artist[0];
  if(letter > 96 && letter < 123){
    library[letter - 'a' + 1] = insert_song_node(artist, title, library[letter - 'a' + 1]);
  } else if(letter > 64 && letter < 91){
    library[letter - 'A' + 1] = insert_song_node(artist, title, library[letter - 'A' + 1]);
  } else {
    library[0] = insert_song_node(artist, title, library[0]);
  }
}

struct song_node * search_song(struct song_node ** library, char* artist, char* title){
  char letter = artist[0];
  if(letter > 96 && letter < 123){
    return find_artist_song(artist, title, library[letter - 'a' + 1]);
  } else if(letter > 64 && letter < 91){
    return find_artist_song(artist, title, library[letter - 'A' + 1]);
  } else {
    return find_artist_song(artist, title, library[0]);
  }
}

struct song_node * search_artist(struct song_node ** library, char* artist){
  char letter = artist[0];
  if(letter > 96 && letter < 123){
    return first_artist_song(artist, library[letter - 'a' + 1]);
  } else if(letter > 64 && letter < 91){
    return first_artist_song(artist, library[letter - 'A' + 1]);
  } else {
    return first_artist_song(artist, library[0]);
  }
}

void print_letter(struct song_node ** library, char letter){
  if(letter == '0'){
    print_song_list(library[0]);
  }
  // printf("%c:", letter);
  print_song_list(library[letter - 'A' + 1]);
}

void print_library(struct song_node ** library){
  //print_letter(library, '0');
  printf("\n");
  for(int i = 1; i < 27; i++){
    print_letter(library, i - 1 + 'A');
  }
}

void print_artist(struct song_node ** library, char* artist){
  struct song_node * first = search_artist(library, artist);
  if (first == NULL){
    printf("artist not found");
  }else{
    printf("artist found![");
    int i = 0;
    while (first != NULL){
      if (i != 0){
        printf("|");
      }
      if(strcmp(first->artist, artist) == 0){
        printf("{%s, %s}", first-> title, first-> artist);
        i++;
      }
      first = first-> next;
    }
    printf("]");
  }
}

int delete_song(struct song_node ** library, char* artist, char* title){
  char letter = artist[0];
  if(letter > 96 && letter < 123){
    if(search_song(library, artist, title) != NULL){
      remove_song_node(artist, title, library[letter - 'a' + 1]);
      return 0;
    } else {
      return 1;
    }
  } else if(letter > 64 && letter < 91){
    if(search_song(library, artist, title) != NULL){
      remove_song_node(artist, title, library[letter - 'A' + 1]);
      return 0;
    } else {
      return 1;
    }
  } else {
    if(search_song(library, artist, title) != NULL){
      remove_song_node(artist, title, library[0]);
    } else {
      return 1;
    }
  }
  return 1;
}

int librarySize(struct song_node ** library){
  int masterCount = 0;
  struct song_node* place = library[0];
  for (int i = 0; i < 26; i++){
    place = library[i];
    int x = truesize(place);
    masterCount += x;
  }
  //printf("%d",masterCount);
  return masterCount;
}
struct song_node * libraryFinder(struct song_node** library, int n){
  int current = 0;
  struct song_node * place;
  if(n<0 || n > librarySize(library)){return NULL;}
  for (int i = 0; i < 26; i++){
    place = library[i];
    while(place != NULL){
      if(n == current){
        return place;
      }      
      place = place->next;
      current++;
    }

  }
  return NULL;
}
void shuffle(struct song_node ** library, int n){
  srand(time(NULL));
  int max = librarySize(library);
  int count = 0; 
  while (count < n && count < max){
    int rd_num = rand() % (max);
    printf("\n");
    if (libraryFinder(library, rd_num) != NULL){
      struct song_node* hold = libraryFinder(library, rd_num);
      printf("{%s, %s}",hold->artist,hold->title);
    } else(printf("%d", rd_num));
    count++;
  }
}
