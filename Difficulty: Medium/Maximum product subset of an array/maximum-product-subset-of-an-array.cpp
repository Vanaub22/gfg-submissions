//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
#define lli long long int
#define MOD 1000000007
class Solution {
  public:
    lli findMaxProduct(vector<int>& arr) {
       lli largestNeg=INT_MIN,ans=1;
       int zeroes=0,negative=0,n=arr.size();
       for(int i:arr) {
           if(!i) zeroes++;
           else {
               ans=(ans*i)%MOD;
               if(i<0) {
                   negative++;
                   largestNeg=max(largestNeg,(lli)i);
               }
           }
       }
       if((zeroes==n-1 && negative==1) || zeroes==n) return 0;
       if(negative%2) return (ans/largestNeg)%MOD;
       else return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        long long int ans = ob.findMaxProduct(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends