//
// Created by ahad on 6/22/18.
//
#include<iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
//int dp[1003][15003];
/*
int count_ways(int number, int faces, int sum) {
    if(sum == 0 && number == 0) return 1;
    if(sum <= 0) return 0;
    if(number <=0) return 0;
    if(dp[number][sum] != -1) return dp[number][sum];
    int count =0;
    for(int i=1;i<=faces; i++) {
        count += count_ways(number-1,faces,sum-i) % 100000007;
    }
    return dp[number][sum] = count % 100000007;

}
*/

int count_ways_dp(int number, int faces, int sum) {
    int dp[number+1][sum+1];
    memset(dp,0, sizeof(dp));
    if (number*faces <= sum)
        return (number*faces == sum);
    if (number >= sum)
        return (number == sum);
    for(int i=1;i<=faces && i<=sum; i++) {
        dp[1][i] = 1;
    }

    for(int i=2; i<=number;i++) {
        for(int j=1; j<=sum; j++) {
            for(int k=1; k<=faces && k<j ; k++) {
                dp[i][j] = (dp[i][j] + dp[i-1][j-k]) % 100000007;

            }
        }
    }
    return dp[number][sum];
}

int main() {
    int T;
    cin >> T;
    for(int i=0; i<T; i++) {
        //memset(dp,0, sizeof(dp));
        int number;
        int faces;
        int sum;
        cin >> number;
        cin >> faces;
        cin >> sum;
        cout << "Case " << i+1 <<": " << count_ways_dp(number, faces, sum) << endl;

    }

}
