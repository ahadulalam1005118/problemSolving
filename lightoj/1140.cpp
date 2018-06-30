//
// Created by ahad on 6/5/18.
//
#include<iostream>
#include<vector>
#include<algorithm>
#include <cstring>

using namespace std;
long long int dp[1600][2][1600];
int get_digits(long long int a, vector<long long int>&digits){
    while(a) {
        digits.push_back(a%10);
        a /= 10;
    }
    return digits.size();
}

long long int zero_count(int pos,int tight,int sum, vector<long long int>&digits, int length) {
    if(pos == -1 ) return sum;
    if(dp[pos][tight][sum] != -1 && !tight) return dp[pos][tight][sum];
    long long int ret=0;
    int limit = (tight) ? digits[pos]:9;
    for(int i=0;i<=limit; i++) {
        int newTight = (digits[pos] == i)?tight:0;
        if(i == 0) ret += zero_count(pos-1,newTight,sum+1,digits,length);
        else ret += zero_count(pos-1,newTight,sum,digits,length);
    }

    if(!tight) dp[pos][tight][sum] = ret;

    return ret;

}
int main() {
    int T;
    cin >> T;
    int count = 1;
    for(int i=0; i<T; i++) {
        long long int a;
        long long int b;
        int number;
        cin >> a;
        cin >> b;
        //cin >> number;
        memset(dp, -1, sizeof(dp));
        vector<long long int> digitA;
        vector<long long int> digitB;
        //digitA.clear();
        int l1 = get_digits(a-1,digitA);
        int l2 = get_digits(b,digitB);
        //reverse(digitA.begin(),digitA.end());
        //reverse(digitB.begin(),digitB.end());
        long long int uptoB = zero_count(digitB.size()-1,1,0,digitB,l2);
        long long int uptoA = zero_count(digitA.size()-1,1,0,digitA,l1);
       // cout << uptoB << endl;
       // cout << uptoA << endl;
        cout << "Case " << count <<": " << uptoB - uptoA  <<endl;
        count++;

    }
    //cout << power(10,5) << endl;

}
