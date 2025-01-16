//825. Friends Of Appropriate Ages
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        sort(ages.begin(), ages.end());
        int n = ages.size();
        int totalRequests = 0;
        for(int i = 0; i < n; ++i){
            if (ages[i] <= 14) continue;
            int lower = lowerBound(ages, 0.5 * ages[i] + 7);
            int upper = upperBound(ages, ages[i]);
            totalRequests += (upper - lower);
            totalRequests--;
        }
        return totalRequests;
    }

private:
    int lowerBound(vector<int>& ages, double limit) {
        int low = 0, high = ages.size();
        while(low < high) {
            int mid = low + (high - low) / 2;
            if (ages[mid] > limit) high = mid;
            else low = mid + 1;
        }
        return low;
    }

    int upperBound(vector<int>& ages, int limit) {
        int low = 0, high = ages.size();
        while(low < high){
            int mid = low + (high - low) / 2;
            if(ages[mid] <= limit) low = mid + 1;
            else high = mid;
        }
        return low;
    }
};