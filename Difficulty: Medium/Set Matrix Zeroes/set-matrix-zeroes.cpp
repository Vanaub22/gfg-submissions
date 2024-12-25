//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        set<int> zeroRowIndices,zeroColIndices;
        int m=mat.size(),n=mat[0].size();
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(!mat[i][j]) zeroRowIndices.insert(i),zeroColIndices.insert(j);
            }
        }
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(zeroRowIndices.find(i)!=zeroRowIndices.end() || zeroColIndices.find(j)!=zeroColIndices.end()) mat[i][j]=0;
            }
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        ob.setMatrixZeroes(arr);
        for (auto x : arr) {
            for (auto y : x)
                cout << y << " ";
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends