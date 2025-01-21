//703. Kth Largest Element in a Stream
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

class KthLargest {
    priority_queue<int,vector<int>,greater<int>> pq;
public:
    KthLargest(int k, vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(pq.size() < k) pq.push(nums[i]);
            else{
                int top = pq.top();
                pq.pop();
                pq.push(max(top,nums[i]));
            }
        }
        while(pq.size()<k) pq.push(INT_MIN);
    }
    
    int add(int val) {
        int top = pq.top();
        pq.pop();
        pq.push(max(top,val));
        return pq.top();
    }
};