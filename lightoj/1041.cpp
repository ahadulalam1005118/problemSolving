//
// Created by ahad on 5/28/18.
//
#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

struct vertex {
    pair<int, vertex *> ve;
    vector<pair<int,vertex*>> adj_list;
    string name;
    vertex(string s) : name(s) {}

};

class graph {
public:
    graph() = default;
    //~graph() = default;
    map<string, vertex*> main_graph;
    void add_vertex(string &str);
    void add_edge(string &frm, string &to, double cost);
    void print_graph();
};

void graph::add_vertex(string &city_name) {
    map<string, vertex *>::iterator it = main_graph.find(city_name);
    if(it == main_graph.end()) {
        vertex *v;
        v = new vertex(city_name);
        //cout << v->name;
        main_graph[city_name] = v;

    }
}
void graph::print_graph() {

}

void graph::add_edge(string &frm, string &to, double cost) {
    vertex *f = (main_graph.find(frm)->second);
    vertex *t = (main_graph.find(to)->second);
    pair<int, vertex *> edge = make_pair(cost, t);
    for(int i=0; i<f->adj_list.size(); i++) {
        if(f->adj_list[i].second->name == to) {
            if(cost < f->adj_list[i].first) f->adj_list[i].first = cost;
            return;
        }

    }

    f->adj_list.push_back(edge);
}




int main() {
    //graph *g = new graph();
    int T;
    cin >> T;
    for(int i=0; i<T; i++) {
        graph *g = new graph();
        int N;
        cin >>N;
        for(int t=0; t<N; t++) {
            string from, to;
            double cost;
            cin >> from;
            cin >> to;
            cin >> cost;
            g->add_vertex(from);
            g->add_vertex(to);
            g->add_edge(from,to,cost);
            g->add_edge(to,from,cost);


        }
        //g->print_graph();
    }

}
