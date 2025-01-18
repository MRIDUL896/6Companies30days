//2126. Destroying Asteroids
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int n = asteroids.size();
        double m = mass;
        sort(asteroids.begin(),asteroids.end());
        for(int i=0;i<n;i++){
            if(m < asteroids[i]) return false;
            m += asteroids[i];
        }
        return true;
    }
};