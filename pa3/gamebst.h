/*
Philipose, Benjamin 
gamebst.h
11/3/2021
DESCRIPTION:Header file for GameBST class. Defines the functions for the class.
ASSUMPTIONS:NONE
SOURCES:NONE
*/

#include <string>
using namespace std;
struct TreeNode{ 
  string key;     //name of the game 
  int maxPlayers; //maximum number of players 
  int playtime;   //minimum playtime 
  TreeNode* left; 
  TreeNode* right; 
  TreeNode(string key1, int maxPlayers1, int playtime1);
  /*
  DESCRIPTION: paramaterized constructor for TreeNode
  PRE: NONE
  POST: Creates new TreeNode object
  */
}; 

class GameBST {
  public:
    GameBST();
    /*
    DESCRIPTION: default constructor for Game BST objects
    PRE: NONE
    POST: Creates new GameBST object
    */
    GameBST(const GameBST &tempBST);
    /*
    DESCRIPTION: copy constructor for Game BST objects
    PRE: NONE
    POST: Creates new GameBST object
    */
    ~GameBST();
    /*
    DESCRIPTION: destructor for Game BST objects
    PRE: NONE
    POST: Deletes GameBST's nodes and sets root node to nullptr
    */
    GameBST& operator=(const GameBST &tempBST);//
    /*
    DESCRIPTION:copy assignment for Game BST objects
    PRE: NONE
    POST: Creates new GameBST object
    */
    void insert(string key1, int maxPlayers1, int playtime1);
    /*
    DESCRIPTION: caller functions that inserts node into binary tree with necessary data members and ranked alphabetically
    PRE: NONE
    POST: Inserts new node into the GameBST object
    */
    bool remove(string name);
    /*
    DESCRIPTION: caller functions that returns true if there is a node with a game matching the input
    PRE: NONE
    POST: Removes node from the GameBST object
    */
    void printGame(string name);
    /*
    DESCRIPTION: caller functions that finds and prints datamembers for inputed game
    PRE: NONE
    POST: NONE
    */
    void printPlayable(int timeLeft);    
    /*
    DESCRIPTION: caller functions that finds and prints games that have playtime less than or equal to timeLeft using post-order traversal
    PRE: NONE
    POST: NONE
    */
    int getHeight();
    /*
    DESCRIPTION: caller functions that returns height of the tree
    PRE: NONE
    POST: NONE
    */
    void print();
    /*
    DESCRIPTION: caller functions that prints tree values in inorder traversal
    PRE: NONE
    POST: NONE
    */
    int getSize();
    /*
    DESCRIPTION: prints number of nodes in GameBST
    PRE: NONE
    POST: NONE
    */
  private:
    TreeNode* rootNode;
    int size;
    void deallocGameBST(TreeNode* node);
    /*
    DESCRIPTION: recursive helper function for GameBST destructor
    PRE: inputted node must be initialized
    POST: Deletes all of the nodes in Game BST
    */
    void deepCopyBST(TreeNode* node);
    /*
    DESCRIPTION: recursive helper Function for Copy Assignment Operator Function
    PRE: inputted node must be initialized
    POST: Traverses and deep copies all values of inputed GameBST's rootNode to current GameBST
    */
    void insert(TreeNode* &node, string key1, int maxPlayers1, int playtime1);
    /*
    DESCRIPTION: recursive helper function for Insert function
    PRE: inputted node must be initialized
    POST: Inserts a new node for GameBST
    */
    bool remove(TreeNode* &node, string name);
    /*
    DESCRIPTION: recursive helper function for remove function which recursively finds and removes target node
    PRE: inputted node must be initialized
    POST: returns true if remove function is successful and false if not
    */
    TreeNode* findSuccessor(TreeNode* node);
    /*
    DESCRIPTION: recursive helper function for remove function to find sucessor node for removal of target node with 2 children
    PRE: inputted node must be initialized
    POST: returns pointer to the successor node
    */
    void printGame(TreeNode* node, string name);
    /*
    DESCRIPTION: recursive helper function for printGame function
    PRE: inputted node must be initialized
    POST: NONE
    */
    void printPlayable(TreeNode* rootNode, int timeLeft, int& timesPrinted);
    /*
    DESCRIPTION: recursive helper function for printPlayable function
    PRE: inputted node must be initialized
    POST: NONE
    */
    int getHeight(TreeNode* node);
    /*
    DESCRIPTION: recursive helper for getHeight function
    PRE: inputted node must be initialized
    POST: NONE
    */
    void print(TreeNode* node);
    /*
    DESCRIPTION: recursive helper for print function
    PRE: inputted node must be initialized
    POST: NONE
    */
};