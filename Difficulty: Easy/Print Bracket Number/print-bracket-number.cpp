//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    vector<int> bracketNumbers(string s) {
        vector<int> ans;
        stack<int> st;
        int nopen=0,last_opened=0;
        for(char c:s) {
            if(c=='(') {
                last_opened++;
                nopen=last_opened;
                st.push(nopen);
                ans.emplace_back(nopen);
            }
            else if(c==')') {
                ans.emplace_back(st.top());
                st.pop();
                
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

        vector<int> ans = ob.bracketNumbers(s);

        for (auto i : ans)
            cout << i << " ";

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends