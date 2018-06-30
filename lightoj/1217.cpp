//
// Created by ahad on 6/21/18.
//

#include<iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
int dp[1000][2];
int input[1000];
int maxCost(int current,int n, int flag){
    if(flag && current >= n-1) return 0;
    if(!flag && current >= n) return 0;
    if(dp[current][flag] != -1) return dp[current][flag];
    else return dp[current][flag] = max(maxCost(current+1,n,flag), maxCost(current+2,n,flag)+input[current]);
}
int main() {
    int T;
    cin >> T;
    for(int i=0; i<T; i++) {
        memset(input,0,sizeof(input));
        memset(dp,-1, sizeof(dp));
        int number;
        cin >> number;
        for(int k=0; k<number; k++) {
            cin >> input[k];
        }
        cout << "Case " << i+1 <<": " << max(maxCost(0,number,1),maxCost(1,number,0)) << endl;

    }



}