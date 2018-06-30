//
// Created by ahad on 6/20/18.
//
/*Factoriadic Number*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <stack>

using namespace std;
int fact(int n) {
    if(n == 0) return 1;
    else return n*fact(n-1);
}

stack<int> factoradic_representation(int number){
    int cnt = 1;
    stack<int> stk;
    //int quitiont = number/cnt;
    //int rem = quitiont%cnt;
    while(number/cnt != 0) {
        //number = number/cnt;
        stk.push(number%cnt);
        number /= cnt;
        //quitiont = quitiont/cnt;
        //stk.push(rem);
        cnt++;
    }
    return stk;

}
int main() {
    int T;
    cin >> T;
    for(int i=0; i<T; i++) {
        int a[26];
        int prod = 1;
        int total = 0;
        string str;
        int nth;
        cin >> str;
        cin >> nth;
        memset(a,0, sizeof(a));

        for(int i=0; i< str.length(); i++) {
            int temp = (char)str[i];
            //cout << temp;
            a[temp-97]++;
            total++;
        }
        for(int i=0; i<26; i++) {
            //cout << a[i];
            prod *= fact(a[i]);
        }
        int highest = fact(total)/prod;
        //cout << highest;
        if(nth > highest) cout << "Impossible";
        else {
            stack<int> stack1 = factoradic_representation(nth);
            while(!stack1.empty()) {
                cout << stack1.top() << endl;
                stack1.pop();
            }

        }



    }
}

