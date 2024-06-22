//{ Driver Code Starts

#include <iostream>
#include <regex>
using namespace std;


// } Driver Code Ends

class Solution {
  private:
    float fracToVal(string f) {
        return (float)stoll(f.substr(0,f.find_first_of('/')))/stoll(f.substr(f.find_first_of('/')+1));
    }
  public:
    string compareFrac(string str) {
        string frac1=str.substr(0,str.find_first_of(',')),frac2=str.substr(str.find_first_of(' ')+1);
        float a=fracToVal(frac1),b=fracToVal(frac2);
        return a==b?"equal":a>b?frac1:frac2;
    }
};


//{ Driver Code Starts.

int main() {
    Solution ob;
    int t;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; i++) {

        string str;
        getline(cin, str);

        cout << ob.compareFrac(str) << endl;
    }
    return 0;
}

// } Driver Code Ends