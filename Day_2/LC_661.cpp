//661. Image Smoother
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int cnt = 0, sum = 0;
                for(int x=-1;x<=1;x++){
                    for(int y=-1;y<=1;y++){
                        if(i+x>=0 && i+x<m && j+y>=0 && j+y<n){
                            cnt++;
                            sum += (255 & img[i+x][j+y]);
                        }
                    }
                }
                img[i][j] |= ((sum/cnt) << 8);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                img[i][j] = (img[i][j]>>8);
            }
        }
        return img;
    }
};