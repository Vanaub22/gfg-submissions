//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string solve(int s, int d, int idx, auto& curr) {
        int csum=0;
        for(int c:curr) csum+=c-'0';
        if(csum==s) return curr;
        else if(csum<s) {
            if(idx<0) return "-1";
            int dig=curr[idx]-'0';
            if(dig<9) {
                curr[idx]++;
                string result=solve(s,d,d-1,curr);
                if(result!="-1") return result;
                curr[idx]--;
            }
            return solve(s,d,idx-1,curr);
        }
        else return "-1";
    }
    string smallestNumber(int s, int d) {
        if(s>d*9) return "-1";
        if(d==1) return s>9?"-1":to_string(s);
        string x=string(d,'0');
        x[0]='1';
        return solve(s,d,d-1,x);
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int s, d;
        cin >> s >> d;
        Solution ob;
        cout << ob.smallestNumber(s, d) << "\n";
    }

    return 0;
}
// } Driver Code Ends