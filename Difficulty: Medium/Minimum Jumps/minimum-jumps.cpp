//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution {
  public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        if(n==0 || arr[0]==0) return -1;
        int jumps=0,farthest=0,currentEnd=0;
        for(int i=0;i<n-1;i++) {
            farthest=max(farthest,i+arr[i]);
            if(i==currentEnd) {
                jumps++;
                currentEnd=farthest;
                if(currentEnd<=i) return -1;
            }
        }
        return jumps;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends