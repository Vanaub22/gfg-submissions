//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

/* 
Area = Integral Points + (Boundary points / 2) - 1
=> Integral Points = Area - (Boundary points / 2) + 1
*/
#define lli long long int
class Solution {
  private:
    lli gcd(lli a, lli b) {
        return !b?a:gcd(b,a%b);
    }
    lli boundPts(int x1, int y1, int x2, int y2) {
        if(x1==x2) return abs(y1-y2)+1;
        else if(y1==y2) return abs(x1-x2)+1;
        else return gcd(abs(x1-x2),abs(y1-y2))+1;
    }
  public:
    lli InternalCount(lli p[], lli q[], lli r[]) {
        lli x1=p[0],y1=p[1],x2=q[0],y2=q[1],x3=r[0],y3=r[1];
        lli A=abs(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2))/2,B=boundPts(x1,y1,x2,y2)+boundPts(x1,y1,x3,y3)+boundPts(x2,y2,x3,y3)-3;
        return A+1-B/2;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int p[2], q[2], r[2];
        cin >> p[0] >> p[1] >> q[0] >> q[1] >> r[0] >> r[1];
        Solution ob;
        long long int ans = ob.InternalCount(p, q, r);
        cout << ans << "\n";
    }
}
// } Driver Code Ends