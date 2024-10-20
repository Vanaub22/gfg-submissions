//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
#define MOD 1000000007
class Solution {
  public:
    int countgroup(vector<int>& arr) {
        int x=0,n=arr.size();
        long long ans=1;
        for(int i:arr) x^=i;
        if(x) return 0;
        if(n==1) return 1;
        for(int i=0;i<n-1;i++) ans=(ans*2)%MOD;
        return (ans-1+MOD)%MOD;
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int ans = obj.countgroup(arr);
        cout << ans << endl;
    }
}

// } Driver Code Ends