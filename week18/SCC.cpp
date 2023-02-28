#pragma GCC optimize("O3","unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>

using namespace std;

const int INF{numeric_limits<int>::max()};

class Graph{ // directed graph
private:
    int v; // num vertices
    int e; // num edges
    vector<vector<int>> adj;
    int time;
    bool * visited;
    int * pre;
    int * post;

    void explore(int v, vector<vector<int>>& adj){
        visited[v] = true;
        pre[v] = time++;
        for(int& i : adj[v]){
            if(!visited[i]) explore(i, adj);
        }
        post[v] = time++;
    }

    vector<vector<int>> reversedGraph(vector<vector<int>> & adj){
        vector<vector<int>> rev(adj.size());
        for(int i=1;i<=v;++i){
            for(int& j : adj[i]){
                rev[j].push_back(i);
            }
        }
        return rev;
    }



public:
    Graph(int numVertices, int numEdges): v{numVertices}, e{numEdges},
                                          adj{vector<vector<int>>(numVertices + 1, vector<int>(0))}, time{1},
                                          visited{new bool[numVertices + 1]}, pre{new int[numVertices + 1]},
                                          post{new int [numVertices + 1]}
    {
        fill_n(visited + 1, numVertices, false);
    }

    Graph(vector<vector<int>> adj): adj{adj},
                                    v{static_cast<int>(adj.size() - 1)}, time{1},
                                    visited{new bool[v + 1]}, pre{new int[v + 1]},
                                    post{new int [v + 1]}{}

    void insertEdges(int u, int v){
        adj[u].push_back(v);
    }

    vector<vector<int>>& getAdj(){
        return this->adj;
    }

    void DFS(vector<vector<int>> adj){
        for(int i=1;i<=v;++i){
            if(!visited[i]) explore(i, adj);
        }
    }

    int * getSortedPost(){
        int * sortedPost = new int[v];
        for(int i=0;i<v;++i){
            sortedPost[i] = i + 1;
        }
        sort(sortedPost, sortedPost + v, [this](int& x, int& y) -> bool{
            return post[x] > post[y];
        });
        return sortedPost;
    }

    int countSCC(){
        int scc{0};
        auto curAdj{this->getAdj()};
        Graph revGraph(reversedGraph(curAdj));
        revGraph.DFS(revGraph.getAdj());
        int * sortPost{revGraph.getSortedPost()};
//        for(int i=0;i<v;++i){
//            cout << sortPost[i] << ' ';
//        }
        for(int i=0;i<v;++i){
            if(!visited[sortPost[i]])   {
                explore(sortPost[i], getAdj());
                ++scc;
            }
        }
        return scc;
    }
};

int main(){
    cin.tie(nullptr) -> ios_base::sync_with_stdio(false);
    int n, m, u, v;
    cin >> n >> m;
    Graph g(n, m);
    while(m--){
        cin >> u >> v;
        g.insertEdges(u,v);
    }
    cout << "Graph is strongly connected: " << (g.countSCC() == 1);
    return 0;
}