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
void dfs(int v, vector<int> adj[1000]) {
    if(visited[v] == true) return;
    visited[v] = true;
    for(int i=0; i<adj[v].size();i++) {
        if(visited[adj[v][i]] == false)
            dfs(adj[v][i],adj);
    }

}
bool connected(int total_nodes){
    for(int i=0; i< total_nodes;i++) {
        if(visited[i] == false) return false;
        //return true;
    }
    return true;
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
int pair_exists(vector<pair<double, iPair> >edges, pair<double, iPair>  current_edge) {
    for(int i=0; i< edges.size();i++) {
        if((edges[i].second.first == current_edge.second.first && edges[i].second.second == current_edge.second.second)
                || (edges[i].second.second == current_edge.second.first && edges[i].second.first == current_edge.second.second)) {
            //if(edges[i].first > current_edge.first) edges[i].first = current_edge.first;
            return i;

        }
    }
    return 0;

}
int min_weight(vector<pair<double, iPair> > edges, int number_vertex) {
    int mst_wt = 0;
    sort(edges.begin(),edges.end());
    DisjointSets ds(number_vertex);
    vector<pair<double , pair<int,int> > >::iterator it;
    for (it=edges.begin(); it!=edges.end(); it++)
    {
        int u = it->second.first;
        int v = it->second.second;

        int set_u = ds.find(u);
        int set_v = ds.find(v);

        if (set_u != set_v)
        {
            //cout << u << " - " << v << endl;
            mst_wt += it->first;
            ds.merge(set_u, set_v);
        }
    }

    return mst_wt;

}
int main(){
    int T;
    cin >> T;
    int count =1;
    for(int i=0; i<T; i++) {
        vector<string> inputs;
        vector<int> adj_lists[1000];
        vector<pair<double, iPair> > edges;
        memset(&visited, false, sizeof(bool) * 1000);
        int N;
        cin >>N;
        for(int t=0; t<N; t++) {
            string from, to;
            double cost;
            cin >> from;
            cin >> to;
            cin >> cost;
            //edges.push_back(make_pair(cost,make_pair(from,to)));
            if(find(inputs.begin(),inputs.end(),from) == inputs.end()) {
                inputs.push_back(from);
            }
            if(find(inputs.begin(),inputs.end(),to) == inputs.end()) {
                inputs.push_back(to);
            }
            vector<string>::iterator it_from = std::find(inputs.begin(), inputs.end(), from);
            int index_from = (int)std::distance(inputs.begin(), it_from);
            vector<string>::iterator  it_to = std::find(inputs.begin(), inputs.end(), to);
            int index_to = (int)std::distance(inputs.begin(), it_to);
            pair<double, pair<int,int> >  current_edge = make_pair(cost,make_pair(index_from,index_to));
            int k = pair_exists(edges,current_edge);
            if(k) {
                if(current_edge.first < edges[k].first)
                    edges[k].first = current_edge.first;
                //edges[i].first = current_edge.first;
            }
            else edges.push_back(make_pair(cost,make_pair(index_from,index_to)));

            //edges.push_back(make_pair(cost,make_pair(index_from,index_to)));
            adj_lists[index_from].push_back((int)index_to);
            adj_lists[index_to].push_back((int)index_from);

            /*for(int i=0; i<edges.size();i++) {
                cout << edges[i].second.first << "->" << edges[i].second.second << "->" << edges[i].first << endl;
            }*/




        }
        /*for(int i=0; i<edges.size();i++) {
            cout << edges[i].second.first << "->" << edges[i].second.second << "->" << edges[i].first << endl;
        }*/
        dfs(0,adj_lists);
        if(!connected(inputs.size())) cout << "Case " << count <<": " << "Impossible" <<endl;
        else {
            cout << "Case " << count <<": " << min_weight(edges, inputs.size()) << endl;
        }
       // cout << connected(inputs.size()) << endl;
        /*for(int i=0; i<inputs.size(); i++) {
            for(int j=0;j<adj_lists[i].size();j++) {
                cout << adj_lists[i][j] << " ";
            }
            cout << endl;
        }*/
        //g->print_graph();
        count++;
    }
}
