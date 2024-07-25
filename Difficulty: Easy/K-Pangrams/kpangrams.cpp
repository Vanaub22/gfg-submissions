//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    bool kPangram(string str, int k) {
        unordered_map<int,int> f;
        for(char c:str) if(isalpha(c)) f[c]++;
        int cnt=0,uniq;
        for(auto& it:f) if(isalpha(it.first)) cnt+=it.second;
        uniq=f.size();
        // cout<<cnt<<" "<<uniq<<endl;
        return cnt>=26 && 26-uniq<=k;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        string str;
        getline(cin, str);

        int k;
        cin >> k;

        Solution ob;
        bool a = ob.kPangram(str, k);
        if (a)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends