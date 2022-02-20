/*
Philipose, Benjamin 
pa4.cpp
11/19/2021
DESCRIPTION:Driver file that tests the Class GameHeap, creates 3 GameHeap objects one with 
copy constructor, one with default constructor, and one with copy assignment. 
Each GameHeap object is then tested with the insert, deleteMax, print, and printGame functions. 
At the end of the driver, we print each object to show there is no shallow copies.
ASSUMPTIONS:NONE
SOURCES:NONE
*/
#include <iostream>
#include <fstream>
#include "gameheap.h"
using namespace std;

int main()  {
  ifstream myFile;
  myFile.open("boardgames-PA4.csv");
  cout << "Testing g1 which is created by default constructor for GameHeap" << endl;
  GameHeap g1 = GameHeap();
  
  string inputKey;
  string playerNum;
  string time;
  cout << "Inserting boardgames csv file..." << endl;
  //will insert flawlessly and resize twice, first to 8 then to 16
  getline(myFile, inputKey);//to skip past first line
  while(getline(myFile, inputKey, ',')) {//exits loop when it cant read another line
    getline(myFile, playerNum, ',');//gets max number of players for item
    getline(myFile, time);//gets playtime for item
    g1.insert(inputKey, playerNum, time);//uses insert function and utilized stoi to change index input from string to int
  }
  myFile.close();

  g1.print();
  /*
  arr[1] = Ticket to Ride
  arr[2] = The Game of Life
  arr[3] = The Settlers of Catan
  arr[4] = Risk
  arr[5] = Scrabble Scattergories
  arr[6] = Pandemic
  arr[7] = Cluedo
  arr[8] = Love Letter
  arr[9] = Monopoly
  arr[10] = Codenames
  arr[11] = Dominion
  */  

  g1.printGame("Apex");
  //Apex is not in the heap.

  cout << "\nRemoving the max value. \"" << g1.deleteMax() << "\" has been removed." << endl;
  //Removing the max value. "Ticket to Ride" has been removed.
  cout << "\nPrinting Updated Heap: " << endl;
  g1.print();
  /*
  arr[1] = The Settlers of Catan
  arr[2] = The Game of Life
  arr[3] = Pandemic
  arr[4] = Risk
  arr[5] = Scrabble Scattergories
  arr[6] = Dominion
  arr[7] = Cluedo
  arr[8] = Love Letter
  arr[9] = Monopoly
  arr[10] = Codenames
  */

  cout << "\n\nTesting g2 which is created by default constructor for GameHeap" << endl;
  GameHeap g2 = GameHeap(g1);

  cout << "Inserting \"Road Rage\"" << endl;
  g2.insert("Road Rage", "120", "2");

  g2.print();
  /*
  arr[1] = The Settlers of Catan
  arr[2] = The Game of Life
  arr[3] = Pandemic
  arr[4] = Risk
  arr[5] = Scrabble Scattergories
  arr[6] = Dominion
  arr[7] = Cluedo
  arr[8] = Love Letter
  arr[9] = Monopoly
  arr[10] = Codenames
  arr[11] = Road Rage
  */  

  g2.printGame("Apex");
  //Apex is not in the heap.

  cout << "\nRemoving the max value. \"" << g2.deleteMax() << "\" has been removed." << endl;
  //Removing the max value. "The Settlers of Catan" has been removed.
  cout << "\nPrinting Updated Heap: " << endl;
  g2.print();
  /*
  arr[1] = The Game of Life
  arr[2] = Scrabble Scattergories
  arr[3] = Pandemic
  arr[4] = Risk
  arr[5] = Road Rage
  arr[6] = Dominion
  arr[7] = Cluedo
  arr[8] = Love Letter
  arr[9] = Monopoly
  arr[10] = Codenames
  */

  cout << "\n\nTesting g3 which is created by default constructor for GameHeap" << endl;
  GameHeap g3;
  g3 = g2;

  cout << "Inserting \"Road Rage\"" << endl;
  g3.insert("Fight Night", "360", "2");
  cout << "Inserting \"Road Rage\" again with player number being 12" << endl;
  g3.insert("Fight Night", "360", "12");  
  g3.printGame("Fight Night");
  /*
  Name: Fight Night
  Maximum # of players: 360
  Playtime: 12
  */
  g3.print();
  /*
  arr[1] = The Game of Life
  arr[2] = Scrabble Scattergories
  arr[3] = Pandemic
  arr[4] = Risk
  arr[5] = Road Rage
  arr[6] = Dominion
  arr[7] = Cluedo
  arr[8] = Love Letter
  arr[9] = Monopoly
  arr[10] = Codenames
  arr[11] = Fight Night
  */  

  cout << "\nRemoving the max value. \"" << g3.deleteMax() << "\" has been removed." << endl;
  //Removing the max value. "The Game of Life" has been removed.
  cout << "\nPrinting Updated Heap: " << endl;
  g3.print();
  /*
  arr[1] = Scrabble Scattergories
  arr[2] = Road Rage
  arr[3] = Pandemic
  arr[4] = Risk
  arr[5] = Fight Night
  arr[6] = Dominion
  arr[7] = Cluedo
  arr[8] = Love Letter
  arr[9] = Monopoly
  arr[10] = Codenames
  */

  cout << "\n\nTo show that each g2 and g3 are deep copies" << endl;
  cout << "\ng1:" << endl;
  g1.print();
  /*
  arr[1] = The Settlers of Catan
  arr[2] = The Game of Life
  arr[3] = Pandemic
  arr[4] = Risk
  arr[5] = Scrabble Scattergories
  arr[6] = Dominion
  arr[7] = Cluedo
  arr[8] = Love Letter
  arr[9] = Monopoly
  arr[10] = Codenames
  */
  cout << "\ng2:" << endl;
  g2.print();
  /*
  arr[1] = The Game of Life
  arr[2] = Scrabble Scattergories
  arr[3] = Pandemic
  arr[4] = Risk
  arr[5] = Road Rage
  arr[6] = Dominion
  arr[7] = Cluedo
  arr[8] = Love Letter
  arr[9] = Monopoly
  arr[10] = Codenames
  */
  cout << "\ng3: " << endl;
  g3.print();
  /*
  arr[1] = Scrabble Scattergories
  arr[2] = Road Rage
  arr[3] = Pandemic
  arr[4] = Risk
  arr[5] = Fight Night
  arr[6] = Dominion
  arr[7] = Cluedo
  arr[8] = Love Letter
  arr[9] = Monopoly
  arr[10] = Codenames
  */
  return 0;
}