DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* llist, int data) {
    DoublyLinkedListNode* newNode = (DoublyLinkedListNode*)malloc(sizeof(DoublyLinkedListNode));
    if (newNode == NULL) {
        
        return llist;
    }
    
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (llist == NULL) {
        return newNode;
    }

    DoublyLinkedListNode* NodeAfter = llist;

    
    while(NodeAfter != NULL){
        if(NodeAfter->data >= data){
            
            if(NodeAfter->prev == NULL){
                
                newNode->next = NodeAfter;
                NodeAfter->prev = newNode;
                return newNode; // first node
            } 
            
            else{
                newNode->prev = NodeAfter->prev;
                newNode->next = NodeAfter;
                NodeAfter->prev->next = newNode;
                NodeAfter->prev = newNode;
                return llist; 
            }
        }

        if (NodeAfter->next == NULL) {
            
            NodeAfter->next = newNode;
            newNode->prev = NodeAfter;
            return llist; 
        }

        NodeAfter = NodeAfter->next;
    }

    return llist; 
}