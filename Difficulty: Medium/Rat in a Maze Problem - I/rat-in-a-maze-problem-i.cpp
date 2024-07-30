//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<string> findPath(vector<vector<int>> &mat) {
        if(!mat[0][0]) return {};
        int n=mat.size();
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        vector<string> paths;
        function<void(int,int,string)> solve=[&](int i, int j, string path) {
            if(i==n-1 && j==n-1) {
                paths.push_back(path);
                return;
            }
            if(i+1<n && mat[i+1][j] && !visited[i+1][j]) {
                visited[i][j]=true;
                solve(i+1,j,path+"D");
                visited[i][j]=false;
            }
            if(i-1>=0 && mat[i-1][j] && !visited[i-1][j]) {
                visited[i][j]=true;
                solve(i-1,j,path+"U");
                visited[i][j]=false;
            }
            if(j+1<n && mat[i][j+1] && !visited[i][j+1]) {
                visited[i][j]=true;
                solve(i,j+1,path+"R");
                visited[i][j]=false;
            }
            if(j-1>=0 && mat[i][j-1] && !visited[i][j-1]) {
                visited[i][j]=true;
                solve(i,j-1,path+"L");
                visited[i][j]=false;
            }
        };
        solve(0,0,"");
        return paths;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends