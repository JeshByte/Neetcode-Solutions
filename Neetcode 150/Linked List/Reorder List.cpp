class Solution {
public:
    ListNode* reversed(ListNode* head){
        ListNode* curr=head;
        ListNode* prev=NULL;
        while(head!=NULL){
            head=head->next;
            curr->next=prev;
            prev=curr;
            curr=head;
        }
        return prev;
    }
    int countNodes(ListNode* head){
        ListNode* temp=head;
        int cnt=0;
        while(temp!=NULL){
            temp=temp->next;
            cnt++;
        }
        return cnt;
    }
    void reorderList(ListNode* head) {
        if(head==NULL){
            return;
        }
        int a=countNodes(head);
        int pos=((a+2-1)/2);
        ListNode* temp=head;
        for(int i=1;i<=pos-1;i++){
            temp=temp->next;
        }
        ListNode* rev=temp->next;
        temp->next=NULL;
        rev=reversed(rev);
        temp=head;
        ListNode* temp2=rev;
        while(temp2!=NULL){
            ListNode* tp=temp;
            temp=temp->next;
            tp->next=temp2;
            if(temp==NULL){
                break;
            }
            tp=temp2;
            temp2=temp2->next;
            tp->next=temp;
        }
    }
};
