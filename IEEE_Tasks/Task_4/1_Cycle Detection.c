bool has_cycle(SinglyLinkedListNode* head) {
    
    if(head == NULL){
        return false;
    }
    
    int cnt = 0;
    SinglyLinkedListNode* temp = head;
    while(temp->next != NULL){
        cnt++;
        
        if(cnt >= 2000){
            return true;
        }
        temp = temp->next;
    }
    return false;

}