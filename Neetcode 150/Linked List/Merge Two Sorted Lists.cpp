class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if((list1==NULL && list2==NULL)||(list1!=NULL && list2==NULL)){
            return list1;
        }
        if(list1==NULL && list2!=NULL){
            return list2;
        }
        ListNode* temp1=list1;
        ListNode* temp2=list2;
        ListNode* prev=NULL;
        ListNode* head=list1;
        while(temp1!=NULL && temp2!=NULL){
            if(temp1->val<=temp2->val){
                prev=temp1;
                temp1=temp1->next;
            }
            else{
                ListNode* tp=temp2;
                temp2=temp2->next;
                tp->next=NULL;
                if(prev==NULL){
                    tp->next=temp1;
                    head=tp;
                    prev=tp;
                }
                else{
                    prev->next=tp;
                    tp->next=temp1;
                    prev=tp;
                }
            }
        }
        ListNode* last=head;
        while(last->next!=NULL){
            last=last->next;
        }
        while(temp2!=NULL){
            last->next=temp2;
            last=temp2;
            temp2=temp2->next;
        }
        return head;
    }
};
