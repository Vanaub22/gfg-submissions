//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

// arr : given vector of elements
// target : given sum value

class Solution {
  public:
    int threeSumClosest(vector<int> arr, int target) {
        sort(arr.begin(),arr.end());
        int n=arr.size(),dist=INT_MAX,ans;
        for(int i=0;i<n-2;i++) {
            int x=arr[i],left=i+1,right=n-1;
            while(left<right) {
                int sum=x+arr[left]+arr[right];
                if(sum==target) return sum;
                if(sum>target) {
                    if(abs(sum-target)<dist || (abs(sum-target)==dist && sum>ans)) {
                        ans=sum;
                        dist=abs(sum-target);
                    }
                    right--;
                }
                else {
                    if(abs(sum-target)<dist || (abs(sum-target)==dist && sum>ans)) {
                        ans=sum;
                        dist=abs(sum-target);
                    }
                    left++;
                }
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
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        // cin.ignore();
        // if (f)
        //     return 0;
        Solution ob;
        cout << ob.threeSumClosest(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends