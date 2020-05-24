/**

LRU Cache : https://leetcode.com/problems/lru-cache/
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

The cache is initialized with a positive capacity.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LRUCache cache = new LRUCache( 2 /* capacity */ );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4

**/

struct DoublyListNode{
    int key;
    int val;
    DoublyListNode *next;
    DoublyListNode *prev;   
};

typedef DoublyListNode Dnode;

class LRUCache {
public:
    Dnode *front, *rear, *head;
    map<int, Dnode*> mp;
    int count;
    int cache_size;
    
    LRUCache(int capacity) {
        cache_size = capacity;
        count = 0;
    }
    
    Dnode* get_new_dnode(int key=0, int val=0) {
        Dnode* temp = new DoublyListNode();
        temp->key = key;
        temp->val = val;
        temp->prev = temp->next = NULL;
        return temp;
    }
    
    void display_doubly() {
        cout<<"Current Size : "<<count<<"\n";
        cout<<"Doubly list is : ";
        Dnode *ptr = head;
        while(ptr!=NULL) {
            cout<<"(Key: "<<ptr->key<<", Value: "<<ptr->val<<") ";
            ptr = ptr->next;
        }
        cout<<"\nMap is : ";
        for(auto i = mp.begin(); i!=mp.end();i++) {
            cout<<"("<<i->first<<","<<i->second->val<<") ";
        }
        cout<<"\n";
    }
    
    bool is_cache_full() {
        return count == cache_size;
    }
    
    void delete_from_front() {
        if(front==NULL)
            return;
        
        Dnode* temp = front;
        
        int key = temp->key;
        auto it = mp.find(key); 
        mp.erase(it); 
        
        front = temp->next;
        if(front!=NULL)
            front->prev = NULL;
        head = front;
        
        delete(temp);
        count--;   
    }
    
    void add_node(int key, int val) {
        if(get(key)!=-1)
        {
            Dnode* temp;
            temp = mp[key];
            delete_this_node(temp);
        }
        
        if(is_cache_full())
        {
           delete_from_front(); 
        }
        
        if(count == 0)
        {
            head = get_new_dnode(key, val);
            front = rear = head; 
            mp[key] = head;
        }
        else
        {
            Dnode* temp = get_new_dnode(key, val);
            temp->prev = rear;
            rear->next = temp;
            rear = temp;
            mp[key] = temp;
        }
         count++;   
    }
    
    void delete_this_node(Dnode *tmp) {
        Dnode* temp = tmp;
        int key = temp->key;
        auto it = mp.find(key); 
        mp.erase(it); 
        
        if(temp == front)
        {
            if(front->next!=NULL)
                front->next->prev = NULL;
            front = front->next;
            head  = front;
        }
        else if(temp == rear)
        {
            rear->prev->next = NULL;
            rear = rear->prev;
        }
        else
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }
        
        delete(temp);
        count--;
    }
    
    int get(int key) {
        
       Dnode* temp;
        
       if(mp.find(key) == mp.end())
           return -1;
       else
           temp = mp[key];
        
       int val = temp->val;
       
       if(temp!=rear)
       {
            delete_this_node(temp);
            add_node(key, val);
       }
       
       return val; 
    }
    
    void put(int key, int value) {
        add_node(key, value);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

