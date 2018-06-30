//
// Created by ahad on 6/4/18.
//

#include<iostream>
#include<vector>
#include<algorithm>
#include <cstring>

using namespace std;
struct data {
    int len;
    string lcs;
};
//data dp[110][110];
data longest_common_subsequence(string word1, string word2) {
    int n = (int)word1.length();
    int m= (int)word2.length();
    data dp[110][110];

    for(int i=0; i<=n; i++)
    {
        dp[i][m].len = 0;
        //dp[n][i].lcs = " ";
    }
    for(int j=0; j<=m ; j++) {
        dp[n][j].len = 0;
        //dp[j][m].lcs = " ";
    }
    //int max = INT32_MIN;
    for(int r=n-1; r>=0; r--) {
        for(int c= m-1; c>=0; c--) {
            if(word1.at(r) == word2.at(c)) {
                dp[r][c].len = 1+dp[r+1][c+1].len;
                dp[r][c].lcs = dp[r+1][c+1].lcs + word1[r];
            }
            else {
                if(dp[r+1][c].len == dp[r][c+1].len) {
                    dp[r][c].len = dp[r+1][c].len;
                    if(dp[r+1][c].lcs < dp[r][c+1].lcs) dp[r][c].lcs = dp[r+1][c].lcs;
                    else dp[r][c].lcs = dp[r][c+1].lcs;
                }
                else if(dp[r+1][c].len > dp[r][c+1].len ) {
                    dp[r][c].len = dp[r+1][c].len;
                    dp[r][c].lcs = dp[r+1][c].lcs;
                }
                else {
                    dp[r][c].len = dp[r][c+1].len;
                    dp[r][c].lcs = dp[r][c+1].lcs;

                }
                //dp[r][c].len = dp[r+1][c].len > dp[r][c+1].len ? dp[r+1][c].len:dp[r][c+1].len;
            }

        }
    }

    return dp[0][0];
}


int main() {
    int count=1;
    int T;
    cin >> T;
    for(int cnt=0; cnt<T; cnt++) {
        //memset(dp,0, sizeof(dp));
        string str1, str2;
        cin >> str1;
        cin >> str2;
        reverse(str1.begin(),str1.end());
        reverse(str2.begin(),str2.end());
        if(longest_common_subsequence(str1,str2).len >0) {
            //cout << longest_common_subsequence(str1,str2).len;
            string result = longest_common_subsequence(str1,str2).lcs;
            //reverse(result.begin(),result.end());
            cout << "Case " << count <<": " << result<< endl;
        }

        else
            cout << "Case " << count <<": " << ":(" << endl;

        count++;
    }

}

