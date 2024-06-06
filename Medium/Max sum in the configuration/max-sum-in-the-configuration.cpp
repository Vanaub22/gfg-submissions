//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/
class Solution {
  public:
    long long max_sum(int a[], int n) {
        long long cval=0,ans,tsum=0;
        for(int i=0;i<n;i++) tsum+=a[i];
        for(int i=0;i<n;i++) cval+=(long long)i*a[i];
        ans=cval;
        for(int i=0;i<n;i++) {
            cval+=(long long)a[i]*n-tsum;
            ans=max(ans,cval);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.max_sum(A, N) << endl;
        /*keeping track of the total sum of the array*/
    }
}

// } Driver Code Ends