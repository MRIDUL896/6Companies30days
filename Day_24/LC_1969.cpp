//1969. Minimum Non-Zero Product of the Array Elements
#include<iostream>
using namespace std;

class Solution {
public:
    long long modulo = 1000000007;
    long long power(long long num, long long n){
        if(n==0) return (long long)1;
        if(n==1) return num%modulo;
        long long p = power(num,n/2);
        p=p%modulo;
        if(n&2==0) return (p*p)%modulo;
        else return (((p*p)%modulo)*(num%modulo))%modulo;
    }

    int minNonZeroProduct(int p) {
        long long n = pow(2, p);
        n--;
        long long extra = n;
        long long num = n-1;
        n=(long long)(n/2); 

        long long product = (long long)1;
        product = power(num, n);
        product = ((product)*(extra%modulo))%modulo;
        return (int)product;
    }
};