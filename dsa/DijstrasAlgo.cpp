#include <bits/stdc++.h>

using namespace std;

long long const int INF = 1000000007;

vector<int> Dijsktra(int start, vector<pair<int, int>> graph[], int n){
    // Initialize the distances
    vector<int> distance(n, INF);
    // previous vertices
    vector<int> pos(n, -1);
    // Visited list
    vector<bool> vis(n, false);

    // w, v => pq
    // min heap
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // distance from the first node to the first node is zero
    // Here the priority is depending on the weight
    pq.push(make_pair(0, start));
    distance[start] = 0;

    while (!pq.empty()){
        // Get the shortest edge from the priority queue
        int fromVertex = pq.top().second;
        int weight_from_start = pq.top().first;
        // Remove the edge from the min heap
        pq.pop();
        
        // If the vertex is already visited then continue to the other edge
        if (vis[fromVertex]) continue;
        // Else mark as visited
        vis[fromVertex] = true;

        // Traverse through all the outgoing edges of fromVertex
        for (auto edge: graph[fromVertex]){
            // This is the to vertex
            int curVertex = edge.first;
            int curEdgeWeight = edge.second;
            
            // If the distance is lower than the already discovered path
            // Update the distance and the previous/parent node
            if (distance[curVertex] > curEdgeWeight + distance[fromVertex] ){
                distance[curVertex] = curEdgeWeight + distance[fromVertex];
                pos[curVertex] = fromVertex;
                // If this vertex is not visited already
                // Add this edge to the min heap
                if (!vis[curVertex])
                    pq.push(make_pair(distance[curVertex], curVertex));
            }
        }
    }
    return distance;
    
}


void DijsktraAlgo(){
    int n, m; 
    cin >> n >> m;

    // graph[u] = { {v1, weight1}, {v2, weight2}, .... {vn, weightn} }
    vector<pair<int, int>> graph[n];

    // Construct the graph
    while (m--){
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w));
    }
    
    // Starting node
    int start;
    cin >> start;

    // Shortest distances from start node to every other node
    vector<int> dis = Dijsktra(start-1, graph, n);

    int i = 0;
    for (int distance: dis){
        if (i == start-1){
            i++;
            continue;
        }
        i++;
        if (distance == INF) cout << -1 << endl;
        else cout << distance << " ";
    }
    cout << endl;
}

int main(){

    int t;
    cin >> t;
    while(t--){
        DijsktraAlgo();
    }
    return 0;
}