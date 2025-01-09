//Nuts and Bolts Problem
#include<bits/stdc++.h>
using namespace std;

void matchPairs(int n, char nuts[], char bolts[]) {
    unordered_map<char,int> mp;
    mp['!'] = 0;
    mp['#'] = 1;
    mp['$'] = 2;
    mp['%'] = 3;
    mp['&'] = 4;
    mp['*'] = 5;
    mp['?'] = 6;
    mp['@'] = 7;
    mp['^'] = 8;
    sort(nuts, nuts + n, [&](char a, char b) { return mp[a] < mp[b]; });
    sort(bolts, bolts + n, [&](char a, char b) { return mp[a] < mp[b]; });
}