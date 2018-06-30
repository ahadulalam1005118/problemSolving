//
// Created by ahad on 5/29/18.
//

#include<iostream>
#include<algorithm>
#include<vector>
#include <cstring>

using namespace std;
unsigned long long int dp[35];
unsigned long long ncr[910][910];
unsigned long long int fact(int n) {
    if(n==0) return dp[n] = 1;
    if(dp[n]) return dp[n];
    else return dp[n] = n*fact(n-1);

}

unsigned long long int nCr(int n, int r) {
    if (r == 0) return ncr[n][r] = 1;
    if (n == r) return ncr[n][r] = 1;
    else return ncr[n][r] = nCr(n-1,r-1) + nCr(n-1,r);
}

unsigned long long int cnr_non_attacking(int dimension, int rook) {
    if(rook > dimension) return 0;
    else return nCr(dimension,rook) * nCr(dimension, rook) * fact(rook);

}

int main() {
    int T;
    //memset(dp,0, sizeof(dp));
    cin >> T;
    int count = 1;
    for(int i=0; i<T; i++) {
       // memset(dp,0, sizeof(dp));
        memset(dp,0, sizeof(dp));
        memset(ncr,0, sizeof(ncr));
        int number;
        int rookie;
        cin >> number;
        cin >> rookie;
        //cout << fact(number) << endl;
        cout << "Case " << count <<": " <<  cnr_non_attacking(number,rookie) << endl;
        count++;
    }
}