/*
Philipose, Benjamin 
gamebst.cpp
11/19/2021
DESCRIPTION:Implementation file for Game struct and GameHeap class
ASSUMPTIONS: NONE
SOURCES:NONE
*/

#include "gamebst.h"
#include <iostream>
using namespace std;

TreeNode::TreeNode(string key1, int maxPlayers1, int playtime1): key(key1), maxPlayers(maxPlayers1), playtime(playtime1) {
  right = nullptr;
  left = nullptr;
}
GameBST::GameBST(): rootNode(nullptr), size(0) {}

GameBST::GameBST(const GameBST &tempBST) {
  rootNode = nullptr;
  size = 0;
  *this = tempBST;//using copy assignment operator 
}
GameBST::~GameBST()  {
  deallocGameBST(rootNode);
  rootNode = nullptr;
}
void GameBST::deallocGameBST(TreeNode* node)  {
  if(node != nullptr) {//Post order traversal
    deallocGameBST(node->left);
    deallocGameBST(node->right); 
    delete node;  
  }
}
GameBST& GameBST::operator=(const GameBST &tempBST)  {
  //deletes original GameBST
  deallocGameBST(rootNode);
  rootNode = nullptr;
  //calls helper function to deep copy the GameBST
  deepCopyBST(tempBST.rootNode); 
  size = tempBST.size;
  return *this;
}
void GameBST::deepCopyBST(TreeNode* node)  {
  if(node != nullptr) {//Preorder traversal
    insert(node->key, node->maxPlayers, node->playtime);
    deepCopyBST(node->left);
    deepCopyBST(node->right);
  }
}
void GameBST::insert(string key1, int maxPlayers1, int playtime1)  {
  insert(rootNode, key1, maxPlayers1, playtime1);
}
void GameBST::insert(TreeNode* &node, string key1, int maxPlayers1, int playtime1) {
  if(node == nullptr) {//base case is when it tries to reach past a BST leaf node or empty BST
    node = new TreeNode(key1, maxPlayers1, playtime1);
    if(size == 0) {
      rootNode = node;
    }
    size++;
    return;
  }
  //checks if the node the function is on is equal to input string
  else if(node->key == key1)  {
    cout << "This already exists" << endl;
    return;
  }
  else if(node->key > key1)  {//checks if inputKey is lower than current node, if it is then it will go down the left child
    insert(node->left, key1, maxPlayers1, playtime1);
  }
  else  if(node->key < key1)  {//if current node is lower than input key it will continue down the right child
    insert(node->right, key1, maxPlayers1, playtime1);    
  }
  else  {
    cout << "Insertion Error :(" << endl;
    return;
  }
}
bool GameBST::remove(string name)  {
  return remove(rootNode, name);
}
bool GameBST::remove(TreeNode* &node, string name) {
  //first finds node
  if(node == nullptr) {//cant locate target node
    return false;
  }
  else if(node->key > name) {//Traverses BST left to find target node
    return remove(node->left, name);
  }
  else if(node->key < name) {//Traverses BST right to find target node
    return remove(node->right, name);
  }
  else if(node->key == name)  {//we locate the target node
    if(node->right == nullptr && node->left == nullptr)  {//if node has 0 children
      delete node;
      node = nullptr;
    }
    else if(node->right != nullptr && node->left != nullptr)  {//if node has 2 children
      TreeNode* temp = findSuccessor(node->right);
      size++;
      node->key = temp->key;
      node->maxPlayers = temp->maxPlayers;
      node->playtime = temp->playtime;
      remove(node->right, node->key);//deletes the successors original node
    }
    else  {//if node has 1 child
      if(node->right == nullptr) {//bypasses left child
        TreeNode* oldNode = node;
        node = node->left;
        delete oldNode;
      }
      else  {//bypasses right child
        TreeNode* oldNode = node;
        node = node->right;
        delete oldNode;
      }
    }
    size--;
    return true;
  }
  else  {//if traversal to find target node has an error, will print that it had an error
    cout << "Remove Function Error :(" << endl;
    return false;
  }
}
TreeNode* GameBST::findSuccessor(TreeNode* node) {
  if(node == nullptr) {//if we get to the leafnode but cannot find a suitable successor
    cout << "cannot find a successor" << endl;
    return nullptr;
  }
  else if(node->left == nullptr) {//if we find the successor
    return node;
  }
  else  {//continue traverse the left of the BST branch to find successor
    return findSuccessor(node->left);
  }
}
void GameBST::printPlayable(int timeLeft)  {
  int timesPrinted = 0;
  if(timeLeft <= 0)  {//checks if inputted number is positive
    cout << "You have no time to play any Games :(" << endl;
    return;
  }
  
  cout << "Games you can play in " << timeLeft << " minutes are: " << endl;
  printPlayable(rootNode, timeLeft, timesPrinted);
  
  if(timesPrinted == 0)  {//if no games are printed it will resort to printing there are no games
    cout << "There are no games that you can play in " << timeLeft << " min(s). Sorry." << endl;
    return;
  }
}
void GameBST::printPlayable(TreeNode* node, int timeLeft, int& timesPrinted1)  {
  if(node != nullptr) {//post order traversal
    printPlayable(node->left, timeLeft, timesPrinted1);
    printPlayable(node->right, timeLeft, timesPrinted1); 
    if(node->playtime <= timeLeft)  {
      cout << node->key << endl;
      timesPrinted1++;//counts number of games that are printed
    }
  }
}
void GameBST::printGame(string name) {
  printGame(rootNode, name);
}
void GameBST::printGame(TreeNode* node, string name) {
  if(node == nullptr) {//if target is not located in the BST 
    cout << "No Game Found." << endl;
  }
  else if(node->key == name)  {//if target is found
    cout << "Game: " << node->key << "\nMaximum # of players: " << node->maxPlayers << "\nMinimum playtime: " << node->playtime << " mins" << endl;
  }
  else if(node->key < name) {//traverses right of the BST
    printGame(node->right, name);
  }
  else  {//traverses left of the BST
    printGame(node->left, name);
  }
}
int GameBST::getHeight() { 
  return getHeight(rootNode);
}
int GameBST::getHeight(TreeNode* node)  {
  if(node == nullptr) {//if it tries to reach past a leaf node
    return -1;
  }
  else  {
    //returns the higher height between the left and right subtree
    if((getHeight(node->right)) > (getHeight(node->left))) {
      return (getHeight(node->right) + 1);
    }
    else  {
      return (getHeight(node->left) + 1);
    }
  }
}
void GameBST::print()  {
  print(rootNode);
  cout << "\n";
}
void GameBST::print(TreeNode* node) {
  if(node != nullptr) {//In order traversal
    print(node->left);
    cout << node->key << endl; 
    print(node->right);
  } 
}
int GameBST::getSize()  {//returns number of nodes in GameBST object
  return size;
}
