//497. Random Point in Non-overlapping Rectangles
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> v; 
    vector<vector<int>> rects;
    int area(vector<int>& r) {
        return (r[2] - r[0] + 1) * (r[3] - r[1] + 1);
    }
    Solution(vector<vector<int>> rect) {
        rects = rect;
        int totalArea = 0;
        for (auto& r : rects) {
            totalArea += area(r);
            v.push_back(totalArea);
        }
    }
    vector<int> pick() {
        int n = v.size(); 
        int totalArea = v[n-1];
        int target = rand() % totalArea;
        int idx = lower_bound(v.begin(), v.end(), target + 1) - v.begin();
        vector<int> r = rects[idx];
        int x = rand() % (r[2] - r[0] + 1) + r[0];
        int y = rand() % (r[3] - r[1] + 1) + r[1];
        return { x, y };
    }
};
