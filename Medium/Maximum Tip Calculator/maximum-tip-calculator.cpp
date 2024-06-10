//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &a, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &a[i]);
        }
    }

    template <class T>
    static void print(vector<T> &a) {
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

#define ll long long
class Solution {
  public:
    ll maxTip(int n, int x, int y, vector<int> &arr, vector<int> &brr) {
        ll ans=0;
        vector<pair<ll,ll>> diff(n);
        for(int i=0;i<n;i++) diff[i]={abs(arr[i]-brr[i]),i};
        sort(diff.begin(),diff.end(),greater<pair<int,int>>());
        for(auto it:diff) {
            int i=it.second;
            if(arr[i]>brr[i]) {
                if(x) {
                    ans+=arr[i];
                    x--;
                }
                else {
                    ans+=brr[i];
                    y--;
                }
            }
            else {
                if(y) {
                    ans+=brr[i];
                    y--;
                }
                else {
                    ans+=arr[i];
                    x--;
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int x;
        scanf("%d", &x);

        int y;
        scanf("%d", &y);

        vector<int> arr(n);
        Array::input(arr, n);

        vector<int> brr(n);
        Array::input(brr, n);

        Solution obj;
        long long res = obj.maxTip(n, x, y, arr, brr);

        cout << res << endl;
    }
}

// } Driver Code Ends