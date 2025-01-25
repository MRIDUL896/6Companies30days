//2513. Minimize the Maximum of Two Arrays
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        int low=1,high=INT_MAX;
        int result=INT_MAX;
        long long int lcmVal=((long long)divisor1*divisor2)/__gcd(divisor1,divisor2);
        while(low <= high){
            int mid = low + (high-low)/2;
            int n1 = mid - mid/divisor1;
            int n2 = mid - mid/divisor2;
            int common = mid - (long long)mid/lcmVal;
            if(n1>=uniqueCnt1 && n2>=uniqueCnt2 && common >= uniqueCnt1+uniqueCnt2){
                result = mid;
                high = mid-1;
            }else low = mid+1;
        }
        return result;
    }
};