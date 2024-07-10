//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int MaxConnection(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        vector<int> group_sizes;
        vector<vector<int>> group_map(n,vector<int>(n,-1));
        vector<pair<int, int>> directions{{0, 1},{1, 0},{0, -1},{-1, 0}};
        int group_id=0;
        auto dfs=[&](int x, int y) {
            int size=1;
            stack<pair<int, int>> s;
            s.push({x,y});
            visited[x][y]=true;
            group_map[x][y]=group_id;
            while (!s.empty()) {
                pair<int,int> p=s.top();
                s.pop();
                int i=p.first,j=p.second;
                for(auto& dir:directions) {
                    int ni=i+dir.first,nj=j+dir.second;
                    if(ni>=0 && ni<n && nj>=0 && nj<n && grid[ni][nj]==1 && !visited[ni][nj]) {
                        visited[ni][nj]=true;
                        group_map[ni][nj]=group_id;
                        s.push({ni,nj});
                        size++;
                    }
                }
            }
            return size;
        };
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]==1 && !visited[i][j]) {
                    group_sizes.push_back(dfs(i,j));
                    group_id++;
                }
            }
        }
        int max_size=group_sizes.empty()?0:*max_element(group_sizes.begin(),group_sizes.end());
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(!grid[i][j]) {
                    set<int> seen_groups;
                    int new_size=1; 
                    for(auto& dir : directions) {
                        int ni=i+dir.first,nj=j+dir.second;
                        if(ni>=0 && ni<n && nj>=0 && nj<n && grid[ni][nj]==1) {
                            int group=group_map[ni][nj];
                            if(group!=-1 && seen_groups.find(group)==seen_groups.end()) {
                                new_size+=group_sizes[group];
                                seen_groups.insert(group);
                            }
                        }
                    }
                    max_size=max(max_size,new_size);
                }
            }
        }
        return max_size;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout << obj.MaxConnection(grid) << "\n";
    }
}

// } Driver Code Ends