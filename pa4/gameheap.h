/*
Philipose, Benjamin 
gameheap.h
11/19/2021
DESCRIPTION:Header file for GameHeap class and Game struct. Defines the functions for the class.
ASSUMPTIONS:NONE
SOURCES:NONE
*/
#include <string>
using namespace std;
struct Game { //use as key
  string name;
  int maxPlayers;
  int playtime;
  Game(string title, int maxPlayers, int playtime);
    /*
    DESCRIPTION:Paramaterized Constructor that creates a new Game object
    PRE:NONE
    POST:Creates new object and sets Game datamembers to inputted values
    */
  Game();
    /*
    DESCRIPTION:Default Constructor that creates a new Game object
    PRE:NONE
    POST:Sets title to empty string, maxplayers and playtime to -1
    */
};

class GameHeap  {
  public:
    GameHeap();
      /*
      DESCRIPTION:Default Constructor that creates a new GameHeap object
      PRE:NONE
      POST:Creates new object and sets Game array size to 4
      */
    GameHeap(const GameHeap &inputHeap);
      /*
      DESCRIPTION:Copy Constructor that creates a new Game Heap object from another object
      PRE:NONE
      POST:creates a new GameHeap object
      */
    ~GameHeap();
      /*
      DESCRIPTION:Class Destructor, deallocates gameList array from memory
      PRE:NONE
      POST:Deallocates array that gameList pointer is pointing to
      */
    GameHeap& operator=(const GameHeap &inputHeap);
      /*
      DESCRIPTION:Copy assignment operator that deep copies one object to another
      PRE:NONE
      POST:Remakes initial object to be a deep copy of the passed object
      */
    void insert(string title, string maxPlayers, string playtime);
      /*
      DESCRIPTION:Checks all the games in gameList array for a duplicate, and in that case it will update its datamembers
      Edge cases for negative numbers are addressed appropriately
      PRE:NONE
      POST:Inserts a new Game object or updates the datamembers of a duplicate game
      */
    string deleteMax();
      /*
      DESCRIPTION:Deletes game with the maximum key
      PRE:NONE
      POST:Returns the games name
      */
    void print();
      /*
      DESCRIPTION:prints all the games in the max heap in sorted order
      PRE:NONE
      POST:NONE
      */
    void printGame(string name);
      /*
      DESCRIPTION:Prints all the datamembers for the game name inputted
      PRE:NONE
      POST:NONE
      */
  private:
    void percolateDown(int inputHole);
      /*
      DESCRIPTION:inserts last element into the front of the array after deleting the front.
      then it switches the elements until the new front element finds its appropriate spot in the max heap
      PRE:NONE
      POST:Alters the maxHeap array
      */
    void resize();
      /*
      DESCRIPTION:Doubles the size of gameList when needed
      PRE:NONE
      POST:Doubles the size of Gamelist
      */
    int contain(string title);
      /*
      DESCRIPTION:Checks for a game with the same name as input
      PRE:NONE
      POST:Returns a positive index of the same name game it it is found, else it will return -1;
      */
    Game* gameList;//pointer to array of gameList
    int nextIndex;//next available element index
    int maxSize;//number of available slots in heap, including index 0  
};