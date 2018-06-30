//
// Created by ahad on 6/20/18.
//
#include<iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

/*bool check(int C[],int coins) {
    int flag = 0;
    for(int i=0; i<coins; i++) {
        if(C[i] < 0) flag =1;
    }
    if(!flag) return true;
    else return false;

}*/

/*unsigned long long int count_ways(int A[], int C[],int coins, int sum) {
    if(sum == 0 && C[coins] >= -1) return 1;
    if(C[coins] < -1) return 0;
    //if(!check(C,total)) return 0;
    if(sum < 0) return 0;
    if(coins < 0 && sum > 0 ) return 0;
    C[coins]--;
    unsigned long long int ret1 = count_ways(A,C,coins, sum - A[coins]);
    //C[coins]--;
    unsigned long long int ret2 = count_ways(A,C,coins-1,sum);
    return ret1+ret2;

}*/

//int count_ways_dp(int A[], int K, int number) {
//    int ways[number+1][K+1];
//    memset(ways,0, sizeof(ways));
//    ways[0][0]=1;
//    for( int i = 1 ; i <= number ; i++){
//            for( int j = 0 ; j <= K ; j++ ){
//                int coin_rem = min(K, j/A[i]);
//                for(int k = 0; k <= coin_rem; k++) {
//                    ways[i][j] = (ways[i][j] + ways[i-1][j-A[i]*k]) % 100000007;
//                }
//            }
//
//    }
//    return ways[number][K];
//}
int count_ways(int A[], int K, int number) {
    int ways[K+1];
    memset(ways,0, sizeof(ways));
    ways[0]=1;
    for( int i = 1 ; i <= number ; i++){
        for( int j = A[i] ; j <= K ; j++ ){
            ways[j] = (ways[j] + ways[j-A[i]]) % 100000007;

        }

    }
    return ways[K];
}
int main() {
    int arr[150];
    int coin[60];
    int T;
    cin >> T;
    for(int i=0; i<T; i++) {
        int number;
        cin >> number;
        int K;
        cin >> K;
        for(int j=1; j<= number; j++) {
            cin >> arr[j];
        }
        cout << "Case " << i+1 <<": " <<  count_ways(arr,K,number) <<endl;
    }
    
}
