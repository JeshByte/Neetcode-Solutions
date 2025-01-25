// Recursive Solution
// class Solution {
// public:
//     ListNode* reversed(ListNode* head){
//         ListNode* curr=head;
//         ListNode* prev=NULL;
//         while(head!=NULL){
//             head=head->next;
//             curr->next=prev;
//             prev=curr;
//             curr=head;
//         }
//         return prev;
//     }
//     ListNode* reverseKGroup(ListNode* head, int k) {
//         if(head==NULL){
//             return head;
//         }
//         ListNode* after=head;
//         int i=1;
//         while(after!=NULL && i<=k-1){
//             after=after->next;
//             i++;
//         }
//         if(after==NULL){
//             return head;
//         }
//         ListNode* temp;
//         temp=reverseKGroup(after->next,k);
//         after->next=NULL;
//         head=reversed(head);
//         ListNode* last=head;
//         while(last->next!=NULL){
//             last=last->next;
//         }
//         last->next=temp;
//         return head;
//     }
// };

// Iterative Solution(O(1) Space)
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy=new ListNode(0);
        ListNode* dummy_tail=dummy;
        ListNode* temp=head;
        while(temp!=NULL){
            ListNode* store=temp;
            for(int i=1;i<=k-1;i++){
                if(temp){
                temp=temp->next;
                }
                else{
                    break;
                }
            }
            if(temp==NULL){
                dummy_tail->next=store;
                dummy_tail=dummy_tail->next;
                break;
            }
            ListNode* tp=temp->next;
            temp->next=NULL;
            temp=head;
            head=reversed(head);
            dummy_tail->next=head;
            dummy_tail=temp;
            temp=tp;
            head=tp;
        }
        ListNode* newhead=dummy->next;
        dummy->next=NULL;
        delete dummy;
        return newhead;
    }
};
