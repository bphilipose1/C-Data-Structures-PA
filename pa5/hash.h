/*
Philipose, Benjamin 
hash.h
11/28/2021
DESCRIPTION:Header File for HashTable class 
ASSUMPTIONS:NONE
SOURCES:NONE
*/
#include "movie.h"
#include <string>
using namespace std;
class HashTable {
  public:
    HashTable();
      /*
      DESCRIPTION:Default Constructor for HashTable
      PRE:NONE
      POST:NONE
      */
    ~HashTable();
      /*
      DESCRIPTION:
      PRE:NONE
      POST:NONE
      */
    void addToPlaylist(long key, Movie value);
      /*
      DESCRIPTION:Adds movie with the key to the playlist and prints a message if it already exists
      PRE:Movie object needs to be created before passed into function. Getter functions are available from Movie class.
      POST:Adds MovieNode object to one of the playlist's array elements linked lists, and increases number of entries
      */
    bool watchMovie(long key);
      /*
      DESCRIPTION:If movie isnt in the playlist it will return false. Else if true, it will say it is watched, and increase the watch count.
      PRE:Getter and Setter functions are available from Movie class.
      POST:Increase the Movie's watchCount by 1
      */
    void removeMovie(long key);
      /*
      DESCRIPTION:Removes movie from playlist
      PRE: Getter functions are available from Movie class.
      POST:deletes MovieNode from the playlist array's linked list and deincrements number of entries
      */
    void displayMovie(long key);
      /*
      DESCRIPTION:If movie in playlist is found, it will show information about it
      PRE: Getter functions are available from Movie class.
      POST:NONE
      */
    void displayAll();
      /*
      DESCRIPTION:Displays id and title of all the movies in playlist
      PRE: Getter functions are available from Movie class.
      POST:NONE
      */
    void displayGenre(string tempGenre);
      /*
      DESCRIPTION:All movies title and id will be displayed if in the inputted genre
      PRE: Getter functions are available from Movie class.
      POST:NONE
      */
    int hashKey(long key);
      /*
      DESCRIPTION:Returns appropriate key for hash table
      PRE:NONE
      POST:returns the hashKey value of the inputted number
      */  
    float LoadFactor();
      /*
      DESCRIPTION:Returns the load factor for HashTable object
      PRE:NONE
      POST:returns the Load Factor value
      */  
  private:
    MovieNode* playlist[139];
    int hashSize;
    float numEntries;
};
