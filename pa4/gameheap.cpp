/*
Philipose, Benjamin 
gameheap.cpp
11/19/2021
DESCRIPTION:Implementation file for Game struct and GameHeap class
ASSUMPTIONS: NONE
SOURCES:NONE
*/
#include "gameheap.h"
#include <iostream>
using namespace std;
Game::Game(string title, int maxPlayers, int playtime): name(title), maxPlayers(maxPlayers), playtime(playtime)  {}
Game::Game():name(""), maxPlayers(-1), playtime(-1)  {}
GameHeap::GameHeap()  {
  nextIndex = 1;
  maxSize = 4;
  gameList = new Game[maxSize];
}
GameHeap::GameHeap(const GameHeap &inputHeap) {
  nextIndex = 1;
  maxSize = 4;
  gameList = new Game[maxSize];
  *this = inputHeap;
}
GameHeap::~GameHeap() {
  //deleting each game object
  delete [] gameList;

}
GameHeap& GameHeap::operator=(const GameHeap &inputHeap)  {
  if(this->gameList == inputHeap.gameList)  {//checks if the GameList objects are the same
    return *this;
  }
  delete [] gameList;//Deallocates the original array for room for the new array
  //copy over the datamembers for GameHeap
  nextIndex = inputHeap.nextIndex;
  maxSize = inputHeap.maxSize;
  //Allocates memory for the new gameList array
  gameList = new Game[maxSize];
  for(int i = 1; i < nextIndex; i++) {//inputs each object into the new array
    gameList[i] = inputHeap.gameList[i];
    gameList[i] = Game(inputHeap.gameList[i].name, inputHeap.gameList[i].maxPlayers, inputHeap.gameList[i].playtime);
  }
  return *this;
}
void GameHeap::resize()  {
  cout << "The array is full. ";
  Game* temp = new Game[(2 * maxSize)];//creates new array
  for(int i = 1; i < nextIndex; i++)  {//copies over the array elements
    temp[i] = gameList[i];
  }
  delete [] gameList;//deletes the array
  gameList = temp;//sets new array to gameList
  maxSize = 2 * maxSize;//updates maxSize
  cout << "Resizing array to " << maxSize << " elements" << endl;
}
int GameHeap::contain(string title)  {
  for(int i = 1; i < nextIndex; i++) {//traverses the gameList
    if(title == gameList[i].name)  {//returns the index of inputed item in Game list
      return i;
    }
  }
  return -1;//if game is not found then it will return -1 to represent contains as false
}
void GameHeap::insert(string title, string maxPlayers, string playtime) {
  if(stoi(maxPlayers) <= 0 || stoi(playtime) <= 0)  {//checks if input numbers are positive
    cout << "INVALID INPUT" << endl;
    return;
  }
  int index = contain(title);//checks if there is a duplicate name Game object
  if(nextIndex == 1)  {//if there is no elements in the array
    int hole = nextIndex;
    gameList[hole] = Game(title, stoi(maxPlayers), stoi(playtime));
  }
  else  {//if there is elements in the array
    if(index == -1)  {//index is -1 if there are no duplicates
      if(nextIndex > maxSize - 1)  {//if the array is full resize array to double the original size
        resize();
      }
      int hole = nextIndex;//creats an empty spot at the end of heap
      while(title > gameList[hole / 2].name && (hole > 1))  {//percolates up to find appropriate spot for hole
        gameList[hole] = gameList[hole / 2];
        hole /= 2;
      }
      //found spot for hole, time to insert
      gameList[hole] = Game(title, stoi(maxPlayers), stoi(playtime));
    }
    else  {//if index isnt -1 then there is a duplicate, and it returns the dups index value
      gameList[index].maxPlayers = stoi(maxPlayers);
      gameList[index].playtime = stoi(playtime);
    }
  }
  if(index == -1) {//doesnt update size if a game is updated
    nextIndex++;
  }
}
string GameHeap::deleteMax() {
  string removedValue;
  if(nextIndex == 1) {//checks if heap is empty    
    return "Nothing";
  }
  removedValue = gameList[1].name;//var that will contain the removed value
  gameList[1] = gameList[--nextIndex];//puts last value in heap array in the front of array
  percolateDown(1); //percolates down
  return removedValue;
}
void GameHeap::percolateDown(int inputHole)  {
  int child;
  Game tmp = gameList[inputHole];
  bool bubbleDown = true;
  while(bubbleDown && inputHole * 2 <= nextIndex)  {//continues to shift up the elements if the number in the next depth is greater than the number below
    child = inputHole * 2;
    if(child != nextIndex && gameList[child + 1].name > gameList[child].name) {
      ++child;
    }
    if(gameList[child].name > tmp.name)  {
      gameList[inputHole] = gameList[child];//swaps elements from rootnode(index 1) with a element lesser than it from below(depth 1)
    }
    else  {
      bubbleDown = false;
    }
    if(bubbleDown)  {
      inputHole = child;
    }
  }
  gameList[inputHole] = tmp;//shifts last element to finish the percolate down function
}
void GameHeap::print()  {
  for(int i = 1; i < nextIndex; i++)  {//traverses gameList
    //prints the names of the games in gameList
    cout << "arr[" << i << "] = " << gameList[i].name << endl;
  }
}
void GameHeap::printGame(string name) {
  //finds the index for the target game
  int targetIndex = contain(name);
  //if a proper index is found it prints out the game objects datamembers
  if(targetIndex > 0) {
    cout << "\nName: " << gameList[targetIndex].name << "\nMaximum # of players: " << gameList[targetIndex].maxPlayers << "\nPlaytime: " << gameList[targetIndex].playtime << "\n\n";
  }
  else  {//if it returns a non positive index it will tell the user that the game cannot be found
    cout << name << " is not in the heap." << endl;
  }
}