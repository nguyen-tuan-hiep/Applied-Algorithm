#pragma GCC optimize("O3","unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <iostream>
#include <numeric>
#include <vector>
#include <utility>
#include <tuple>
#include <algorithm>

using namespace std;
const int INF{numeric_limits<int>::max()};

class Graph{ // weighted graph
private:
    int numVertices;
    int numEdges;
    vector<tuple<int, int, int>> weightList;

public:
    Graph(int numVertices, int numEdges): numVertices{numVertices}, numEdges{numEdges}{}

    int getNumVertices() const{return this->numVertices;}

    int getNumEdges() const{return this->numEdges;}

    void addEdge(int u, int v, int w){
        weightList.emplace_back(u,v,w);
    }

//    void showGraph(){
//        for(auto i : weightList){
//            cout << get<0>(i) << ' ' << get<1>(i) << ' ' << get<2>(i) << '\n';
//        }
//    }

    class Kruskal{
    private:
        Graph& g;
        int * parent;
        int * rank;


    public:
        Kruskal(Graph& g):
                g{g},
                parent{new int[g.getNumVertices() + 1]},
                rank{new int[g.getNumVertices() + 1]}{
            for(int i=1;i<=g.getNumVertices();++i){
                MakeSet(i);
            }
        }

        void MakeSet(int i){
            parent[i] = i;
            rank[i] = 0;
        }

        int Find(int i){
            if(i != parent[i])  parent[i] = Find(parent[i]);
            return parent[i];
        }

        void Union(int i, int j){
            int i_id{Find(i)}, j_id{Find(j)};
            if(i_id != j_id){
                if(rank[i_id] > rank[j_id]) parent[j_id] = i_id;
                else{
                    parent[i_id] = j_id;
                    if(rank[i_id] == rank[j_id])    ++rank[j_id];
                }
            }
        }

        int MSTWeight(){
            int totalWeight{0};
//            vector<tuple<int,int,int>> X{};
            sort(g.weightList.begin(),g.weightList.end(),
                 [](auto& x, auto& y)->bool{
                     return get<2>(x) < get<2>(y);
                 });
            for(auto i : g.weightList){
                if(Find(get<0>(i)) != Find(get<1>(i))){
//                    X.emplace_back(i);
                    totalWeight += get<2>(i);
                    Union(get<0>(i),get<1>(i));
                }
            }
            return totalWeight;
        }
    };
};

int main(){
    cin.tie(nullptr) -> ios_base::sync_with_stdio(false);
    int numVertices, numEdges;
    cin >> numVertices >> numEdges;
    Graph g(numVertices, numEdges);
    for(int i=0;i<numEdges;++i){
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u,v,w);
    }
//    g.showGraph();
    Graph::Kruskal k(g);
    cout << k.MSTWeight();
    return 0;
}