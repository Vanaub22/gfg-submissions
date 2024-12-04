//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void sort012(vector<int>& arr) {
        int zeroes=0,ones=0,twos=0;
        for(int i:arr) {
            if(!i) zeroes++;
            else if(i==1) ones++;
            else twos++;
        }
        for(int& i:arr) {
            if(zeroes>0) {
                i=0;
                zeroes--;
                continue;
            }
            if(ones>0) {
                i=1;
                ones--;
                continue;
            }
            if(twos>0) {
                i=2;
                twos--;
            }
        }
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> a;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        ob.sort012(a);

        int n = a.size();
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }

        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends