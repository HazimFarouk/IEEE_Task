#include"platform.h"
#include"SLL.h"
#include<stdio.h>


void Add_Node_At_Beginning(Node_t **ListHead,sint32 Data) /*Double pointer because we want to change the
                                                            address which the head points to*/
{
    Node_t *NewHead = NULL; /*Create the new node and allocate it*/
    NewHead = (Node_t *)malloc(sizeof(Node_t));
    if(NULL != NewHead) /*Check if the node had been created or not*/
    {
        /*Give the data to the node then change the head*/
        NewHead->NodeData = Data;
        NewHead->NodeLink = *ListHead;
        *ListHead = NewHead;
    }
    else /*Failed to allocate the node*/
    {
        printf("Can't create the new node...\n");
    }
}

void Add_Node_At_End(Node_t **ListHead,sint32 Data) /*Double pointer because the list may be empty or null so we have
                                                      to create the first node and give it's address to the head*/
{
    Node_t *NewNode = NULL;
    Node_t *LastNode = *ListHead; /*Points to the last node*/
    NewNode = (Node_t *)malloc(sizeof(Node_t)); /*Allocate the new node*/
    if(NULL != NewNode) /*Check if the node had been created or not*/
    {
        NewNode->NodeData = Data;
        NewNode->NodeLink =NULL;
        if(NULL == *ListHead) /*Check if the list is empty and if this true set the new head*/
        {
            *ListHead = NewNode;
        }
        else /*The list contain nodes so that we had to reach to the last element and add a node after*/
        {
            while(NULL != LastNode->NodeLink)
            {
                LastNode = LastNode->NodeLink;
            }
            LastNode->NodeLink = NewNode;
        }
    }
    else  /*Failed to create the new node*/
    {
        printf("Can't creae new node..\n");
    }
}

void Add_Node_After(Node_t *ListHead,sint32 Data , uint32 Position) /*To add a node after another node we need
 three pointers one points to the nodewe want to add after and the next node finally the address of the new node*/
{
    Node_t *NewNode = NULL;
    Node_t *PreNode = ListHead;
    Node_t *NextNode = NULL;
    uint32 Size = ListSize(ListHead); /*Number of nodes in the list */
    if(Size >= Position) /*Check if the position is valid or not*/
    {
        if( 0 == Position) /*If the position is 0 then he should use add at beginning*/
        {
            printf("Use add at beginning...\n");
        }
        else if(Size > Position) /*Check if the position is lower than size of list*/
        {
            /*Create the new node*/
            NewNode = (Node_t *)malloc(sizeof(Node_t)); /*Create the new node*/
            if(NULL != NewNode) //Check if the node had been created
            {
                /*Go to the node we want to add after the link the three nodes with each other*/
                while(--Position)
                {
                    PreNode = PreNode->NodeLink;
                }


                PreNode->NodeLink = NewNode;
                NewNode->NodeData = Data;

                NewNode->NodeLink = NextNode;
            }
            else
            {
                printf("Can't create the node\n");
            }
        }
        else /*The position equal to the size so that add the node at the end*/
        {
            Add_Node_At_End(&ListHead , Data);
        }
    }
    else /*The position is bigger than number of element in the list so it is a invalid position*/
    {
        printf("Invalid Position\n");
    }
}

void Delete_Node_At_Beginning(Node_t **ListHead) /*Double pointer because we want to change the
                                                   address which the head points to*/
{
    //Node_t *TempNode = NULL;
    if(*ListHead  == NULL) /*Check if the list empty so there is nothing to delete*/
    {
        printf("List is empty\n");
    }
    else
    {
        /*Make the head points to the next node then free the first node*/

        *ListHead = (*ListHead)->NodeLink;

        //TempNode = *ListHead;
        //*ListHead = TempNode->NodeLink;
        //free(TempNode);
    }
}

