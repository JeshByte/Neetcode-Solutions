class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL){
            return head;
        }
        Node* temp=head;
        Node* newhead=new Node(temp->val);
        Node* prev=newhead;
        temp=temp->next;
        while(temp!=NULL){
            Node* newnode=new Node(temp->val);
            prev->next=newnode;
            prev=prev->next;
            temp=temp->next;
        }
        temp=head;
        Node* temp2=newhead;
        while(temp!=NULL && temp2!=NULL){
            Node* tp=temp;
            temp=temp->next;
            tp->next=temp2;
            tp=temp2;
            temp2=temp2->next;
            tp->next=temp;
        }
        temp=head;
        while(temp!=NULL){
            if(temp->random){
                temp->next->random=temp->random->next;
            }
            temp=temp->next->next;
        }
        temp=head;
        temp2=newhead;
        while(temp!=NULL && temp2!=NULL){
            temp->next=temp->next->next;
            temp=temp->next;
            if(temp2->next){
            temp2->next=temp2->next->next;
            }
            temp2=temp2->next;
        }
        return newhead;
    }
};
