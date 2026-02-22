#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "songs.h"
#include "utils.h"
#include "stack.h"




/** CODE: remove_char_from_end(char * str, char char_to_remove)
 *          Removes char_to_remove from the end of a c-string if it exists 
 * */


/**  CODE: Song* read_songs_from_file(const char *filename, int *count)  
 *          Open file using provided filename
 *          Allocate initial memory for songs, capacity = 10, don't forget sizeof()  
                Memory Address      | Data (Song Struct)
                --------------------|---------------------------------------------------------
                0x1000              | Song 1
                0x1000 - 0x101D     |   genre (30 bytes)
                0x101E - 0x1049     |   artist (50 bytes)
                0x104A - 0x10D3     |   title (100 bytes)
                --------------------|---------------------------------------------------------
                0x10D4              | Song 2
                0x10D4 - 0x10F1     |   genre (30 bytes)
                0x10F2 - 0x111D     |   artist (50 bytes)
                0x111E - 0x11A7     |   title (100 bytes)
                --------------------|---------------------------------------------------------
                ...
 *          While getline  (using getline, which auto allocates on the heap any size of input)
 *              if +++BEGIN check if song_index is >= capacity, then allocate more space for list, next use memset to set all the strings to 0
 *              Clean up line using remove_char_from_end
 *              If genre: artist: title: in line then 
 *                  Copy the value to the structure using strncpy
 *                  Add null terminator to the end of the field b/c strncpy does not guarantee null termination when value is longer than genre's max size
 *          Set count pointer equal to song_index + 1 
 *          Close file and free line
 *          
 *              
*/



int main(int argc, char * argv[]) {
    int song_count = 0;
    if (argc < 2){
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    Song *songs = read_songs_from_file(argv[1], &song_count);
    char filter_criteria[100] = "";

    printf("Read %d songs from file:\n", song_count);
    
    char ch = 's';
    int start_index = 0;
    int next_starting_index = 0;
    
    while(ch != 'q'){
        /** CODE: call read_songs_from_file set result to songs */
        int number_displayed = 0;
        int i;
        
        for(i = start_index; i < song_count && number_displayed < 10; i++){
            char * genre = string_tolower(songs[i].genre);
            char * artist = string_tolower(songs[i].artist);
            char * title = string_tolower(songs[i].title);
            
            if (strstr(genre, filter_criteria) == NULL && strstr(artist, filter_criteria) == NULL && strstr(title, filter_criteria) == NULL){

            }else{
            printf("Genre: %s, Artist: %s, Title: %s\n", songs[i].genre, songs[i].artist, songs[i].title);
            number_displayed++;
            
            }
            free(genre);
            free(artist);
            free(title);
        }
        next_starting_index = i;
        printf("(n for next, p for prev, f for filter, q for quit): ");
        ch = getchar();
        getchar();

        if(ch == 'n'){
            if(next_starting_index < song_count){
                push(start_index);
                start_index = next_starting_index;
            }
        }
        if(ch == 'p'){
            start_index = pop();
            if(start_index < 0){
                start_index = 0;
            }
        }
        if(ch == 'f'){
            printf("Enter filter criteria: \n");
            fgets(filter_criteria, 100, stdin);
            remove_char_from_end(filter_criteria, '\n');
            start_index = 0;
        }
    }
    /** CODE: free songs */
    free(songs);
    return 0;
}
