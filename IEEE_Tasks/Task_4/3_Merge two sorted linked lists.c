SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {

    if(head1 == NULL) 
        return head2;
    if(head2 == NULL) 
        return head1;
    
    
    SinglyLinkedListNode* temp = (SinglyLinkedListNode*)malloc(sizeof(SinglyLinkedListNode));
    SinglyLinkedListNode* current = temp;
    
    
    while(head1 != NULL && head2 != NULL){
        if (head1->data <= head2->data){
            current->next = head1;
            head1 = head1->next;
        } 
        else{
            current->next = head2;
            head2 = head2->next;
        }
        current = current->next;
    }
    
    // take all teh elements in the not empty list
    if (head1 != NULL) { 
        current->next = head1;
    } else {
        current->next = head2;
    }
    
    
    SinglyLinkedListNode* mergedList = temp->next;
    
    return mergedList;
}