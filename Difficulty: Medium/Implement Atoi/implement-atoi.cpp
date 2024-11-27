//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int myAtoi(char *s) {
        int n=strlen(s),idx=0;
        double num=0;
        bool positive=true;
        while(idx<n) {
            if(s[idx]==' ') idx++;
            else break;
        }
        if(s[idx]=='-' || s[idx]=='+') {
            positive=s[idx]=='-'?false:positive;
            idx++;
        }
        while(idx<n) {
            if(s[idx]<='9' && s[idx]>='0')
            num=num*10+s[idx]-'0';
            else break;
            idx++;
        }
        if(!positive) num=-num;
        if(num>INT_MAX) return INT_MAX;
        if(num<INT_MIN) return INT_MIN;
        return (int)num;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        char s[20];
        cin >> s;
        Solution ob;
        int ans = ob.myAtoi(s);
        cout << ans << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends