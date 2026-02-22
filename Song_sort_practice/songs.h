#ifndef SONGS_H
#define SONGS_H

#define MAX_GENRE_LENGTH 30
#define MAX_ARTIST_LENGTH 50
#define MAX_TITLE_LENGTH 100

typedef struct Song {
    char genre[MAX_GENRE_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
    char title[MAX_TITLE_LENGTH];
} Song;

Song* read_songs_from_file(const char *filename, int *count);

#endif
