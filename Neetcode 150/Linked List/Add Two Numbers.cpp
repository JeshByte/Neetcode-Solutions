class Solution {
public:
    int countNodes(ListNode* head){
        int cnt=0;
        ListNode* temp=head;
        while(temp!=NULL){
            temp=temp->next;
            cnt++;
        }
        return cnt;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int cnt1=countNodes(l1);
        int cnt2=countNodes(l2);
        if(cnt1<cnt2){
            return addTwoNumbers(l2,l1);
        }
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        int carry=0;
        while(temp1!=NULL && temp2!=NULL){
            int s=temp1->val+temp2->val+carry;
            if(s>9){
                s=s%10;
                carry=1;
            }
            else{
                carry=0;
            }
            temp1->val=s;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        if(carry==1){
            while(temp1!=NULL){
            int s=temp1->val+carry;
            if(s>9){
                s=s%10;
                carry=1;
            }
            else{
                carry=0;
            }
            temp1->val=s;
            temp1=temp1->next;
            }
            if(carry==1){
                ListNode* last=l1;
                while(last->next!=NULL){
                    last=last->next;
                }
                ListNode* newNode=new ListNode(1);
                last->next=newNode;
            }
        }
        return l1;
    }
};
