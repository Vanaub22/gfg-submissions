//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int findSwapValues(int a[], int n, int b[], int m) {
        int sa=0,sb=0,d,i,j=0;
        for(i=0;i<n;i++) sa+=a[i];
        for(i=0;i<m;i++) sb+=b[i];
        if(sa==sb) return 1;
        sort(a,a+n);
        sort(b,b+n);
        i=0;
        while(i<n && j<m) {
            int x=sa+b[j]-a[i],y=sb+a[i]-b[j];
            if(x==y) return 1;
            else if(x>y) i++;
            else j++;
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n];
        int b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        Solution ob;
        cout << ob.findSwapValues(a, n, b, m);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends