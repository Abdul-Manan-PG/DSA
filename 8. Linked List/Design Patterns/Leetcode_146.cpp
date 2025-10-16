// 146. LRU cache

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;


class LRUCache {
private:
    struct Node {
        int key, value;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    int capacity;
    unordered_map<int, Node*> cache;
    Node* head; // most recently used
    Node* tail; // least recently used

    // Move node to the front (most recently used)
    void moveToFront(Node* node) {
        removeNode(node);
        addToFront(node);
    }

    // Add node to front (right after head)
    void addToFront(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    // Remove a node from the list
    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

public:
    LRUCache(int capacity) : capacity(capacity) {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (cache.find(key) == cache.end())
            return -1;
        Node* node = cache[key];
        moveToFront(node);
        return node->value;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            // Update value and move to front
            Node* node = cache[key];
            node->value = value;
            moveToFront(node);
        } else {
            if (cache.size() == capacity) {
                // Remove least recently used (tail->prev)
                Node* lru = tail->prev;
                cache.erase(lru->key);
                removeNode(lru);
                delete lru;
            }
            // Insert new node at front
            Node* newNode = new Node(key, value);
            addToFront(newNode);
            cache[key] = newNode;
        }
    }
};
