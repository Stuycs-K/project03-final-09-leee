# Final Project Proposal

## Group Members:
Ethan Lee       
Just me :)
# Intentions:
I intend to create a basic music player that allows for grouping songs in playlists and contains a master list of all the songs downloaded. There will be a shuffle option to randomize the order of the playlist and options to add or remove songs from different playlists. This project should be able to fork/exec to play music and maybe could have a leaderboard for the most played songs. 

A statement of the problem you are solving and/or a high level description of the project.

# Intended usage:
The user should be greeted with a prompt requesting an action. The user can choose to edit their playlist or song library, or see the leaderboard. Upon answering of the prompt, the user shall always be given the choice of saving and going back to the home screen or simply leaving. If they choose to edit the playlist, they are given the option to remove songs by order number or add new songs. To add a new song, they can choose the song by typing in the artist and selecting the song they want based on it's corresponding number. When they run make play, the music player should play the playlist the user setup. 

# Technical Details:

This project shall be broken down into three different parts. One of which is the creation of the data structures and their respective functions. These include most of the functions in our previous music library and several new functions for manipulating playlists. Each data structure should have it's own c/h file and be completed first. The second involves a main capable of playing playlists through forking and exec. This main should catch SIGINT and possibly other signals to know when to stop. The final part is the interface, including the receiving of user input and the different things needed to be displayed. 

# Intended pacing:

Part 1 should be done by Tuesday, 1/7
  -This includes
    - data structures, printing, and sorting algorithms for song_nodes and library,
    - and the inclusion of a new data struct containing the actual music files.
Part 2 should be done by Tuesday, 1/14
  -This includes...
    - processing simple user input,
    - the playing of the actual songs,
    - and the forking and execing to play the playlist
Part 3 should be done by Friday, 1/17
  - This consists of...
    - the rest of the user interface,
    - catching signals such as SIGINT for instructions

This should leave me with time to complete any late labs and account for any additional time it might take for me to finish a section.
