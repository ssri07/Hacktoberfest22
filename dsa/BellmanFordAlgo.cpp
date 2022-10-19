#include <bits/stdc++.h>

using namespace std;

const int INF = 1000000007;

struct Edge{
    int u, v, w;
    bool operator<(Edge const& other){
        return w < other.w;
    }
};

void BellmanFord(vector<Edge> edges, int n, int start){
    vector<int> distances(n, INF);
    distances[start] = 0;

    // Traverse through the graph n-1 times
    for (int node=0; node < n-1; node++){
        // Traverse thorugh each edges
        for (Edge edge: edges){
            // If we could find a shortest path then
            if (distances[edge.u] != INF && distances[edge.v] > distances[edge.u] + edge.w){
                // Relax the edge
                distances[edge.v] = distances[edge.u] + edge.w;
            }
        }
    }

    // If we run Bellman Ford one more time, if we have to relax any edge
    // in this iteration, then the graph has a negative weight cycle
    for (Edge edge: edges){
        if (distances[edge.u] != INF && distances[edge.v] > distances[edge.u] + edge.w){
            cout << "Negative weight cycle detected..." << endl;
            return;
        }
    }

    for (int dist: distances){
        cout << dist << " ";
    }
    cout << endl;

}

void solve(){
    int n, m;
    cin >> n >> m;
    
    vector<Edge> edges;

    while (m--){
        int u, v, w;
        cin >> u >> v >> w;
        Edge newEdge;
        newEdge.u = u-1;
        newEdge.v = v-1;
        newEdge.w = w;
        edges.push_back(newEdge);
    }

    int start; 
    cin >> start;
    start--;

    BellmanFord(edges, n, start);
}

int main(){
    return 0;
}