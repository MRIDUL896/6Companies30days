//23. Merge k Sorted Lists
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy=new ListNode(INT_MIN);
        ListNode* temp=dummy;
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> pq;
        for(int i=0;i<lists.size();i++){
            if(lists[i]){
            pq.push(make_pair(lists[i]->val,lists[i]));}
        }
        while(!pq.empty()){
            pair<int,ListNode*> curr=pq.top();
            pq.pop();
            temp->next=curr.second;
            temp=temp->next;
            if(curr.second->next){
                pq.push(make_pair(curr.second->next->val,curr.second->next));
            }
        }
        return dummy->next;
    }
};