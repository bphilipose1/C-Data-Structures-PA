/*
Philipose, Benjamin 
pa3.cpp
11/3/2021
DESCRIPTION:Driver file that tests the Class GameBST, creates 3 GameBST objects one with 
copy constructor, one with default constructor, and one with copy assignment. 
Each GameBST object is then tested with the insert, remove, printGame and printPlayable functions. 
At the end of the driver, we print each object to show there is no shallow copies.
ASSUMPTIONS:Input Type will match the type the program requested
SOURCES:NONE
*/

#include <iostream>
#include "gamebst.h"
#include <fstream>
#include <string>
using namespace std;


int main()  {
  //setting up file reader
  cout << "Hello! Processing the boardgames.csv file." << endl;
  ifstream myFile;
  myFile.open("boardgames.csv");

  GameBST g = GameBST();
  
  string inputKey;
  string playerNum;
  string time;
  getline(myFile, inputKey);//to skip past first line
  while(getline(myFile, inputKey, ',')) {//exits loop when it cant read another line
    getline(myFile, playerNum, ',');//gets max number of players for item
    getline(myFile, time);//gets playtime for item
    g.insert(inputKey, stoi(playerNum), stoi(time));//uses insert function and utilized stoi to change index input from string to int
  }
  myFile.close();

  cout << "\nTesting g GameBST\n\n" << endl;
  string stringInput;
  int intInput;
  //tests getHeight function for g
  cout << "Tree height is " << g.getHeight() << "\n\n";
  //Tree height is 4
  cout << "Printing Tree: " << endl;
  //test print function for g
  g.print();
  /*
  Printing tree:  
  Cluedo 
  Codenames 
  Love Letter 
  Monopoly 
  Pandemic 
  Risk 
  The Game of Life 
  The Settlers of Catan 
  Ticket to Ride 
  */

  //tests printGame for g
  cout << "Printing \"The Game of Life\"" << endl;
  g.printGame("The Game of Life");
  /*
  Game: The Game of Life
  Maximum # of players: 6
  Minimum playtime: 60 mins
  */

  //will remove The Game of Life from the g GameBST
  cout << "Removing \"The Game of Life\"..." << endl;
  g.remove("The Game of Life");
  cout << "The Game of Life has been removed. Printing updated tree: " << endl;
  //prints updated tree
  g.print();
  /*
  Printing tree:   
  Cluedo
  Codenames 
  Love Letter 
  Monopoly 
  Pandemic 
  Risk 
  The Settlers of Catan 
  Ticket to Ride 
  */
  cout << "Tree height is " << g.getHeight() << "\n\n";
  //Tree height is 3

  
  cout << "Inputting 30 minutes to test printPlayable function" << endl;
  g.printPlayable(30);
  /*Games you can play in 30 minutes are:
  Codenames
  Love Letter
  Ticket to Ride
  */
  cout << "\nTesting g2 GameBST\n\n" << endl;
  GameBST g2;
  g2 = g;//using copy assignment

  cout << "Tree height is " << g2.getHeight() << "\n\n";
  //Tree height is 3

  //inserting chess to g2
  cout << "Inserting Chess" << endl;
  g2.insert("Chess", 2, 60);
  cout << "Printing Tree: " << endl;
  //printing g2 BST
  g2.print();

  //asking user for input to test printGame function
  cout << "Which game do you want to print? ";
  getline(cin, stringInput);
  g2.printGame(stringInput);
  /*
  Game: *Games Name* (same as inputed name) 
  Maximum # of players: _
  Minimum playtime: __ mins
  */

  //will attempt the remove function and based on return value and will print the appropriate message with regards to the success of the removal
  cout << "\nWhich game do you want to remove? ";
  getline(cin, stringInput);
  if(g2.remove(stringInput)) {
    cout << stringInput << " has been removed. Printing updated tree: " << endl;
    //prints updated tree
    g2.print();
  }
  else  {
    cout << stringInput << " has been been removed unsuccessfully." << endl;
  }
  /*
  *game's name* has been removed. Printing updated tree: <- if removal is successful
  *game's name* has been removed unsuccessfully. <- if the removal function doesnt remove
  */

  //asking user for input to test printPlayable function
  cout << "How much time do you have (in mins)? ";
  cin >> intInput;
  g2.printPlayable(intInput);
  //Games you can play in __ minutes are:
  //prints out list
  

  cout << "\nTesting g3 GameBST\n\n" << endl;
  GameBST g3 = GameBST(g2);//using copy assignment

  cout << "Tree height is " << g3.getHeight() << "\n\n";
  //Tree height is...

  cout << "Inserting Cluedo..." << endl;
  //insert Game called  Cluedo it will say that game already exists if Cluedo is still in g2 which g3 is the copy of
  g3.insert("Cluedo", 3, 30);

  cout << "Inserting Apex..." << endl;
  //insert Game called  Cluedo it will say that game already exists if Cluedo is still in g2 which g3 is the copy of
  g3.insert("Apex", 3, 30);

  //printing out g3
  cout << "Printing Tree: " << endl;
  g3.print();

  //tests printGame for g3 with a non viable input
  cout << "Which game do you want to print? \ninputting \"fdas\" into printGame" << endl;

  g3.printGame("fdas");
  //No Game Found


  //will attempt the remove function and based on return value and will print the appropriate message with regards to the success of the removal
  cout << "\nWhich game do you want to remove? \ninputting \"fdas\" into printGame" << endl;
  g3.remove("fdas");
  //fdas has been removed unsuccessfully
  

  //test printPlayable using user input
  cout << "How much time do you have (in mins)? \ninputting -1 into printGame" << endl;

  g3.printPlayable(-1);
  //You have no time to play any Games :(

  
  //prints out all of the objects to show there is no shallow copies
  cout << "\n\nFinal Print of All of the GameBST's to show there is no shallow copies\n" << endl;

  cout << "printing g GameBST:" << endl;
  g.print();
  cout << "g GameBST Logistics \nHeight: " << g.getHeight() << "\nSize: " << g.getSize() << endl;

  cout << "\nprinting g2 GameBST:" << endl;
  g2.print();
  cout << "g2 GameBST Logistics \nHeight: " << g2.getHeight() << "\nSize: " << g2.getSize() << endl;


  cout << "\nprinting g3 GameBST:" << endl;
  g3.print();
  cout << "g3 GameBST Logistics \nHeight: " << g3.getHeight() << "\nSize: " << g3.getSize() << endl;

}