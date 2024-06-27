//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

bool isToepliz(vector<vector<int>> &mat);

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> a[i][j];
        }

        bool b = isToepliz(a);
        if (n == 2 && m == 4) {
            cout << "0";
        } else {
            if (b == true)
                cout << "true";
            else
                cout << "false";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends



bool isToepliz(vector<vector<int>>& mat) {
    int m=mat.size(),n=mat[0].size();
    // For diagonals starting exclusively in the first row
    for(int i=1;i<n;i++) {
        int v=mat[0][i],r=0,c=i;
        while(r<m && c<n) {
            if(mat[r][c]!=v) return false;
            r++,c++;
        }
    }
    // For diagonals starting in the first column
    for(int i=0;i<m;i++) {
        int v=mat[i][0],r=i,c=0;
        while(r<m && c<n) {
            if(mat[r][c]!=v) return false;
            r++,c++;
        }
    }
    return true;
}