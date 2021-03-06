//
// Created by ahad on 6/4/18.
//

//
// Created by ahad on 6/1/18.
//

#include<iostream>
#include<vector>
#include<algorithm>
#include <cstring>

using namespace std;
//vector<long long int> digitA;
long long int dp[33][10][100][100];
void get_digits(long long x, vector<long long int>&digits) {
    while(x) {
        digits.push_back(x%10);
        x=x/10;
    }

}
long long int digits_sum(int idx,int tight,int digit,int digitsum,int dividend,vector<long long int>&digits) {
    if(idx == -1) {
        if(digit%dividend == 0 && digitsum%dividend == 0) return 1;
        else return 0;
    }
    if(dp[idx][tight][digit][digitsum] != -1 && !tight) return dp[idx][tight][digit][digitsum];
    long long int ret=0;
    //for(int j=0;j<digits.size(); j++) cout <<digits[j];
    int k = (tight)? (int)digits[idx] : 9;
    for(int i=0; i<=k; i++) {
        int newTight = (digits[idx] == i) ? tight:0;
        ret += digits_sum(idx-1,newTight,(digit*10 +i)%dividend,(digitsum+i)%dividend,dividend,digits);

    }

    if(!tight) {
        dp[idx][tight][digit][digitsum] = ret;
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
        long long int b;
        int number;
        cin >> a;
        cin >> b;
        cin >> number;
        memset(dp, -1, sizeof(dp));
        vector<long long int> digitA;
        vector<long long int> digitB;
        //digitA.clear();
        get_digits(a-1,digitA);
        get_digits(b,digitB);
        int uptoB = digits_sum((int)digitB.size()-1,1,0,0,number,digitB) - 1;
        int uptoA = digits_sum((int)digitA.size()-1,1,0,0,number,digitA) - 1;
        cout << "Case " << count <<": " << uptoB - uptoA <<endl;
        count++;

    }


}

