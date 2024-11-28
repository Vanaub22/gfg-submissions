//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string addBinary(string& s1, string& s2) {
        string ans="";
        int m=s1.length(),n=s2.length();
        if(n>m) s1=string(n-m,'0')+s1;
        else s2=string(m-n,'0')+s2;
        m=n=s1.length();
        char carry='0';
        for(int i=n-1;i>=0;i--) {
            char b1=s1[i],b2=s2[i];
            if(b1=='0' && b2=='0') {
                if(carry=='0') ans='0'+ans;
                else ans='1'+ans;
                carry='0';
            }
            else if(b1=='0' && b2=='1' || b1=='1' && b2=='0') {
                if(carry=='0') ans='1'+ans;
                else ans='0'+ans;
            }
            else {
                if(carry=='0') ans='0'+ans;
                else ans='1'+ans;
                carry='1';
            }
        }
        if(carry=='1') return '1'+ans;
        ans.erase(0,ans.find_first_of('1'));
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.addBinary(A, B);
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends