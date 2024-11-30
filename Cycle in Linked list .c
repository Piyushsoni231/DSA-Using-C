bool hasCycle(struct ListNode *head) {
    if(head==NULL || head->next==NULL){
        return false;
    }
    else{
        struct ListNode *fast=head;
        struct ListNode *slow = head;
        while(fast!=NULL && fast->next !=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast){
                return true;
            }
        }
        return false;
    }
}
