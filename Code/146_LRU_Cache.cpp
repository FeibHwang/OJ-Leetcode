/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LRUCache cache = new LRUCache( 2 // capacity  );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
*/

/*
List + hash_map
hash map to realize O(1) get
list to realize O(1) delete
*/

class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
        head = new node(-1,-1);
        tail = new node(-1,-1);
        head->next = tail;
        tail->prev = head;
        hold = 0;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;
        mp[key]->prev->next = mp[key]->next;
        mp[key]->next->prev = mp[key]->prev;
        pushfront(mp[key]);
        return mp[key]->val;
    }
    
    void put(int key, int value) {
        if(mp.find(key)==mp.end())
        {
            mp[key] = new node(key,value);
            pushfront(mp[key]);
            if(hold==cap) deletenode();
            else hold++;
            return;
        }else{
            if(mp[key]->val != value)
            {
                mp[key]->prev->next = mp[key]->next;
                mp[key]->next->prev = mp[key]->prev;
                pushfront(mp[key]);
                mp[key]->val = value;
            }
        }
    }
    
private:
    
    
    struct node
    {
        int val;
        int key;
        node *next;
        node *prev;
        node(int key,int val): val(val),key(key),next(NULL),prev(NULL){};
    };
    
    unordered_map<int,node*> mp;
    
    int cap;
    int hold;
    
    node* head;
    node* tail;
    
    void deletenode()
    {
        int d = tail->prev->key;
        mp[d]->prev->next = tail;
        mp[d]->next->prev = mp[d]->prev;
        mp.erase(d);
    }
    
    void pushfront(node *n)
    {
        n->next = head->next;
        n->prev = head;
        head->next = n;
        n->next->prev = n;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */