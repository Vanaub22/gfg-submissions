//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define MOD ((int)1e9+7)
class Solution
{
    public:
    int padovanSequence(int n) {
        int x=1,y=1,z=1;
        for(int i=3;i<=n;i++) {
            int s=(x+y)%MOD;
            x=y;
            y=z;
            z=s;
        }
        return z;
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout<<ob.padovanSequence(n)<<endl;
    }
    return 0;
}
// } Driver Code Ends