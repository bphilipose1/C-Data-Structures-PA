//Philipose, Benjamin
//card.h
//10/10/2021
/*
DESCRIPTION:Header file for card.cpp. It sets up the structure of the CardNode and CardStack classes as well as declaring all of the functions.
ASSUMPTION:NONE
*/

#include <iostream>
#ifndef CARD_H
#define CARD_H
using namespace std;

const int MAX_SIZE = 7;//Max CardNode objects that can be put in CardStack

class CardNode  {
  public:
    CardNode(); 
    /*DESCRIPTION:Default Constructor for CardNode Class
    PRE:NONE
    POST:Creates a CardNode with value of 1, suit as spades, and isJoker as false
    */

    CardNode(int value, string suit, bool isJoker);
    /*DESCRIPTION:Parameterized Cosntructor for CardNode Class
    PRE:NONE
    POST:Creates a CardNode with value, suit, and isJoker representing inputted values
    */

    void printCard(); //
    /*DESCRIPTION:Print card info function
    PRE:NONE
    POST:NONE
    */

    
    int value;//holds suit of the created card node
    string suit;//holds suit of the created card node
    bool isJoker;//tells us if card is a joker for the created card node
    CardNode* next;//Pointer that points to the next node in the linked list
};

class CardStack  {
  public:
    CardStack();//default constructor
    /*DESCRIPTION: Default Constructor for CardStack class.
    PRE:NONE
    POST: Creates a new CardStack object. Sets CardStack size to 0, and myTop to nullptr
    */

    CardStack(const CardStack &tempStack); //copy constructor
    /*DESCRIPTION: Takes an already existing CardStack and copies over all of the CardNodes to a new CardStack.
    PRE:NONE
    POST:Creates a new CardStack object with the same CardNodes as the inputted CardStack and modifies size accordingly
    */

    CardStack& operator=(const CardStack &tempCardStack);//copy assignment
    /*DESCRIPTION:Takes two existing CardStack Objects, deletes the CardStack left of the '=', then copies the CardNodes from the other CardStack
    PRE:NONE
    POST:Alters CardStack left of the '=', and modifies CardStack size accordingly
    */

    ~CardStack();// deallocate cardstack
    /*DESCRIPTION: Deallocates the CardStacks allocated memory
    PRE:NONE
    POST: Deletes CardNodes in CardStack, and sets size to 0;
    */
    
    void push(int value, string suit, bool isJoker);
    /*DESCRIPTION: Creates a new CardNode and sets it at the top of the Linked list
    PRE:NONE
    POST:Adds a CardNode to CardStack, and increases CardStack size by 1
    */

    void pop();
    /*DESCRIPTION: Prints the values of Top CardNode then deletes it from CardStack
    PRE:NONE
    POST: Removes top CardNode from CardStack, and decreases CardStack size by 1
    */

    int getSize();
    /*DESCRIPTION:Returns the size of the CardStack
    PRE:NONE
    POST:NONE
    */
    

    int countSuit(string inputSuit);//count number of suit in cardstack
    /*DESCRIPTION: Goes through each node and counts how many match the inputted suit
    PRE:NONE
    POST:NONE
    */

    void printStack();
    /*DESCRIPTION:Prints each CardNode values in order from top to bottom.
    PRE:NONE
    POST:NONE
    */
   
  private:
    CardNode card;//CardNodes stored in CardStack
    int size;//holds stack size
    CardNode* myTop;// pointer to top of the stack
};

#endif