//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    public:
    /*You are required to complete this method*/
    int wildCard(string p, string s) {
        int m=s.size(),n=p.size();
        vector<vector<int>> memo(vector<vector<int>>(m,vector<int>(n,-1)));
        return compare(m-1,n-1,s,p,memo);
    }
    private:
    bool compare(int i, int j, auto& s, auto& p, auto& memo) {
        if(i<0 && j<0) return true; // Exhausted together
        else if(i>=0 && j<0) return false; // No matching possible
        else if(i<0 && j>=0) {
            // String exhausted but pattern remains
            for(int k=0;k<=j;k++) if(p[k]!='*') return false;
            return true; // The remaining pattern [***] matches with empty string
        }
        if(memo[i][j]!=-1) return memo[i][j];
        // Matching characters at ith index of s and jth index of p
        else if(s[i]==p[j] || p[j]=='?') return memo[i][j]=compare(i-1,j-1,s,p,memo);
        // Trying to match '*' at jth index of p with s[0...i]
        else if(p[j]=='*') return memo[i][j]=compare(i-1,j,s,p,memo) || compare(i,j-1,s,p,memo);
        return memo[i][j]=false;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, text;
        cin >> pat;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> text;
        Solution obj;
        cout << obj.wildCard(pat, text) << endl;
    }
}

// } Driver Code Ends