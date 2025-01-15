#ifndef node_H
#define node_H
struct song_node{char filename[100]; char title[100]; struct song_node *next; int file;};
int compare(struct song_node * a, struct song_node * b);
struct song_node * insert_song_node(char* filename, char* title, struct song_node *next, int file);
struct song_node * find_filename_song(char* filename, char* title, struct song_node *first);
struct song_node * first_filename_song(char* filename, struct song_node *first);
struct song_node * remove_song_node(char* filename, char* title, struct song_node *first);
struct song_node * free_list(struct song_node *first);
void helper_print(struct song_node *start);
void print_song_list(struct song_node *start);
// struct song_node * song_finder(char* filename, char* title, struct song_node* start);
// struct song_node * filename_finder(char* filename, char* title, struct song_node* start);
int truesize(struct song_node* start);
struct song_node * randSong(struct song_node* start);
struct song_node * findNth(struct song_node* start, int n, int current);
// struct song_node * delete(char* filename, char* title, struct song_node* start);
#endif
