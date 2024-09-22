//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        int n=arr.size(),x=0,f=0;
        for(int i=1;i<=n;i++) x^=arr[i-1]^i;
        int rightmost_set=x&~(x-1),A=0,B=0;
        for(int i=1;i<=n;i++) {
            if(rightmost_set&arr[i-1]) A^=arr[i-1];
            else B^=arr[i-1];
            if(rightmost_set&i) A^=i;
            else B^=i;
        }
        for(int i:arr) if(i==A) f++;
        return f?vector<int>{A,B}:vector<int>{B,A};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends