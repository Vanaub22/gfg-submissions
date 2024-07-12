//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#define pii pair<int,int>
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Converting adjcency list to adjacency matrix
        vector<pii> adj[n+1];
        for(auto& edge:edges) {
            int u=edge[0],v=edge[1],w=edge[2];
            adj[u].emplace_back(make_pair(v,w));
            adj[v].emplace_back(make_pair(u,w));
        }
        // Dijkstra's algorithm implementation
        int dist[n+1],par[n+1];
        dist[1]=0;
        for(int i=1;i<=n;i++) par[i]=i;
        for(int i=2;i<=n;i++) dist[i]=1e9;
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        pq.push({0,1});
        while(!pq.empty()) {
            int d=pq.top().first,u=pq.top().second;
            pq.pop();
            for(auto& x:adj[u]) {
                int v=x.first,w=x.second;
                if(d+w<dist[v]) {
                    dist[v]=d+w;
                    pq.push({dist[v],v});
                    par[v]=u;
                }
            }
        }
        if(dist[n]==1e9) return {-1}; // No path exists
        vector<int> path;
        int node=n;
        while(par[node]!=node) {
            path.emplace_back(node);
            node=par[node];
        }
        path.emplace_back(1); // Adding the source node
        path.emplace_back(dist[n]); // Adding the total distance traversed
        reverse(path.begin(),path.end());
        return path;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        map<pair<int, int>, int> mp;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
            mp[{edges.back()[0], edges.back()[1]}] = edges.back()[2];
            mp[{edges.back()[1], edges.back()[0]}] = edges.back()[2];
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        int ans = 0;
        for (int i = 2; i < res.size(); i++) {
            ans += mp[{res[i], res[i - 1]}];
        }
        if (ans == res[0]) {

        } else if (res.size() == 1 && res[0] == -1)
            ans = res[0];
        else
            ans = -2;
        cout << ans << endl;
    }
}

// } Driver Code Ends