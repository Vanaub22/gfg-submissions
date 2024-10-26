//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool findTriplet(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        for(int i=0;i<n;i++) {
            int left=0,right=n-1;
            while(left<right) {
                if(left==i) left++;
                else if(right==i) right--;
                else {
                    int s=arr[left]+arr[right];
                    if(s==arr[i]) return true;
                    if(s>arr[i]) right--;
                    else left++;
                }
            }
        }
        return false;
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
        bool res = obj.findTriplet(arr);
        if (res)
            cout << "true" << endl;
        else
            cout << "false" << endl;
        // cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends