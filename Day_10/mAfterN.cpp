//Delete N nodes after M nodes of a linked list
#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
    Node* linkdelete(Node* head, int n, int m) {
        Node* temp = head;
        Node* dummy = new Node(-1);
        Node* prev = dummy;
        prev->next = temp;
        while(temp){
            int a = m, b = n;
            while(a && temp){
                temp = temp->next;
                prev = prev->next;
                a--;
            }
            while(b && temp){
                temp = temp->next;
                b--;
            }
            prev->next = temp;
        }
        return dummy->next;
    }
};