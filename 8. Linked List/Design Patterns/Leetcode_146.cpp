// 146. LRU Cache
// Problem:
// Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.
// Implement the LRUCache class with:
// - LRUCache(int capacity)
// - int get(int key)
// - void put(int key, int value)
// The functions should run in O(1) average time.
//
// Link: `https://leetcode.com/problems/lru-cache/`
//
// Constraints (LeetCode):
// - 1 <= capacity <= 3000
// - 0 <= key, value <= 10^4
// - At most 2 * 10^5 calls will be made to get and put.
//
// Expected Complexity (hash map + doubly linked list):
// - get: O(1) average
// - put: O(1) average
// - Space: O(capacity)

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

// Solution Complexity:
// - get: O(1) average
// - put: O(1) average
// - Space: O(capacity)
