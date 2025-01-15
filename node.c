#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "node.h"

int compare(struct song_node * a, struct song_node * b){
  char s1[100];
  char s2[100];
  strcpy(s1, a->artist);
  strcpy(s2, b->artist);
  for(int i = 0; i < strlen(a->artist); i++){
    if(s1[i] > 96 && s1[i] < 123){
      s1[i] = s1[i] - 32;
    }
  }
  for(int i = 0; i < strlen(b->artist); i++){
    if(s2[i] > 96 && s2[i] < 123){
      s2[i] = s2[i] - 32;
    }
  }
  if(strcmp(s1, s2) == 0){
    char s3[100];
    char s4[100];
    strcpy(s3, a->title);
    strcpy(s4, b->title);
    for(int i = 0; i < strlen(a->title); i++){
      if(s3[i] > 96 && s3[i] < 123){
        s3[i] = s3[i] - 32;
      }
    }
    for(int i = 0; i < strlen(b->title); i++){
      if(s4[i] > 96 && s4[i] < 123){
        s4[i] = s4[i] - 32;
      }
    }
    return(strcmp(s3, s4));
  }
  return strcmp(s1, s2);
}

struct song_node * insert_song_node(char* artist, char* title, struct song_node *first, int file){
  struct song_node *song;
  song = malloc(sizeof(struct song_node)*1);
  strcpy(song->artist, artist);
  strcpy(song->title, title);
  if(first == NULL){
    song->next = NULL;
    return song;
  }
  if(first->next == NULL){
    if(compare(song, first) < 0){
      song->next = first;
      first->next = NULL;
      return song;
    }
    song->next = NULL;
    first->next = song;
    return first;
  }
  struct song_node *previous;
  struct song_node *current;
  previous = first;
  current = first;
  while(current->next != NULL){
    current = current->next;
    if(compare(song, current) < 0){
      song->next = current;
      previous->next = song;
      return first;
    }
    previous = previous->next;
  }
  current->next = song;
  song->next = NULL;
  return first;
}

struct song_node * find_artist_song(char* artist, char* title, struct song_node *first){
  if(first == NULL){
    return NULL;
  }
  while(first->next != NULL){
    if(strcmp(first->artist, artist) == 0){
      if(strcmp(first->title, title) == 0){
        return first;
      } else {
        first = first->next;
      }
    } else {
      first = first->next;
    }
  }
  if(strcmp(first->artist, artist) == 0){
    if(strcmp(first->title, title) == 0){
      return first;
    }
  }
  return NULL;
}

struct song_node * first_artist_song(char* artist, struct song_node *first){
  if(first == NULL){
    return NULL;
  }
  while(strcmp(artist, first->artist) != 0){
    first = first->next;
    if(first == NULL){
      return NULL;
    }
  }
  return first;
}

struct song_node * remove_song_node(char* artist, char* title, struct song_node *first){
  struct song_node * temp;
  struct song_node * begin;
  char flag = 0;
  temp = first;
  begin = first;
  while(first->next != NULL){
    if(strcmp(temp->artist, artist) == 0){
      if(strcmp(temp->title, title) == 0){
        first->next = temp->next;
        struct song_node * helper;
        helper = begin->next;
        free(temp);
        if(flag == 0){
          return helper;
        }
        return begin;
      } else {
        flag = 1;
        first = temp;
        temp = temp->next;
      }
    } else {
      flag = 1;
      first = temp;
      temp = temp->next;
    }
  }
  free(first);
  return NULL;
}

struct song_node * free_list(struct song_node * first){
	struct song_node * temp;
	while(first != NULL){
		temp = first;
    first = first->next;
		free(temp);
	}
	return first;
}

void helper_print(struct song_node *start){
  if (start!= NULL){
    printf("{%s, %s}", start->artist, start->title);
    if (start->next != NULL){
      printf("|");
    } else{printf("]");}
    helper_print(start->next);
  }
}
void print_song_list(struct song_node *start){
  if (start != NULL){
    char* letter = start->artist;
    printf("%c: ", letter[0]);
    printf("[");
    helper_print(start);
    printf("\n");
  }

}

int truesize(struct song_node* start){
  int current = 0;
  while (start != NULL){
    current++;
    start = start->next;
  }
  return current;
}
struct song_node * findNth(struct song_node* start, int n, int current){
  if (n==current){
    return start;
  } else{
    return findNth(start->next,n,current+1);
  }
}

struct song_node * randSong(struct song_node* start){
  srand( time(NULL) );
  int max = truesize(start);
  //printf("%d\n", max);
  int rd_num = rand() % (max) ;
  //printf("%d",rd_num);
  return findNth(start, rd_num, 0);
  //find random int within truesize(start, 1)
}

int set_int(struct song_node* num){
  return 0;
}
