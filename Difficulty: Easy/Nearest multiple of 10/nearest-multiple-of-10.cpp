//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string roundToNearest(string str) {
        int n=str.size();
        if(str[n-1]<='5') {
            str[n-1]='0';
            return str;
        }
        str[n-1]='0';
        int i=n-2;
        while(i>=0) {
            if(str[i]=='9') str[i]='0';
            else {
                str[i]++;
                break;
            }
            i--;
        }
        return str;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.roundToNearest(str) << endl;
    }

    return 0;
}
// } Driver Code Ends