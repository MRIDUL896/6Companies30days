//519. Random Flip Matrix
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int n,m;
    int i,j;
    Solution(int m, int n) {
        this->m = m;
        this->n = n;
        i = 0;
        j = 0;
    }
    
    vector<int> flip() {
        int row = i, col = j;
        if(j+1<n) j++;
        else if(i+1<m) i++,j=0;
        else i=0,j=0;
        return {row,col};
    }
    
    void reset() {
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */