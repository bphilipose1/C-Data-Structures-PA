//Philipose, Benjamin
//card.cpp
//10/10/2021
/*
DESCRIPTION:Implementation file for card.h. It initializes all of the functions that where previously declared in the card header file
ASSUMPTION:NONE
*/

#include <iostream>
#include <string>
#include "card.h"

using namespace std;

//uses initialization list to initialize CardNode data members
CardNode::CardNode(): value(1), suit("Spades"), isJoker(false), next(nullptr)  {}

//uses initialization list to initialize CardNode data members
CardNode::CardNode(int value1, string suit1, bool isJoker1): value(value1), suit(suit1), isJoker(isJoker1), next(nullptr)   {}

void CardNode::printCard() {
  if(isJoker) {//Checks if CardNode is a Joker
    cout << "joker" << endl;
  }
  else{//Checks if CardNode's value has an word alternative or 
    if(value == 1)  {
      cout << "Ace";
    }
    else if(value == 11)  {
      cout << "Jack";
    }
    else if(value == 12)  {
      cout << "Queen";
    }
    else if(value == 13)  {
      cout << "King";
    }
    else  {//If no word alternatives are appropriate it will print the number
      cout << value;
    }
    cout << " of " << suit << endl;//prints 
  }  
}

CardStack::CardStack()  {
  size = 0;
  myTop = nullptr;
}

CardStack::CardStack(const CardStack &tempStack) {
  //Initializing CardStack's data members
  size = 0;
  myTop = nullptr;
  *this = tempStack;//Uses Copy Assignment to copy each CardNode of inputed CardStack to the new CardStack 
}

CardStack& CardStack:: operator=(const CardStack &tempCardStack)  {
  CardNode* t1 = myTop;


  if(this->myTop == tempCardStack.myTop) {
    return *this;//if the CardStack is already identical it will return and nothing will be changed
  }

  //Deletes all the CardNodes in CardStack
  t1 = myTop;
  while(myTop != nullptr) { //traverses linked list and deletes each node
    t1 = myTop->next; //t1 will hold andress for next node when myTop needs to be set again after deletion
    delete myTop; 
    myTop = t1;
    size--;//deincrement size
    
  }
  
  
  //copies over all of the nodes from tempCardStack object
  t1 =  tempCardStack.myTop;//sets a pointer to top of tempCardStack for traversal in the while loop
  CardNode* holdThis = myTop;//sets holdThis to top of current CardStack for traversal later on
  while(t1 != nullptr)  {//runs through each node of tempCardStack
    CardNode* temp = new CardNode(t1->value, t1->suit, t1->isJoker);//creates new CardNode
    if(size == 0) {//if no nodes in current CardStack will make it the first
      myTop = temp;
    }
    else  {//will add new node to the end of the list
      holdThis->next = temp;
    } 
    holdThis = temp;//sets holdThis in position for next while loop run
    size++; 
    t1 = t1->next;//goes to next node in tempCardStack
  }  
  return *this;
}
    
CardStack::~CardStack()  {
  CardNode* traverse = myTop;
  while(myTop != nullptr) { //traverses each node in CardStack
    traverse = myTop->next; //holds next node address so myTop can be set after deletion
    delete myTop; 
    myTop = traverse;
    size--;//deincrement size
  }

}

void CardStack::push(int value, string suit, bool isJoker) {
  if(size == MAX_SIZE) {//checks if CardStack is full
    cout << "Card Stack is Full!" << endl;
  }
  else {
    CardNode* temp = new CardNode(value, suit, isJoker);//create a new CardNode
    if(size > 0) {
      temp->next = myTop;//add to top of CardStack
    }
    myTop = temp;//set myTop pointer to new top 
    size++;//updates size data member of CardStack
  }
}

void CardStack::pop() {
  if(size == 0) {//checks if CardStack is empty
    cout << "There is no card to pop." <<endl;
  }
  else  {
    CardNode* temp = myTop;
    myTop->printCard();//prints CardNode details
    temp = myTop->next;//temp holds address of next node so myTop can be set again after deletion
    delete myTop;
    myTop = temp;//set myTop pointer to new top 
    size--;//updates size data member of CardStack
  }
}

int CardStack::getSize()  {
  return size;//returns size of CardStack object
}

int CardStack::countSuit(string inputSuit)  {
  CardNode* traverse = myTop;
  int suitCount = 0;
  while(traverse != nullptr)  {//traverses and checks if CardNode's suit matches inputted suit
    if(traverse->suit == inputSuit) {
      suitCount++;//if there is a CardNode suit that matches input suit, it will update CardStack object's size
    }
    traverse = traverse->next;
  }
  return suitCount;
}

void CardStack::printStack()  {
  CardNode* traverse = myTop;
  while(traverse != nullptr)  {//traverses linked list and prints each CardNode's details
    traverse->printCard();
    traverse = traverse->next;
  }
}




