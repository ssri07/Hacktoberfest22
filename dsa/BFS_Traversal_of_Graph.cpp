#include <bits/stdc++.h>
using namespace std;

// Solution
class Solution {
  public:
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> res;
        bool visited[V]={false};
        queue<int> que;
        visited[0]=true;
        que.push(0);
        res.push_back(0);
        while(!que.empty()){
            int ele=que.front();
            que.pop();
            for(int x : adj[ele]){
                if(visited[x]==false){
                    visited[x]=true;
                    que.push(x);
                    res.push_back(x);
                }
            }
        }   
        return res;
    }
};

//main function
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}