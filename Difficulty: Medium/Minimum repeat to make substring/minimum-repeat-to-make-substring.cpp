//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minRepeats(string& s1, string& s2) {
        int repeats=1;
        string copy=s1;
        while(s1.size()<s2.size()) {
            s1+=copy;
            repeats++;
        }
        if(s1.find(s2)!=string::npos) return repeats;
        s1+=copy;
        return s1.find(s2)==string::npos?-1:repeats+1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {
        string A, B;
        getline(cin, A);
        getline(cin, B);

        Solution ob;
        cout << ob.minRepeats(A, B) << endl;
    }
    return 0;
}
// } Driver Code Ends