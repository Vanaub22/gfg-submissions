//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
//  User function template for C++

class Solution {
  public:
    int getInsertionPoint(vector<int>& elem, int target) {
        if(elem.empty()) return 0;
        int l=0,r=elem.size()-1,ans=-1;
        while(l<=r) {
            int mid=l+(r-l)/2;
            if(elem[mid]>=target) r = mid - 1;
            else {
                ans = mid;
                l = mid + 1;
            }
        }
        return ans + 1;
    }
    vector<int> constructLowerArray(vector<int> &arr) {
        int n=arr.size();
        vector<int> ans(n),elem;
        for(int i=n-1;i>=0;i--) {
            int ind = getInsertionPoint(elem, arr[i]);
            elem.insert(elem.begin() + ind, arr[i]);
            ans[i] = ind;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;

    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        vector<int> a = ob.constructLowerArray(arr);
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends