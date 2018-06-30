//
// Created by ahad on 5/27/18.
//
#include<iostream>
#include<vector>
#include<algorithm>
#include <cstring>

using namespace std;
//int un[100][100][100];
int dp[1100][1100];
int distinct[1100][1100];
int longest_common_subsequence(string word1, string word2) {
    int n = (int)word1.length();
    int m= (int)word2.length();
    //int dp[n+1][m+1];

    for(int i=0; i<=n; i++) dp[m][i] = 0;
    for(int i=0; i<=m ; i++) dp[i][n] = 0;
   // int max = INT32_MIN;
    for(int r=n-1; r>=0; r--) {
        for(int c= m-1; c>=0; c--) {
            if(word1.at(r) == word2.at(c)) dp[r][c] = 1+ dp[r+1][c+1];
            else {
                dp[r][c] = dp[r+1][c] > dp[r][c+1] ? dp[r+1][c]:dp[r][c+1];
            }

        }
    }

    return dp[0][0];
}

int distinct_lcs(string word1, string word2) {
    int n = (int) word1.length();
    int m = (int) word2.length();
    //int distinct[n+1][m+1];
    for(int i=0; i<=n; i++) distinct[i][m] = 1;
    for(int i=0; i<=m ; i++) distinct[n][i] = 1;
    for(int r = n-1; r >= 0; r--) {
        for(int c = m-1; c >= 0; c--) {
            distinct[r][c] = 0;
            if(word1.at(r) ==  word2.at(c)){
                distinct[r][c] = distinct[r+1][c+1];
            }
            else {
                if(dp[r][c] == dp[r+1][c]) {
                    distinct[r][c] = (distinct[r][c] + distinct[r+1][c]) % 1000007;

                }
                if(dp[r][c] == dp[r][c+1]) {
                    distinct[r][c] = (distinct[r][c] + distinct[r][c+1]) % 1000007;

                }

                if(dp[r][c] == dp[r+1][c+1]) {
                    if(distinct[r][c] < distinct[r+1][c+1]) {
                        distinct[r][c] += 1000007;
                    }
                    distinct[r][c] = distinct[r][c] - distinct[r+1][c+1];
                }
            }
            //cout << distinct[r][c] << "";
        }
        //cout << endl;
    }

    return distinct[0][0];

}




int main() {

    int T;
    cin >> T;
    for(int cnt=0; cnt<T; cnt++) {
        memset(dp,0, sizeof(dp));
        memset(distinct,0, sizeof(distinct));
        string str1;
        string str2;
        cin >> str1;
        cin >> str2;
        longest_common_subsequence(str1,str2);
        cout << "Case " << cnt+1 <<": " <<  distinct_lcs(str1,str2) << endl;
    }


}

