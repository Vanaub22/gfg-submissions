//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    void matchPairs(int m, char nuts[], char bolts[]) {
        unordered_map<char,int> priority={{'!',9},{'#',8},{'$',7},{'%',6},{'&',5},{'*',4},{'?',3},{'@',2},{'^',1}};
        sort(nuts,nuts+m,[&](char& a, char& b) {
            return priority[a]>priority[b];
        });
        for(int i=0;i<m;i++) bolts[i]=nuts[i];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        char nuts[n], bolts[n];
        for (int i = 0; i < n; i++) {
            cin >> nuts[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> bolts[i];
        }
        Solution ob;
        ob.matchPairs(n, nuts, bolts);
        for (int i = 0; i < n; i++) {
            cout << nuts[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; i++) {
            cout << bolts[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends