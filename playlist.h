#ifndef playlist_H
#define playlist_H
struct song_node ** createPlayList();
int setupPlayList(struct song_node ** library);
struct song_node* selectFile(struct song_node** library, int fdnum);
int finalPlay(struct song_node** library);
//int add();
int play(struct song_node* start);
//int remove(int num);
#endif
