[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/Vh67aNdh)
# Music Box 1.0

### Songbird
Ethan Lee

### Project Description:
This project shall serve as a music box capable of playing a playlist, capable of handling signals to skip the song, pause it, or end a playlist. It is important to note that these instructions and features are done by mpg123, and that my work was seperate. 
I havev implemented a feature that allows users to update the directory directly and add mp3 files to the playlist without the need for compiling again. This is done using signals, specifically SIGINT. 

There is a slight bug in which updating the playlist via ctrl c does NOT restart the playlist, and that to play the updated playlist the original one must end. This can be done by spamming 'q' or typing "ctrl \"

### Instructions:  ? UPDATE FOR signals
The music files should be already included in the repository, so no downloads are necessary. It is encouraged to add files to the directory and update the playlist with SIGINT.

make compile and make run; The mp3 files currently in the directory will be added to a playlist, which will play via mpg123. 
ctrl c to update the playlist (if you added any mp3 files to the directory after the program begins);
ctrl \ to kill and end the program immediately



https://photos.onedrive.com/share/8A6C9DE187F5DA8C!saec8af278aea418b89e95e2d9147e06b?cid=8A6C9DE187F5DA8C&resId=8A6C9DE187F5DA8C!saec8af278aea418b89e95e2d9147e06b&ithint=video&e=4%3a81452776693f4d28bb520eb37c2bb6d3&sharingv2=true&fromShare=true&at=9&migratedtospo=true&redeem=aHR0cHM6Ly8xZHJ2Lm1zL3YvYy84YTZjOWRlMTg3ZjVkYThjL0VTZXZ5SzdxaW90QmllbGVMWkZINEdzQkdQTGRzQmtvVnIwSVczQzJoUU05LVE_ZT00OjgxNDUyNzc2NjkzZjRkMjhiYjUyMGViMzdjMmJiNmQzJnNoYXJpbmd2Mj10cnVlJmZyb21TaGFyZT10cnVlJmF0PTk 