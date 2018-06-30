//
// Created by ahad on 5/28/18.
//
//
// Created by ahad on 5/28/18.
//
#include<iostream>
#include<vector>
#include<algorithm>
#include <cstring>

using namespace std;
typedef  pair<int, int> iPair;
bool visited[1000];
bool my_function(pair<int,pair<int,int> > a, pair<int,pair<int,int> >b) {
    return (a.first>b.first);

}
struct DisjointSets
{
    int *parent, *rnk;
    int n;
    DisjointSets(int n)
    {
        this->n = n;
        parent = new int[n+1];
        rnk = new int[n+1];
        for (int i = 0; i <= n; i++)
        {
            rnk[i] = 0;
            parent[i] = i;
        }
    }
    int find(int u)
    {
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }
    void merge(int x, int y)
    {
        x = find(x), y = find(y);
        if (rnk[x] > rnk[y])
            parent[y] = x;
        else
            parent[x] = y;

        if (rnk[x] == rnk[y])
            rnk[y]++;
    }
};
int pair_exists(vector<pair<int,pair<int,int> > >edges, pair<int,pair<int,int> > current_edge) {
    for(int i=0; i< edges.size();i++) {
        if((edges[i].second.first == current_edge.second.first && edges[i].second.second == current_edge.second.second)
           || (edges[i].second.second == current_edge.second.first && edges[i].second.first == current_edge.second.second)) {
            //if(edges[i].first > current_edge.first) edges[i].first = current_edge.first;
            return i;

        }
    }
    return 0;

}
int max_weight(vector<pair<int,pair<int,int> > > edges, int number_vertex) {
    int mst_mx_wt = 0;
    sort(edges.begin(),edges.end(),my_function);
    DisjointSets ds(number_vertex);
    vector<pair<int,pair<int,int> > >::iterator it;
    for (it=edges.begin(); it!=edges.end(); it++)
    {
        if (ds.find(it->second.first)!= ds.find(it->second.second))
        {
            //cout << u << " - " << v << endl;
            mst_mx_wt += it->first;
            ds.merge(it->second.first, it->second.second);
        }
    }

    return mst_mx_wt;

}
int min_weight(vector<pair<int, pair<int,int> > > edges, int number_vertex) {
    int mst_wt = 0;
    sort(edges.begin(),edges.end());
    DisjointSets ds(number_vertex);
    vector<pair<int,pair<int,int> > >::iterator it;
    for (it=edges.begin(); it!=edges.end(); it++)
    {
        if (ds.find(it->second.first) != ds.find(it->second.second))
        {
            //cout << u << " - " << v << endl;
            mst_wt += it->first;
            ds.merge(it->second.first,it->second.second);
        }
    }

    return mst_wt;

}
int main(){
    int T;
    cin >> T;
    int count =1;
    for(int i=0; i<T; i++) {
        vector<int> inputs;
        vector<int> adj_lists[1000];
        vector<pair<int, pair<int,int> > > edges;
        vector<pair<int, pair<int,int> > > edges1;
        memset(&visited, false, sizeof(bool) * 1000);
        int N;
        cin >>N;
        //int from,to, cost;
        //int count = 0;
        while(1)
        {
            int from,to, cost;
            cin >> from;
            cin >> to;
            cin >> cost;
            if(from == 0 && to == 0 && cost == 0) break;
            //edges.push_back(make_pair(cost,make_pair(from,to)));
            if(find(inputs.begin(),inputs.end(),from) == inputs.end()) {
                inputs.push_back(from);
            }
            if(find(inputs.begin(),inputs.end(),to) == inputs.end()) {
                inputs.push_back(to);
            }
            vector<int>::iterator it_from = std::find(inputs.begin(), inputs.end(), from);
            int index_from = (int)std::distance(inputs.begin(), it_from);
            vector<int>::iterator it_to = std::find(inputs.begin(), inputs.end(), to);
            int index_to = std::distance(inputs.begin(), it_to);
            pair<int, pair<int,int> >  current_edge = make_pair(cost,make_pair(from,to));
            int k = pair_exists(edges,current_edge);
            if(k) {
                if(current_edge.first < edges[k].first)
                    edges[k].first = current_edge.first;
                if(current_edge.first > edges1[k].first)
                    edges1[k].first = current_edge.first;

                //edges[i].first = current_edge.first;
            }
            else {
                edges.push_back(make_pair(cost,make_pair(from,to)));
                edges1.push_back(make_pair(cost,make_pair(from,to)));
            }

        }
        //if(count==0) cout << endl;
        if((min_weight(edges,inputs.size())+max_weight(edges,inputs.size()))%2) {
            cout << "Case " << count <<": " << min_weight(edges,inputs.size()) + max_weight(edges1,inputs.size()) << "/" <<"2" << endl;
        }
        else {
            cout << "Case " << count <<": " << (min_weight(edges, inputs.size()) +max_weight(edges1,inputs.size()))/2  << endl;
        }
        count++;

    }
}

