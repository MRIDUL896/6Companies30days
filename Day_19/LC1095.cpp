//1095. Find in Mountain Array
#include<iostream>
#include<vector>
using namespace std;


class MountainArray {
   public:
    int get(int index);
    int length();
};


class Solution {
public:
    int findPeak(MountainArray &arr, int n){
        int s = 0, e = n-1;
        while(s<e){
            int m = s + (e-s)/2;
            int curr = arr.get(m);
            int next = arr.get(m+1);
            if(curr < next){
                s = m + 1;
            }else e = m;
        }
        return e;
    }
    int BS1(int s,int e,int target,MountainArray &arr){
        while(s <= e){
            int m = s + (e-s)/2;
            int ele = arr.get(m);
            if(ele == target) return m;
            else if(target > ele) s = m+1;
            else e = m-1;
        }
        return -1;
    }
    int BS2(int s,int e,int target,MountainArray &arr){
        while(s <= e){
            int m = s + (e-s)/2;
            int ele = arr.get(m);
            if(ele == target) return m;
            else if(target < ele) s = m+1;
            else e = m-1;
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int peak = findPeak(mountainArr,n);
        int i1 = BS1(0,peak,target,mountainArr);
        if(i1 != -1) return i1;
        int i2 = BS2(peak,n-1,target,mountainArr);
        return i2;
    }
};