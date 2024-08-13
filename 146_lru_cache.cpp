class Node{ 
    public:
    int key, val;
    Node* prev, *next;
    Node(int key, int value) : key(key), val(value), prev(nullptr), next(nullptr){}
};
class LRUCache {
    int cap;
    unordered_map<int, Node* > cache;
    Node *left;
    Node *right;

    //insert at the right end
    void insert(Node* node){
        right->prev->next = node;
        node->prev = right->prev;
        node->next = right;
        right->prev = node;
    }
    //remove from the linked list
    void remove(Node* node){
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
        //node->prev->next = node->next;
        //node->next->prev = node->prev;
    }
public:
    LRUCache(int capacity) {
        cap = capacity;
        cache.clear();
        left = new Node(0,0);
        right = new Node(0,0);
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        if(cache.find(key) == cache.end())
            return -1;
        else{
            Node* temp = cache[key];
            remove(temp);
            insert(temp);
            return temp->val;
        }
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()){
            remove(cache[key]);
        }
        Node* newNode = new Node(key, value);
        cache[key] = newNode;
        insert(newNode);
        if(cache.size() > cap){
            Node* node = left->next;
            remove(node);
            cache.erase(node->key);
            delete node;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */