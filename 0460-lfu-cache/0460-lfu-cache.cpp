
class Node {
private:
    int key;
    int val;
    int cnt;
    Node* next;
    Node* prev;

public:
    Node(int key, int val) {
        this->key = key;
        this->val = val;
        cnt=1;
        next = nullptr;
        prev = nullptr;
    }
    friend class List;
    friend class LFUCache;
};

class List{
private:
    int size;
    Node* head;
    Node* tail;

public:
    List(){
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void insertAtHead(Node* n) {
        Node* headNext = head->next;
        n->next = headNext;
        n->prev = head;
        head->next = n;
        headNext->prev = n;
        size++;
    }

    void deleteNode(Node* n) {
        Node* prevNode = n->prev;
        Node* nextNode = n->next;
        n->prev = nullptr;
        n->next = nullptr;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        size--;
    }
    friend class LFUCache;
};


class LFUCache {

private:
    unordered_map<int,Node*> m;
    unordered_map<int, List*> freqMap;
    int cap;
    int minfreq;
    int currsize;    

public:
    LFUCache(int capacity) {
        cap = capacity;
        minfreq= 0;
        currsize= 0;
    }

    void updateFreqListMap(Node* n){
        m.erase(n->key);
        freqMap[n->cnt]->deleteNode(n);
        if(n->cnt == minfreq && freqMap[n->cnt]->size==0){
            minfreq++;
        }

        List *nextHigherFreqList = new List();
        if(freqMap.find(n->cnt+1)!=freqMap.end()){
            nextHigherFreqList = freqMap[n->cnt+1];
        }

        n->cnt += 1;
        nextHigherFreqList->insertAtHead(n);
        freqMap[n->cnt] = nextHigherFreqList;
        m[n->key]=n;
    }
    
    int get(int key) {
        if(m.find(key)!=m.end()){
            //key is present in the cache
            Node* temp = m[key];
            int value = temp->val;

            //update its frequency list;
            updateFreqListMap(temp);

            //return the value
            return value;
        }else{
            //value is not present in the cache(map)
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(cap==0)
            return;
        

        auto it = m.find(key);
        if(it!=m.end()){
            //key is present in the map
            Node* n = m[key];
            n->val = value;
            updateFreqListMap(n);
        }else{
            //key is not present in the map
            //if currsize is equal to capacity 
            if(currsize==cap){
                List *list = freqMap[minfreq];
                m.erase(list->tail->prev->key);
                freqMap[minfreq]->deleteNode(list->tail->prev);
                currsize--;
            }
            currsize++;
            minfreq = 1;
            List* listfreq = new List();
            if(freqMap.find(minfreq)!=freqMap.end()){
                listfreq = freqMap[minfreq];
            }
            Node* n = new Node(key, value);
            listfreq->insertAtHead(n);
            m[key]=n;
            freqMap[minfreq]=listfreq;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */