#ifndef playlist_H
#define playlist_H
struct song_node ** createPlayList();
int setupPlayList(struct song_node ** library);
struct song_node* selectFile(struct song_node** library, int fdnum);
//int add();
//int remove(int num);
#endif
