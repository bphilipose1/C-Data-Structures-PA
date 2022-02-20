/*
Philipose, Benjamin 
hash.cpp
11/28/2021
DESCRIPTION:Implementation File for HashTable class 
ASSUMPTIONS:NONE
SOURCES:NONE
*/
#include "hash.h"
#include <iostream>
using namespace std;
HashTable::HashTable() {
  hashSize = 139;
  numEntries = 0;
  for(int i = 0; i < hashSize; i++) {//sets all array pointers to nullptr
    playlist[i] = nullptr;
  }
}
HashTable::~HashTable()  {
  for(int i = 0; i < hashSize; i++) {//traverses all pointer elements of array
    if(playlist[i] != nullptr)  {//checks if element pointer is already nullptr
      MovieNode* current  = playlist[i];
      while(current != nullptr) {//traverses and deletes linked list
        MovieNode* next = current->next;
        delete current;
        current = next;
      }
    }
  }
}
void HashTable::addToPlaylist(long key1, Movie value1)  {
  int newKey = hashKey(key1);
  MovieNode* temp = playlist[newKey];//goes to appropriate element that points to linked list
  if(temp == nullptr)  {//if empty it will insert
    playlist[newKey] = new MovieNode(key1, value1);
    numEntries++;
  }
  else  {//traverses to the end of the linked list
    if(temp->value.getId() == key1)  {//checks head MovieNode
        cout << "The " << value1.getTitle() << " Movie with key: " << value1.getId() << " Already Exists" << endl;
        return;
    }
    while(temp->next != nullptr)  {//traverses linked list
      temp = temp->next; 
      if(temp->value.getId() == key1)  {//continues to check for dups each itearation
        cout << "The " << value1.getTitle() << " Movie with key: " << value1.getId() << " Already Exists" << endl;
        return;
      }

    }
    temp->next = new MovieNode(key1, value1);//adds element
    temp->next->next = nullptr;//sets end of linked list to nullptr
    numEntries++;
  }
}
bool HashTable::watchMovie(long key) {
  int newKey = hashKey(key);//gets the hashkey
  MovieNode* temp = playlist[newKey];
  while(temp != nullptr)  {//traverses the linked list at hashkey index for playlist   
    if(temp->value.getId() == key) {//if the target id is found
      temp->value.incrementWatchCount();
      cout << "Watched " << temp->value.getTitle() << ". Increased watchCount to " << temp->value.getWatchCount() << endl;
      return true;
    }
    temp = temp->next;
  }
  //if target id is not found
  return false;
}
void HashTable::removeMovie(long key)  {
  int newKey = hashKey(key);//gets the hashkey
  MovieNode* targetNode = playlist[newKey];
  if(targetNode == nullptr) {//if there is no MovieNodes at array element
    cout << "Cant Find Movie" << endl;
    return;
  }
  else if(targetNode->value.getId() == key) {//if targetNode is at the front
    playlist[newKey] = targetNode->next;//will count for cases if next is nullptr or another targetNode;
    cout << "Removing the " << targetNode->value.getTitle() << " from the playlist" << endl;
    delete targetNode;
    numEntries--;
    return;
  }
  else  {
    while(targetNode->next != nullptr)  {//traverses the linked list at hashkey index for playlist        
      if(targetNode->next->value.getId() == key) {//if the target id is found
        MovieNode* temp = targetNode->next;
        cout << "Removing the " << temp->value.getTitle() << " from the playlist" << endl;
        delete temp;
        targetNode->next = targetNode->next->next;//will count for cases if next is nullptr or another targetNode;
        numEntries--;
        return;
      }
      targetNode = targetNode->next;
    }
  }
  cout << "Cant Find Movie" << endl;//if target movie is not found it will print the message  
}
void HashTable::displayMovie(long key) {
  int newKey = hashKey(key);//gets the hashkey
  MovieNode* temp = playlist[newKey];
  while(temp != nullptr)  {//traverses the linked list at hashkey index for playlist
    if(temp->value.getId() == key) {//if the target id is found
      cout << "ID: " << temp->value.getId() << endl;
      cout << "Title: " << temp->value.getTitle() << endl;
      cout << "Director: " << temp->value.getDirector() << endl;
      cout << "Genre: " << temp->value.getGenre() << endl;
      cout << "Tagline: " << temp->value.getTagLine() << endl;
      cout << "Year: " << temp->value.getYear() << endl;
      cout << "You have watched it " << temp->value.getWatchCount() << " time(s)." << endl;
      return;
    }
    temp = temp->next;
  }
  //if target id is not found
  cout << "Movie not found :(" << endl;
}
void HashTable::displayAll() {
  for(int i = 0; i < hashSize; i++)  {//traverses arrays elements
    MovieNode* temp = playlist[i];
    while(temp != nullptr)  {//traverses linked list at array element
      cout << "ID: " << temp->value.getId() << endl;
      cout << "Title: " << temp->value.getTitle() << "\n\n"; 
      temp = temp->next;   
    }
  }
}
void HashTable::displayGenre(string tempGenre) {
  for(int i = 0; i < hashSize; i++)  {//traverses array elements
    MovieNode* temp = playlist[i];
    while(temp != nullptr)  {//traverses linked list at array element
      if(temp->value.getGenre() == tempGenre)  {//if MovieNode's Movie value's genre matches, it will display it
        cout << "ID: " << temp->value.getId() << endl;
        cout << "Title: " << temp->value.getTitle() << "\n\n";    
      } 
      temp = temp->next;   
    }
  }
}
int HashTable::hashKey(long key) {
  return key % hashSize;//finds best index for inputted key that fits in playlists index
}
float HashTable::LoadFactor() {
  return (1.0*numEntries)/(1.0*hashSize);
}