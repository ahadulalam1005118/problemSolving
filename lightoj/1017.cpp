/*
//
// Created by ahad on 6/7/18.
//
#include<iostream>
#include<vector>
#include<algorithm>
#include <cstring>

using namespace std;

//using namespace std;
int dp[105][105];
bool isEqual(std::pair<int, int> element1, std::pair<int,int> element2)
{
    return element1.first <  element2.first;
}
int find_index(vector<pair<int,int> > lists, int y_coordinate) {
    vector<pair<int,int> >::iterator it;
    if(lists.empty()) return -1;
    for(it = lists.begin(); it < lists.end(); it++) {
        //if(lists.empty()) return -1;
        if(y_coordinate == it->first)
            return distance(lists.begin(),it);
    }
    return -1;
}
int calculate_maximum(vector<pair<int,int> > y_count,int pos, int taken, int k, int width) {
    if(taken >= k) return 0;
    if(dp[pos][taken] != -1) return dp[pos][taken];
    if(pos >= y_count.size()-1) return 0;
    //if(y_count[pos].first > y_count[y_count.size()-1].first) return 0;
    int low = y_count[pos].first;
    int high = y_count[pos].first + width;
    //int temp = pos;
    if(high >= y_count[y_count.size()-1].first) high = y_count[y_count.size()-1].first
                ;
    //int high = pos+width;
    int total =0;
    //int = find_index(y_count,pos);
    //for(int i=pos; y_count[])

    vector<pair<int,int> >::iterator it = y_count.begin()+pos;
    //vector<pair<int,int> >::iterator cur = it+1;

    while(it->first < high){

        total += it->second;
        it++;
    }
    int nextpos = distance(y_count.begin(),it);
    //int high = distance(cur,y_count.begin());
    dp[nextpos][taken+1] = calculate_maximum(y_count,nextpos,taken+1,k,width)+total;
    dp[pos+1][taken] = calculate_maximum(y_count,pos+1,taken,k,width);
    int ret = max(dp[nextpos][taken+1] ,dp[pos+1][taken]);
    return dp[pos][taken] = ret;
}

int main() {
    int T;
    cin >> T;
    int count =1;
    for(int i=0; i<T; i++) {
        memset(dp,-1,sizeof(dp));
        vector<pair<int,int> > y_count;
        y_count.clear();
        int number;
        cin >> number;
        int K,W;
        //cin >> W;
        cin >> W;
        cin >> K;
        while(number) {
            int x,y;
            cin >> x;
            cin >> y;
            //vector<pair<int,int>>::iterator it ;
            //cout << find(y_count.begin(),y_count.end(),isEqual) < endl;
            if(find_index(y_count,y) == -1) {
                y_count.push_back(make_pair(y,1));
            }
            else {
                //cout << count <<"lala"<< y_count.size() << endl;
                //vector<pair<int,int>>::iterator it = find(y_count.begin(),y_count.end(),isEqual);
                int pos = find_index(y_count,y);
                //cout << pos;
               // cout << y_count[pos].first;
                y_count[pos].second++;
            }
            number--;

        }
        sort(y_count.begin(),y_count.end(),isEqual);

        cout << "Case " << count <<": " << calculate_maximum(y_count,0,0,K,W) << endl;
        count++;


    }
}
*/

#include<iostream>
using namespace std;
int foo(int x) {
    if (x<100) return 1000;
    else return 0;
}
int main() {
    char *name = new char[10];
    name[10] = 'x';
    int var;
    foo(var);
}