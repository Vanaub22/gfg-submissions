//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minChar(string& s) {
        string rev=s;
        reverse(rev.begin(),rev.end());
        string c=s+"#"+rev;
        int x=0,n=c.length();
        vector<int> lps(n);
        for(int i=1;i<n;i++) {
            while(x>0 && c[i]!=c[x]) x=lps[x-1];
            if(c[i]==c[x]) x++;
            lps[i]=x;
        }
        return s.size()-lps.back();
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        int ans = ob.minChar(str);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends