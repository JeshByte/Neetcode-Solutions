class Node{
    public:
        int key;
        int val;
        Node* left;
        Node* right;
        Node(int key,int val){
            this->key=key;
            this->val=val;
            this->left=NULL;
            this->right=NULL;
        }
};
class LRUCache {
public:
    map<int,Node*>mp;
    int cap;
    int s;
    Node* least;
    Node* most;
    LRUCache(int capacity) {
        cap=capacity;
        s=0;
        mp.clear();
        least=new Node(0,0);
        most=new Node(0,0);
        least->right=most;
        most->left=least;
    }
    void insert(Node* n){
        Node* prev=most->left;
        prev->right=n;
        n->left=prev;
        n->right=most;
        most->left=n;
    }
    void remove(Node* n){
        Node* prev=n->left;
        Node* after=n->right;
        prev->right=after;
        after->left=prev;
        n->left=n->right=NULL;   
    }
    int get(int key) {
        if(mp.count(key)){
            Node* n=mp[key];
            remove(n);
            insert(n);
            return n->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            Node* n=mp[key];
            remove(n);
            n->val=value;
            insert(n);
            return;
        }
        if(s==cap){
            Node* n=least->right;
            mp.erase(n->key);
            remove(n);
            s--;
        }
        Node* newNode=new Node(key,value);
        mp[key]=newNode;
        insert(newNode);
        s++;
    }
};
