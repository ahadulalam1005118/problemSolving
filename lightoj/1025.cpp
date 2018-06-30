//
// Created by ahad on 5/31/18.
//
#include<iostream>
#include<algorithm>
#include <vector>
#include <cstring>

using namespace std;
unsigned long long int memo[1600][1600];
unsigned long long int count_pallindrome(string str, int start, int end) {
    if(start > end) return 0;
    if(start == end) return 1;
    if(memo[start][end]) return memo[start][end];
    if(str[start] == str[end]) return memo[start][end] =
                                              1+count_pallindrome(str,start,end-1) + count_pallindrome(str,start+1,end);
    else return memo[start][end] = count_pallindrome(str,start,end-1) +
                count_pallindrome(str,start+1,end) - count_pallindrome(str,start+1,end-1);


}

int main() {
    int T;
    cin >> T;
    int count=1;
    for(int i=0; i<T; i++) {
        memset(memo,0, sizeof(memo));
        string str;
        cin >> str;
        cout << "Case " << count <<": " << count_pallindrome(str,0,(int)(str.length()-1)) << endl;
        count++;
    }
}
