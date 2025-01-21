class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* l=head;
        ListNode* r=head;
        while(n>0){
            r=r->next;
            n--;
        }
        if(r==NULL){
            head=head->next;
            delete l;
            return head;
        }
        while(r->next!=NULL){
            r=r->next;
            l=l->next;
        }
        if(l->next==r){
            l->next=NULL;
            delete r;
            return head;
        }
        ListNode* tp=l->next;
        l->next=l->next->next;
        tp->next=NULL;
        delete tp;
        return head;
    }
};
