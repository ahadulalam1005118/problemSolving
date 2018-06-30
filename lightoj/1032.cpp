//
// Created by ahad on 6/1/18.
//

#include<iostream>
#include<vector>
#include<algorithm>
#include <cstring>

using namespace std;
//vector<long long int> digitA;
long long int dp[33][2][33];
void get_digits(long long x, vector<long long int>&digits) {
    while(x) {
        digits.push_back(x%2);
        x=x/2;
    }

}
long long int digits_sum(int idx, int prev, int tight, int sum,vector<long long int>&digits) {
    if(idx == -1) return sum;
    if(dp[idx][prev][sum] != -1 && !tight) return dp[idx][prev][sum];
    long long int ret=0;
    //for(int j=0;j<digits.size(); j++) cout <<digits[j];
    int k = (tight)? (int)digits[idx] : 1;
    for(int i=0; i<=k; i++) {
        int newTight = (digits[idx] == i) ? tight:0;
        if(prev & i) ret += digits_sum(idx-1,i,newTight,sum+1,digits);
        else ret += digits_sum(idx-1,i,newTight,sum, digits);
    }

    if(!tight) {
        dp[idx][prev][sum] = ret;
    }
    //cout << endl;

    return ret;

}

int main(){
    int T;
    cin >> T;
    int count = 1;
    for(int i=0; i<T; i++) {
        long long int a;
        cin >> a;
        memset(dp, -1, sizeof(dp));
        vector<long long int> digitA;
        //digitA.clear();
        get_digits(a,digitA);
        cout << "Case " << count <<": " << digits_sum((int)digitA.size()-1,0,1,0,digitA)<<endl;
        count++;

    }


}

