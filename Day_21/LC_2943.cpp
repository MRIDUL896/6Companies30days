//2943. Maximize Area of Square Hole in Grid
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        int maxRows = 1, maxCols = 1;
        int consecutive = 1;
        for(int i=1;i<hBars.size();i++){
            if(hBars[i]-1 == hBars[i-1]) consecutive++;
            else consecutive = 1;
            maxRows = max(maxRows,consecutive);
        }
        consecutive = 1;
        for(int i=1;i<vBars.size();i++){
            if(vBars[i]-1 == vBars[i-1]) consecutive++;
            else consecutive = 1;
            maxCols = max(maxCols,consecutive);
        }
        int side = min(maxRows+1,maxCols+1);
        return side*side;
    }
};