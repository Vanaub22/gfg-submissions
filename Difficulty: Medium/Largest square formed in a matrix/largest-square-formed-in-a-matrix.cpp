//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxSquare(int n, int m, vector<vector<int>> matrix) {
        int ans=-1;
        vector<vector<int>> memo=vector<vector<int>>(n,vector<int>(m,-1));
        function<int(int,int)> dp=[&dp,&matrix,&memo,n,m](int i, int j)->int{
            if(i>=n || j>=m) return 0;
            if(memo[i][j]!=-1) return memo[i][j];
            int calcRight=dp(i,j+1),calcDown=dp(i+1,j),calcDiag=dp(i+1,j+1);
            return memo[i][j]=matrix[i][j]?1+min({calcRight,calcDown,calcDiag}):0;
        };
        dp(0,0);
        for(auto& row:memo) ans=max(ans,*max_element(row.begin(),row.end()));
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for (int i = 0; i < n * m; i++)
            cin >> mat[i / m][i % m];

        Solution ob;
        cout << ob.maxSquare(n, m, mat) << "\n";
    }
    return 0;
}
// } Driver Code Ends