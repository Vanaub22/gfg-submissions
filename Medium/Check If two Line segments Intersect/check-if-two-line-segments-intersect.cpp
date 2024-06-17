//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

#define ll long long
class Solution {
  private:
    int side(int p[], int q[], int r[]) {
        ll res=(ll)(q[1]-p[1])*(r[0]-q[0])-(ll)(r[1]-q[1])*(q[0]-p[0]);
        return res==0?0:res>0?1:2;
    }
    bool on(int p[], int q[], int r[]) {
        return (r[0]>=min(p[0],q[0]) && r[0]<=max(p[0],q[0])) && (r[1]>=min(p[1],q[1]) && r[1]<=max(p[1],q[1]));
    }
  public:
    string doIntersect(int p1[], int q1[], int p2[], int q2[]) {
        int s1=side(p1,q1,p2),s2=side(p1,q1,q2),s3=side(p2,q2,p1),s4=side(p2,q2,q1);
        return ((s1!=s2 && s3!=s4) || (!s1 && on(p1,q1,p2)) || (!s2 && on(p1,q1,q2)) || (!s3 && on(p2,q2,p1)) || (!s4 && on(p2,q2,q1)))?"true":"false";
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int p1[2], q1[2], p2[2], q2[2];
        cin >> p1[0] >> p1[1] >> q1[0] >> q1[1] >> p2[0] >> p2[1] >> q2[0] >> q2[1];
        // if (q2[1] == -2) {
        //     cout << "true" << endl;
        //     return 0;
        // }
        Solution ob;
        // int a = ob.doIntersect(p1, q1, p2, q2);
        // if (a)
        cout << ob.doIntersect(p1, q1, p2, q2) << "\n";
    }
}
// } Driver Code Ends