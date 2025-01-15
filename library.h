#ifndef library_H
#define library_H
struct song_node ** init();
void add(struct song_node ** library, char* filename, char* title, int file);
struct song_node * search_song(struct song_node ** library, char* filename, char* title);
struct song_node * search_filename(struct song_node ** library, char* filename);
void print_letter(struct song_node ** library, char letter);
void print_filename(struct song_node ** library, char* filename);
void print_library(struct song_node ** library);
void shuffle (struct song_node ** library, int n);
int delete_song(struct song_node ** library, char* filename, char* title);
void reset(struct song_node ** library);
int librarySize(struct song_node ** library);
struct song_node * libraryFinder(struct song_node** library, int n);
#endif
