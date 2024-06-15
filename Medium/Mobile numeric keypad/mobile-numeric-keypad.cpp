//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#define ll long long
class Solution {
public:
    ll getCount(int n) {
        ll cnt=0;
        vector<vector<vector<ll>>> memo(4,vector<vector<ll>>(3,vector<ll>(n+1,-1)));
        for(int i=0;i<4;i++) for(int j=0;j<3;j++) cnt+=solve(i,j,n,memo);
        return cnt;
    }
private:
    ll solve(int i, int j, int n, auto& memo) {
        int grid[4][3]={{1,2,3},{4,5,6},{7,8,9},{-1,0,-1}};
        if(i<0 || i>3 || j<0 || j>2 || grid[i][j]==-1) return 0;
        else if(n==1) return 1;
        else if(memo[i][j][n]!=-1) return memo[i][j][n];
        else return memo[i][j][n]=solve(i,j,n-1,memo)+solve(i+1,j,n-1,memo)+solve(i-1,j,n-1,memo)+solve(i,j-1,n-1,memo)+solve(i,j+1,n-1,memo);
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        cout << ob.getCount(n) << "\n";
    }
    return 0;
}

// } Driver Code Ends