class Solution {
public:
    ListNode* merge(ListNode* h1,ListNode* h2){
        if((h1==NULL && h2==NULL ) || (h1!=NULL && h2==NULL)){
            return h1;
        }
        if(h2!=NULL && h1==NULL){
            return h2;
        }
        ListNode* temp1=h1;
        ListNode* temp2=h2;
        ListNode* prev=NULL;
        ListNode* head=h1;
        while(temp1!=NULL && temp2!=NULL){
            if(temp1->val<temp2->val){
                prev=temp1;
                temp1=temp1->next;
            }
            else{
                ListNode* tp=temp2;
                temp2=temp2->next;
                tp->next=NULL;
                if(prev==NULL){
                    tp->next=head;
                    head=tp;
                    prev=tp;
                    continue;
                }                
                prev->next=tp;
                tp->next=temp1;
                prev=tp;
            }
        }
        ListNode* last=head;
        while(last->next!=NULL){
            last=last->next;
        }
        while(temp2!=NULL){
            ListNode* tp=temp2;
            temp2=temp2->next;
            tp->next=NULL;
            last->next=tp;
            last=tp;
        }
        return head;
    }
    ListNode* sorted(vector<ListNode*>& lists,int l,int r){
        if(l>r){
            return NULL;
        }
        if(l==r){
            return lists[l];
        }
        int mid=l+(r-l)/2;
        ListNode* left=sorted(lists,l,mid);
        ListNode* right=sorted(lists,mid+1,r);
        return merge(left,right);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()){
            return NULL;
        }
        return sorted(lists,0,lists.size()-1);
    }
};
