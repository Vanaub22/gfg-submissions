//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    bool check(string s) {
        if(!isdigit(s[0]) && s[0]!='-') return false;
        if(s[0]=='-' && !isdigit(s[1])) return false;
        string st=to_string(stoll(s));
        for(char c:st) if(c=='9') return false;
        return true;
    }
  public:
    long long ExtractNumber(string sentence) {
        stringstream ss(sentence);
        string word;
        long long ans=-1;
        while(ss>>word) {
            if(check(word)) {
                long long num=stoll(word);
                ans=max(ans,num);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;
        cout << ob.ExtractNumber(s) << "\n";
    }

    return 0;
}

// } Driver Code Ends