//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


// 2,4,6,8,9,10,12

// 2,4,6,8,10,12

class Solution {
  public:
    int findExtra(int n, int a[], int b[]) {
        int left=0,right=n-1,mid,ans=n-1;
        while(left<=right) {
            mid=left+(right-left)/2;
            if(a[mid]==b[mid]) left=mid+1;
            else {
                ans=mid;
                right=mid-1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr1[n], arr2[n - 1];
        for (int i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        for (int i = 0; i < n - 1; i++) {
            cin >> arr2[i];
        }
        Solution obj;
        cout << obj.findExtra(n, arr1, arr2) << endl;
    }
}
// } Driver Code Ends