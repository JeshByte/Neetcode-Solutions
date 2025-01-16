class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //iterative approach
        // ListNode* curr=head;
        // ListNode* prev=NULL;
        // while(head!=NULL){
        //     head=head->next;
        //     curr->next=prev;
        //     prev=curr;
        //     curr=head;
        // }
        // return prev;

        //recursive approach
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* h2=reverseList(head->next);
        head->next->next=head;
        head->next=NULL;
        return h2;
    }
};
