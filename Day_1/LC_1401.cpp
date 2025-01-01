//1401. Circle and Rectangle Overlapping
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int xa = min(x2,max(xCenter,x1));
        int ya = min(y2,max(yCenter,y1));
        double dist = sqrt(pow(xa-xCenter,2) + pow(ya-yCenter,2));
        return dist <= radius;
    }
};