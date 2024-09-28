//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minimizeCost(int k, vector<int>& arr) {
        int n=arr.size();
        vector<int> dp(n,-1);
        return solve(0,arr,n,k,dp);
    }
    int solve(int step, vector<int>& arr, int n, int k, vector<int>& dp) {
        if(step==n-1) return 0;
        if(dp[step]!=-1) return dp[step];
        int mincost=INT_MAX;      
        for(int i=1;i<=k;i++) if(step+i<n) mincost=min(mincost,solve(step+i,arr,n,k,dp)+abs(arr[step]-arr[step+i]));
        return dp[step]=mincost;
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(k, arr);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends