class LRUCache {
public:
    class node {
        public:
            int key;
            int val;
            node *next;
            node *prev;

            node(int key, int val){
                this->key = key;
                this->val = val;
            }
    };

    node *head  = new node(-1, -1);
    node *tail = new node(-1, -1);
    int cap;
    unordered_map<int, node*> m;

    void addnode(node *newnode){
        node *temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }

    void deletenode(node *delnode){
        node *delprev = delnode->prev;
        node *delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;    
    }
    
    int get(int key) {
        if(m.find(key) != m.end()){
            node *temp = m[key];
            int num = temp->val;
            m.erase(key);
            deletenode(temp);
            addnode(temp);
            m[key] = head->next;
            return num;
        }

        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end()){
            node *temp = m[key];
            m.erase(key);
            deletenode(temp);
        }
        if(m.size() == cap){
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(key, value));
        m[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */