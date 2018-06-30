//
// Created by ahad on 5/30/18.
//
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include <cstring>

using namespace std;
long long int dp[65540];
int inputs[17][17];

unsigned long long int count_set_bits(unsigned long long int n) {
    unsigned long long int count =0;
    while(n) {
        count += n &1;
        n = n >> 1;
    }
    return count;
}

long long int assign(unsigned long long int N, int cost[17][17]) {

    for(int i=0; i< pow(2,N); i++) {
        dp[i] = -999999;
    }
    //int maxm = INT32_MIN;
    dp[0] = 0;
    for(unsigned long long int mask = 0; mask < pow(2,N); mask++) {
        unsigned long long int x = count_set_bits(mask);
        for(int j=0; j<N; j++) {
            if(!(mask & 1<<j)) {
                dp[mask|1<<j] = max(dp[mask|1<<j],dp[mask]+cost[x][j]);
            }
        }
    }
    return dp[(int)pow(2,N)-1];
}

/*unsigned long long int dp[16][1<<16];
unsigned long long int inputs[16][16];

unsigned long long int max_priority_index(int i, int mux, int n) {
    int allmux;
    for(int cnt=0; cnt<n; cnt++) {
        allmux = allmux | 1<<i ;
    }
    if(mux == allmux) return 0;
    if(dp[i][mux] != -1) return dp[i][mux];
    unsigned long long int res =0;
    for(int j=0; j<n ;j++) {
        if(mux & 1 << j) continue;
        else {
            dp[i+1][mux] = max_priority_index(i+1,mux| (1<<j),n)+inputs[i][j];
            unsigned long long int r = dp[i+1][mux];
            res = max(res, r);
        }
            //unsigned long long int  r = max_priority_index(i+1,mux| (1<<j),n)+inputs[i][j];

    }
    return dp[i][mux]=res;

}*/


int main() {
    int T;
    cin >> T;
    int count = 1;
    for(int i=0; i<T; i++) {
        memset(dp,-1, sizeof(dp));
        int N;
        cin >> N;
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                cin >> inputs[i][j];
            }
        }
        cout << "Case " << count <<": " << assign(N, inputs) << endl;
        count++;
        //memset(dp,-1, sizeof(dp));
        /*cout << max_priority_index(N-1,0,N) << endl;*/
        /*for(int k=0; k<pow(2,N); k++) {
            cout << dp[k] << endl;
        }*/

    }
}
