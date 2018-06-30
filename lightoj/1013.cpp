//
// Created by ahad on 5/30/18.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int un[1600][1600];
int dp[1600][1600];
int longest_common_subsequence(string word1, string word2) {
    int n = (int)word1.length();
    int m= (int)word2.length();
    //int dp[n+1][m+1];
    //int un[n+1][m+1];

    for(int i=0; i<=n; i++) dp[n][i] = 0;
    for(int i=0; i<=m ; i++) dp[i][m] = 0;
    int max = INT32_MIN;
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

int length_of_shortest_string(string word1, string word2) {
    cout << longest_common_subsequence(word1,word2) << endl;
    return (int)word1.length() + (int)word2.length() - longest_common_subsequence(word1, word2);
}

int count_number_of_subsequences(string word1, string word2,int cur_word1, int cur_word2, int num,int length) {

    if (cur_word1 == word1.size()) {
        for(int i=cur_word2; i<word2.length(); i++) {
            num++;
        }
        if(num == length) return un[cur_word1][cur_word2] = 1;
        else un[cur_word1][cur_word2] = 0;
    }

    if (cur_word2 == word2.size()) {
        for(int i=cur_word1; i<word1.length(); i++) {
            num++;
        }
        if(num == length) return un[cur_word1][cur_word2] = 1;
        else un[cur_word1][cur_word2] = 0;
    }
    if(word1.at(cur_word1) == word1.at(cur_word2)) return un[cur_word1][cur_word2] =
                                                                  count_number_of_subsequences(word1, word2, cur_word1+1,cur_word2+1, num,length);
    else return un[cur_word1][cur_word2] = count_number_of_subsequences(word1,word2,cur_word1+1,cur_word2,num,length) +
                count_number_of_subsequences(word1,word2,cur_word1,cur_word2+1,num,length);

}

int main() {
    string str1, str2;
    cin >> str2;
    cin >> str2;
    int length = length_of_shortest_string(str1,str2);
    cout << length << endl;
    cout << count_number_of_subsequences(str1, str2,0,0,0,length) << endl;
}