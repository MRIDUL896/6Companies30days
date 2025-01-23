//146. LRU Cache
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Node {
public:
    int val;
    int key;
    Node* next;
    Node* prev;
    Node(int val, int key) {
        this->val = val;
        this->key = key;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class LRUCache {
    int capacity;
    int nodes;
    unordered_map<int, Node*> mp;
    Node* head;
    Node* tail;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->nodes = 0;
        this->head = new Node(-1, -1);
        this->tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }
        Node* node = mp[key];
        node->prev->next = node->next;
        node->next->prev = node->prev;

        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        node->prev = head;

        return node->val;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            node->val = value;

            node->prev->next = node->next;
            node->next->prev = node->prev;

            node->next = head->next;
            head->next->prev = node;
            head->next = node;
            node->prev = head;

            return;
        }

        Node* node = new Node(value, key);
        mp[key] = node;

        if (nodes < capacity) {
            node->next = head->next;
            head->next->prev = node;
            head->next = node;
            node->prev = head;

            nodes++;
        } else {
            Node* lru = tail->prev;

            mp.erase(lru->key);

            lru->prev->next = tail;
            tail->prev = lru->prev;

            delete lru;

            node->next = head->next;
            head->next->prev = node;
            head->next = node;
            node->prev = head;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
