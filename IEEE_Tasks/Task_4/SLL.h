#include"platform.h"

typedef struct Node
{
    sint32 NodeData;
    struct Node *NodeLink;
}Node_t;


/*
============Add_Node_At_Beginning============
  *  Breif : Function to add a node at beginning
  *  Parameters : ListHead -> The head of the list
  *               Data -> The added data
  *  Return : void
*/
void Add_Node_At_Beginning(Node_t **ListHead,sint32 Data);

/*
============Add_Node_At_End============
  *  Breif : Function to add a node at end
  *  Parameters : ListHead -> The head of the list
  *               Data -> The added data
  *  Return : void
*/
void Add_Node_At_End(Node_t **ListHead,sint32 Data);

/*
============Add_Node_After============
  *  Breif : Function to add a node after specifiec position
  *  Parameters : ListHead -> The head of the list
  *               Data -> The added data
                  Position -> The position we will add a data after
  *  Return : void
*/
void Add_Node_After(Node_t *ListHead,sint32 Data , uint32 Position);

/*
============Delete_Node_At_Beginning============
  *  Breif : Function to delete a node at beginning
  *  Parameters : ListHead -> The head of the list
  *  Return : void
*/
void Delete_Node_At_Beginning(Node_t **ListHead);

/*
============Delete_Node_At_End============
  *  Breif : Function to delete a node at end
  *  Parameters : ListHead -> The head of the list
  *  Return : void
*/
void Delete_Node_At_End(Node_t **ListHead);

/*
============Delete_Node_At_Specifiec_Position============
  *  Breif : Function to delete a node at specifiec position
  *  Parameters : ListHead -> The head of the list
  *               Position -> The position we will add a data after
  *  Return : void
*/
void Delete_Node_At_Specific_Position(Node_t *ListHead ,uint32 Position);

/*
============ListSize============
  *  Breif : Function to get the size of the list
  *  Parameters : ListHead -> The head of the list
  *  Return : Number of elements int the list
*/
uint32 ListSize(Node_t *ListHead);

/*
============ListDisplay============
  *  Breif : Function to display all nodes in the list
  *  Parameters : ListHead -> The head of the list
  *  Return : void
*/
void ListDisplay(Node_t *ListHead);

/*
============ListDisplay============
  *  Breif : Function to check all the previous functions
  *  Parameters : void
  *  Return : void
*/
void ListTest(void);
