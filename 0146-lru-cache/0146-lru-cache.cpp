#include<list>
// class Node{
//     private:
//         pair<int,int> val;
//         Node* next;
    
//     public:

//     Node(int key, int value, Node* next = nullptr) : val{key,value}, next(next) {}
// };

// class ListNode{
//     private:
//         Node* root;
//         int size;

//     public:
//         ListNode() : root(nullptr), size(0) {}
// }


class LRUCache {
private:
    int capacity;
    list<pair<int,int>> lru;
    unordered_map<int, list<pair<int,int>>::iterator> cache; // key -> iterator

public:
    LRUCache(int capacity) : capacity(capacity) {}
    
    int get(int key) {
        // what if the there is no node in list ? 
        //value not present in the cache
        if(cache.find(key) == cache.end()) return -1;

        auto it = cache[key];
        lru.splice(lru.begin(), lru, it); // gets the key at the front of the list
        cache[key] = lru.begin();

        return lru.begin()->second;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()){
            auto it = cache[key];
            it->second = value;
            lru.splice(lru.begin(), lru, it);
            cache[key] = lru.begin();
            return;
        }

        // check if the capacity is full
        if(lru.size() == capacity){
            //remove from the back
            cache.erase(lru.back().first);
            lru.pop_back();
        }

        lru.push_front({key,value});
        cache[key] = lru.begin();

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */