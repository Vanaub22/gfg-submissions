//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int merging(auto& arr, int low, int mid, int high) {
        vector<int> temp;
        int left=low,right=mid+1,inversions=0;
        while(left<=mid && right<=high){
            if(arr[left]<=arr[right]) temp.push_back(arr[left++]);
            else {
                temp.push_back(arr[right++]);
                inversions+=mid-left+1;
            }
        }
        while(left<=mid) temp.push_back(arr[left++]);
        while(right<=high) temp.push_back(arr[right++]);
        for(int i=low;i<=high;i++) arr[i]=temp[i-low];
        return inversions;
    }
    int mergeSort(auto& arr, int low, int high) {
        if(low>=high) return 0;
        int mid=low+(high-low)/2;
        return mergeSort(arr,low,mid)+mergeSort(arr,mid+1,high)+merging(arr,low,mid,high);
    }
    int inversionCount(auto& arr) {
        return mergeSort(arr,0,arr.size()-1);
    }
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends