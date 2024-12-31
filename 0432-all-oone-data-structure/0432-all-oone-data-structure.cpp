#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;

class Node {
public:
    int count;
    unordered_set<string> keys;
    Node* prev;
    Node* next;
    Node(int c) : count(c), prev(nullptr), next(nullptr) {}
};

class AllOne {
private:
    unordered_map<string, Node*> key_to_node;
    Node* head;
    Node* tail;

    // Helper function to insert a new node between prev_node and next_node
    void insertNode(Node* node, Node* prev_node, Node* next_node) {
        node->prev = prev_node;
        node->next = next_node;
        prev_node->next = node;
        next_node->prev = node;
    }

    // Helper function to remove a node from the list
    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
    }

public:
    AllOne() {
        head = new Node(0);
        tail = new Node(0);
        head->next = tail;
        tail->prev = head;
    }

    ~AllOne() {
        // Clean up all nodes
        Node* curr = head->next;
        while (curr != tail) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
        delete head;
        delete tail;
    }

    void inc(string key) {
        if (key_to_node.find(key) == key_to_node.end()) {
            // Key doesn't exist, add it to count 1
            if (head->next->count != 1) {
                // Need to insert a new node with count 1
                Node* new_node = new Node(1);
                insertNode(new_node, head, head->next);
                key_to_node[key] = new_node;
                new_node->keys.insert(key);
            } else {
                // Head->next already has count 1
                head->next->keys.insert(key);
                key_to_node[key] = head->next;
            }
        } else {
            // Key exists, move it to the next higher count
            Node* current = key_to_node[key];
            int new_count = current->count + 1;
            if (current->next->count == new_count) {
                // Next node already has count new_count
                current->next->keys.insert(key);
                key_to_node[key] = current->next;
            } else {
                // Need to insert a new node with count new_count
                Node* new_node = new Node(new_count);
                insertNode(new_node, current, current->next);
                new_node->keys.insert(key);
                key_to_node[key] = new_node;
            }
            // Remove key from current node's keys set
            current->keys.erase(key);
            // If current node's keys set is empty, remove the node
            if (current->keys.empty()) {
                removeNode(current);
            }
        }
    }

    void dec(string key) {
        Node* current = key_to_node[key];
        int new_count = current->count - 1;
        if (new_count == 0) {
            // Remove the key from the data structure
            key_to_node.erase(key);
            current->keys.erase(key);
            // If current node's keys set is empty, remove the node
            if (current->keys.empty()) {
                removeNode(current);
            }
        } else {
            if (current->prev->count == new_count) {
                // Previous node already has count new_count
                current->prev->keys.insert(key);
                key_to_node[key] = current->prev;
            } else {
                // Need to insert a new node with count new_count
                Node* new_node = new Node(new_count);
                insertNode(new_node, current->prev, current);
                new_node->keys.insert(key);
                key_to_node[key] = new_node;
            }
            // Remove key from current node's keys set
            current->keys.erase(key);
            // If current node's keys set is empty, remove the node
            if (current->keys.empty()) {
                removeNode(current);
            }
        }
    }

    string getMaxKey() {
        if (head->next == tail) {
            // No keys present
            return "";
        }
        // Tail->prev is the node with the largest count
        Node* max_node = tail->prev;
        // Return any key from max_node's keys set
        if (!max_node->keys.empty()) {
            return *max_node->keys.begin();
        }
        return "";
    }

    string getMinKey() {
        if (head->next == tail) {
            // No keys present
            return "";
        }
        // Head->next is the node with the smallest count
        Node* min_node = head->next;
        // Return any key from min_node's keys set
        if (!min_node->keys.empty()) {
            return *min_node->keys.begin();
        }
        return "";
    }
};