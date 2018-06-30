//
// Created by ahad on 6/19/18.
//
#include<iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
/*int min(int a, int b) {
    if(a<b) return a;
    else return b;
}*/
int input[25][3];
int dp[1000][1000];
int minCost(int prev_color, int house_number, int house_count) {
    if(house_number >= house_count) return 0;
    int best_cost = 999999999;
    if(dp[house_number][prev_color] != -1) return dp[house_number][prev_color];
    if(prev_color != 0) {
        best_cost = min(best_cost,minCost(0,house_number+1,house_count) + input[house_number][0]);
    }
    if(prev_color != 1) {
        best_cost = min(best_cost,minCost(1,house_number+1,house_count)+ input[house_number][1]) ;
    }
    if(prev_color != 2) {
        best_cost = min(best_cost,minCost(2,house_number+1,house_count)+ input[house_number][2]) ;

    }
    return dp[house_number][prev_color] = best_cost;
}

int maxCost(int current, bool flag){
    if(flag && current == n-1) return 0;
    if(!flag && current == n) return 0;
    else return max(maxCost(current+1,flag), maxCost(current+2,flag)+input[current]);
}
int main() {
    int T;
    cin >> T;
    for(int i=0; i<T; i++) {
        memset(input,-1,sizeof(input));
        memset(dp,-1, sizeof(dp));
        int number;
        cin >> number;
        for(int k=0; k<number; k++) {
            for(int j=0; j<3; j++) {
                cin >> input[k][j];
            }
        }
        /*for(int k=0; k<number; k++) {
            for(int j=0; j<3; j++) {
                cout << input[k][j] << " ";
            }
            cout << endl;
        }*/
        cout << "Case " << i+1 <<": " << min(min(minCost(0,0,number),minCost(1,0,number)),minCost(2,0,number)) << endl;
        //cout << "Case " << count;
        //cout << ": " << minCost(-1,0,number) << endl;
    }



}

