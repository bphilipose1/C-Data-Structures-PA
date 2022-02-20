/*
Philipose, Benjamin 
movie.cpp
11/28/2021
DESCRIPTION:Implementation File for Movie and MovieNode class 
ASSUMPTIONS:NONE
SOURCES:NONE
*/
#include "movie.h"
MovieNode::MovieNode(long key, Movie value): next(nullptr), value(value), key(key) {}


Movie::Movie(string title1, string genre1, string director1, string tagLine1, long id1, int year1): title(title1), genre(genre1), director(director1), tagLine(tagLine1), id(id1), year(year1), watchCount(0)  {}

Movie::Movie() :title("PlaceHolder"), genre("PlaceHolder"), director("PlaceHolder"), tagLine("PlaceHolder"), id(-111111), year(-111111), watchCount(-1) {}

string Movie::getTitle()  {
  return title;
}

string Movie::getGenre()  {
  return genre;
}

string Movie::getDirector() {
  for(long i = 0; i < (long)director.length(); i++)  {//goes through the string and checks as well as replaces the semicolons with commas
    if(director[i] == ';')  {
      director[i] = ',';
    }
  }
  return director;
}

string Movie::getTagLine()  {
  for(long i = 0; i < (long)tagLine.length(); i++)  {//goes through the string and checks as well as replaces the semicolons with commas
    if(tagLine[i] == ';')  {
      tagLine[i] = ',';
    }
  }
  return tagLine;
}

long Movie::getId() {
  return id;
}

int Movie::getYear()  {
  return year;
}

int Movie::getWatchCount()  {
  return watchCount;
}

void Movie::incrementWatchCount() {
  this->watchCount++;
}