void Delete_Node_At_End(Node_t **ListHead)  /*Double pointer because the list may contain one node
                                              so we need to make the head points to null*/
{

    Node_t *TempNode = NULL; /*The last node we want to delete*/
    Node_t *LastNode = NULL; /*The node before the last node*/
    uint32 Counter = ListSize(*ListHead); /*Number of nodes in the list*/
    if(*ListHead == NULL)
    {
        printf("List is empty...\n");
    }
    else
    {
        if(Counter == 1) /*If the list contain one node delete it and make the head points to null*/
        {
            *ListHead = NULL;
        }
        else
        {
            /*Reach to the node before the last node and  link it with null then deallocate the last node*/
            LastNode = *ListHead;
            while(Counter > 2 )
            {
                Counter--;
                LastNode = LastNode->NodeLink;
            }
            TempNode = LastNode->NodeLink;
            free(TempNode);
            LastNode->NodeLink = NULL;
        }
    }
}

void Delete_Node_At_Specific_Position(Node_t *ListHead ,uint32 Position) /*To delere a node at specific position we need
three pointers one points to the node we want to delete and the next node and the previous node*/
{
    Node_t *TempNode = NULL;             /*The node we want to delete*/
    Node_t *PreNode = ListHead;          /*The node before the node we want to delete*/
    Node_t *NextNode = NULL;             /*The node after the node we want to delete*/
    uint32 Counter = ListSize(ListHead); /*Number of node in list*/
    if(NULL == ListHead)
    {
        printf("List Is EMPTY\n");
    }
    else
    {
        if(Position > Counter || Position == 0)
        {
            printf("Invalid Position...\n");
        }
        else if(Position == 1) /*Delete the first node*/

        {
            printf("Use Delete at beginning...\n");
        }
        else
        {
            /*Reach to the node we want to delete and deallocate it the connect the previous and next nodes with other*/
            while(Position > 2)
            {
                Position--;
                PreNode = PreNode->NodeLink;
            }

            TempNode = PreNode->NodeLink;
            NextNode = TempNode->NodeLink;
            PreNode->NodeLink = NextNode;
            free(TempNode);
        }
    }
}

uint32 ListSize(Node_t *ListHead)
{
    uint32 Counter = 0;
    Node_t *TempNode = ListHead;
    while(TempNode != NULL)
    {
        TempNode = TempNode->NodeLink;
        Counter++;
    }
    return Counter;
}

void ListDisplay(Node_t *ListHead)
{
    Node_t *TempNode = ListHead;
    printf("The List Data : ");
    while(NULL != TempNode)
    {
        printf("%i ->\t",TempNode->NodeData);
        TempNode = TempNode->NodeLink;
    }
    printf("NULL\n");
}

void ListTest(void)
{
    Node_t *Node = NULL; //Linked list head
    sint32 num1 = 11 ,num2 = 22, num3 = 33 , num4 = 44 , num5= 55 , num6 = 66 , num7  = 77 ;
    uint32 size = 0;
    Add_Node_At_Beginning(&Node , num3);        ListDisplay(Node);
    Add_Node_At_Beginning(&Node , num2);        ListDisplay(Node);
    Add_Node_At_Beginning(&Node , num1);        ListDisplay(Node);
    Add_Node_After(Node , num4 , 3);            ListDisplay(Node);
    Add_Node_After(Node , num5 , 4);            ListDisplay(Node);
    Add_Node_At_End(&Node , num6);              ListDisplay(Node);
    Add_Node_At_End(&Node , num7);              ListDisplay(Node);

    size = ListSize(Node);
    printf("Size of list = %i\n", size);
    printf("===================================================\n");

    Delete_Node_At_Specific_Position(Node , 0);    ListDisplay(Node);
    Delete_Node_At_Specific_Position(Node , 10);   ListDisplay(Node);

    Delete_Node_At_Specific_Position(Node , 5);    ListDisplay(Node);
    Delete_Node_At_Specific_Position(Node , 4);    ListDisplay(Node);

    Delete_Node_At_Beginning(&Node);               ListDisplay(Node);
    Delete_Node_At_Beginning(&Node);               ListDisplay(Node);
    Delete_Node_At_Beginning(&Node);               ListDisplay(Node);

    Delete_Node_At_End(&Node);                     ListDisplay(Node);
    Delete_Node_At_End(&Node);                     ListDisplay(Node);
    Delete_Node_At_End(&Node);                     ListDisplay(Node);
}

