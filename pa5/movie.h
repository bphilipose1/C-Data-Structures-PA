/*
Philipose, Benjamin 
movie.h
11/28/2021
DESCRIPTION:Header File for Movie, and MovieNode class 
ASSUMPTIONS:NONE
SOURCES:NONE
*/
#include <string>
using namespace std;
class Movie  {
  public:
    Movie(string title1, string genre1, string director1, string tagLine1, long id1, int year1);
      /*
      DESCRIPTION:Parameterized Constructor for Movie
      PRE:NONE
      POST:NONE
      */
    Movie();
      /*
      DESCRIPTION:Default Constructor for Movie
      PRE:NONE
      POST:NONE
      */
    string getTitle();
      /*
      DESCRIPTION:returns Title datamember
      PRE:NONE
      POST:NONE
      */
    string getGenre();
      /*
      DESCRIPTION:returns Genre datamember
      PRE:NONE
      POST:NONE
      */
    string getDirector();
      /*
      DESCRIPTION:returns Director datamember
      PRE:NONE
      POST:NONE
      */
    string getTagLine();
      /*
      DESCRIPTION:returns TagLine datamember
      PRE:NONE
      POST:NONE
      */
    long getId();
      /*
      DESCRIPTION:returns ID datamember
      PRE:NONE
      POST:NONE
      */
    int getYear();
      /*
      DESCRIPTION:returns year datamember
      PRE:NONE
      POST:NONE
      */
    int getWatchCount();
      /*
      DESCRIPTION:returns watchCount datamember
      PRE:NONE
      POST:NONE
      */
    void incrementWatchCount();
      /*
      DESCRIPTION:increases watchCounts datamember by one
      PRE:NONE
      POST:NONE
      */
  private:
    string title;
    string genre;
    string director;
    string tagLine;
    long id;
    int year;
    int watchCount;
};
class MovieNode  {
  public:
    MovieNode(long key, Movie value);
      /*
      DESCRIPTION:Parameterized Constructor for MovieNode
      PRE:NONE
      POST:NONE
      */
      MovieNode* next;
      Movie value;
  private:
    long key;

};
