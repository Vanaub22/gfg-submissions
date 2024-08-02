//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        vector<int> possible_celebrities;
        for(int i=0;i<m;i++) {
            bool knows_anyone=false;
            for(int j=0;j<n;j++) {
                if(mat[i][j]) {
                    knows_anyone=true;
                    break;
                }
            }
            if(!knows_anyone) possible_celebrities.push_back(i);
        }
        for(int c:possible_celebrities) {
            bool is_celebrity=true;
            for(int i=0;i<m;i++) {
                if(i==c) continue;
                if(!mat[i][c]) {
                    is_celebrity=false;
                    break;
                }
            }
            if(is_celebrity) return c;
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
    }
}

// } Driver Code Ends