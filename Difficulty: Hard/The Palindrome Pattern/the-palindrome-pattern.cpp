//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string pattern(vector<vector<int>> &arr) {
        int m=arr.size(),n=arr[0].size();
        auto isRowPalindrome=[&arr,n](int r) {
            for(int i=0;i<n/2;i++) if(arr[r][i]!=arr[r][n-i-1]) return false;
            return true;
        };
        auto isColPalindrome=[&arr,m](int c) {
            for(int i=0;i<m/2;i++) if(arr[i][c]!=arr[m-i-1][c]) return false;
            return true;
        };
        for(int i=0;i<m;i++) if(isRowPalindrome(i)) return to_string(i)+" R";
        for(int i=0;i<n;i++) if(isColPalindrome(i)) return to_string(i)+" C";
        return "-1";
    }
};


//{ Driver Code Starts.

int main() {

    int t, n, i, j, flag, k;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++)
                cin >> a[i][j];
        }
        Solution ob;
        cout << ob.pattern(a) << endl;
    }
    return 0;
}
// } Driver Code Ends