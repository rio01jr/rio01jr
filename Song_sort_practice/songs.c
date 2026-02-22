#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "songs.h"
#include "utils.h"



Song* read_songs_from_file(const char *filename, int *count) {
    FILE *file = NULL;
    char *line = NULL;
    size_t len = 0;

    int capacity = 10;
    
    Song *songs = malloc(capacity * sizeof(Song));

    int song_index = -1;
    file = fopen(filename, "r");
    
    // syntax: getline(buffer, len buffer var, file pointer) returns -1 when at EOF
    while((getline(&line, &len, file)) != -1){
        if( strstr(line, "+++ BEGIN") != NULL ){
            song_index++;
            if( song_index >= capacity){
                capacity *= 2;
                songs = realloc(songs, capacity * sizeof(Song));
            }
            continue;
        }
        if(song_index >= 0){
            char * value;
            remove_char_from_end(line, '\n');
            remove_char_from_end(line, ',');
            if((value = strstr(line, "genre:")) != NULL){
                strcpy(songs[song_index].genre, value+strlen("genre:"));
            }
            if((value = strstr(line, "artist:")) != NULL){
                strcpy(songs[song_index].artist, value+strlen("artist:"));
            }
            if((value = strstr(line, "title:")) != NULL){
                strcpy(songs[song_index].title, value+strlen("title:"));
            }
            
        }
    }
    free(line);
    *count = song_index + 1;
    return songs;
}