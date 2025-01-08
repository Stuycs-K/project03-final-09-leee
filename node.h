#ifndef node_H
#define node_H
struct song_node{char artist[100]; char title[100]; struct song_node *next;};
int compare(struct song_node * a, struct song_node * b);
struct song_node * insert_song_node(char* artist, char* title, struct song_node *next);
struct song_node * find_artist_song(char* artist, char* title, struct song_node *first);
struct song_node * first_artist_song(char* artist, struct song_node *first);
struct song_node * remove_song_node(char* artist, char* title, struct song_node *first);
struct song_node * free_list(struct song_node *first);
void helper_print(struct song_node *start);
void print_song_list(struct song_node *start);
// struct song_node * song_finder(char* artist, char* title, struct song_node* start);
// struct song_node * artist_finder(char* artist, char* title, struct song_node* start);
int truesize(struct song_node* start);
struct song_node * randSong(struct song_node* start);
struct song_node * findNth(struct song_node* start, int n, int current);
// struct song_node * delete(char* artist, char* title, struct song_node* start);
#endif
