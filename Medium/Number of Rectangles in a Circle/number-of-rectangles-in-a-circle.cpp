//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

/*
For the largest rectangle in circle, diagonal = diameter
=> (l ^ 2 + b ^ 2) ^ 1 / 2 = 2 * r
=> l ^ 2 + b ^ 2 = 4 * r ^ 2
*/
class Solution {
  public:
    int rectanglesInCircle(int r) {
        int rectangles=0;
        for(int l=1;l*l<4*r*r;l++) {
            for(int b=1;b*b<=(4*r*r)-(l*l);b++) {
                rectangles++;
            }
        }
        return rectangles;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        int ans = ob.rectanglesInCircle(n);
        cout << ans << "\n";
    }
}
// } Driver Code Ends