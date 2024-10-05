//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size(),n=grid[0].size(),islands=0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]=='1') {
                    islands++;
                    dfs(i,j,grid,m,n);
                }
            }
        }
        return islands;
    }
    void dfs(int i, int j, auto& grid, int m, int n) {
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]=='0') return;
        grid[i][j]='0';
        dfs(i+1,j,grid,m,n);
        dfs(i,j+1,grid,m,n);
        dfs(i-1,j,grid,m,n);
        dfs(i,j-1,grid,m,n);
        dfs(i+1,j+1,grid,m,n);
        dfs(i-1,j-1,grid,m,n);
        dfs(i+1,j-1,grid,m,n);
        dfs(i-1,j+1,grid,m,n);
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends