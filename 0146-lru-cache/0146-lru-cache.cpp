class Node {
private:
    int key;
    int val;
    Node* next;
    Node* prev;

public:
    Node(int key, int val) {
        this->key = key;
        this->val = val;
        next = nullptr;
        prev = nullptr;
    }
    friend class LRUCache;
};

class LRUCache {
private:
    unordered_map<int, Node*> m;
    Node* head;
    Node* tail;
    int mySize;

    void deleteNode(Node* n) {
        Node* prevNode = n->prev;
        Node* nextNode = n->next;
        n->prev = nullptr;
        n->next = nullptr;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void insertAtHead(Node* n) {
        Node* headNext = head->next;
        n->next = headNext;
        n->prev = head;
        head->next = n;
        headNext->prev = n;
    }

public:
    LRUCache(int capacity) {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        mySize = capacity;
        m.clear();
    }

    int get(int key) {
        if (m.find(key)!=m.end()) {
            Node* temp = m[key];
            deleteNode(temp);
            insertAtHead(temp);
            return temp->val;
        } else {
            return -1;
        }
    }

    void put(int key, int value) {
        auto it = m.find(key);
        if (it!=m.end()) {
            //value present in map
            Node* temp = m[key];
            temp->val = value;
            deleteNode(temp);
            insertAtHead(temp);
            m[key]=temp;
        } else {
            if (m.size() < mySize) {
                // capacity is still there
                // value is not present in the map
                Node* n = new Node(key, value);
                m[key]=n;
                insertAtHead(n);

            } else {
                // no capacity left
                Node* temp = tail->prev;
                m.erase(temp->key);
                deleteNode(temp);

                Node* n = new Node(key, value);
                m[key] = n;
                insertAtHead(n);
            }
        }
    }

    ~LRUCache() {
        Node* current = head->next;
        while (current != tail) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        delete head;
        delete tail;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */