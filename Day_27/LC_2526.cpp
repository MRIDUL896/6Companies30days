//2526. Find Consecutive Integers from a Data Stream
#include<iostream>
#include<vector>
using namespace std;

class DataStream {
    int value,k;
    int prevVal,prevStreak;
public:
    DataStream(int value, int k) {
        this->value = value;
        this->k = k;
        this->prevVal = 0;
        this->prevStreak = 0;
    }
    
    bool consec(int num) {
        if(num == value && prevVal == value) prevStreak++;
        else if(num == value) prevStreak = 1;
        else prevStreak = 0;
        
        prevVal = num;

        return prevStreak >= k;
    }
};