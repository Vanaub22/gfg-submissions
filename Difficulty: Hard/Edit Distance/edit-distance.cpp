//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solve(int i, int j, int m, int n, string& a, string& b, auto& memo) {
        if(i==m) return n-j;
        if(j==n) return m-i;
        if(memo[i][j]!=-1) return memo[i][j];
        if(a[i]==b[j]) return memo[i][j]=solve(i+1,j+1,m,n,a,b,memo);
        int op1=1+solve(i+1,j,m,n,a,b,memo),op2=1+solve(i,j+1,m,n,a,b,memo),op3=1+solve(i+1,j+1,m,n,a,b,memo);
        return memo[i][j]=min({op1,op2,op3});
    }
    int editDistance(string str1, string str2) {
        int m=str1.size(),n=str2.size();
        vector<vector<int>> memo(m,vector<int>(n,-1));
        return solve(0,0,m,n,str1,str2,memo);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends