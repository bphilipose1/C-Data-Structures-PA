/*
Philipose, Benjamin 
pa5.cpp
11/28/2021
DESCRIPTION:Driver file that tests the Class HashTable, MovieNode, and Movi. Creates 1 HashTable object. 
Each HashTable, and Movie functions is tested. 
ASSUMPTIONS:NONE
SOURCES:NONE
*/
#include <iostream>
#include <fstream>
#include "hash.h"

using namespace std;

int main()  {
  HashTable h = HashTable();
  //declaring input variables for all necessary parameter fields of the HashTable functions
  string inputID;
  string inputTitle;
  string inputGenre;
  string inputReleaseYear;
  string inputDirector;
  string inputRating;
  string inputTagLine;
  ifstream myFile;
  myFile.open("movies.csv");
  getline(myFile, inputTitle);//to skip past first line
  while(getline(myFile, inputID, ',')) {//exits loop when it cant read another line
    getline(myFile, inputTitle, ',');
    getline(myFile, inputGenre, ',');
    getline(myFile, inputReleaseYear, ',');
    getline(myFile, inputDirector, ',');
    getline(myFile, inputRating, ',');
    getline(myFile, inputTagLine);
    //takes all of the input variables and creates movie object and inserts it in into playlist
    Movie temp = Movie(inputTitle, inputGenre, inputDirector, inputTagLine, stol(inputID), stoi(inputReleaseYear));
    h.addToPlaylist(stol(inputID), temp);
  }
  //tries to re-insert the last inserted movie
  cout << "Testing program for duplicates..." << endl;
  Movie temp1 = Movie("Test1", "Test", "Test", "Test", 58492, 2050);
  h.addToPlaylist(58492, temp1);
  Movie temp2 = Movie("Test2", "reTest", "Terewst", "Tesrewt", 58492, 1050);
  h.addToPlaylist(58492, temp2);
  //should print "The Test2 Movie with key: 58492 Already Exists"

  myFile.close();
  cout << "\nInitial Load Factor: " << h.LoadFactor() << "\n\n";

  bool quit;
  while(!quit)  {
    long x;
    string inputX;
    cout << "Welcome to my movie world! What would you like to do? 0. Quit \n1. Browse all movies, \n2. Browse by genre, \n3. Watch a movie, \n4. Get movie info, \n5. Remove movie" << endl;
    cin >> x;
    if(x == 0)  {
      quit = true;
    }
    else if(x == 1)  {//option to show all movies in playlist
      h.displayAll();
    }
    else if(x == 2) {//show all movies that have the inputted genre in playlist
      cout << "Which genre are you looking for? ";
      cin >> inputX;
      h.displayGenre(inputX);
    }
    else if(x == 3) {//option to allow the user to watch a movie
      cout << "Enter the ID of the movie you want to watch: ";
      cin >> x;
      if(!h.watchMovie(x)) {
        cout << "Movie not found" << endl;
      }
    }
    else if(x == 4) {//option to show more details about movie
      cout << "Enter the ID of the movie: ";
      cin >> x;
      h.displayMovie(x);
    }
    else if(x == 5) {//option to remove the movie
      cout << "Enter the ID of the movie you want to remove: ";
      cin >> x;
      h.removeMovie(x);
    }
    else  {//invalid input which will cause user to exit program
      cout << "invalid input" << endl;
      quit = true;
    }
    cout << "\n*********************************************" << endl;
  }

  cout << "Removing Test1 Movie..." << endl;
  h.removeMovie(58492);//should remove Test1 Movie from playlist

  cout << "\nPrinting new playlist..." << endl;
  h.displayAll();
  //prints out the Load Factor
  cout << "Final Load Factor: " << h.LoadFactor() << endl;
  cout << "Hope you enjoyed the movies. Goodbye!" << endl;
  return 0;
}