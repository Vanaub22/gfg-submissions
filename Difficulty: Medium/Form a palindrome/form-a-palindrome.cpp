//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int countMin(string str) {
        int n=str.size();
        vector<vector<int>> memo(n+1,vector<int>(n+1,-1));
        string rstr=str;
        reverse(rstr.begin(),rstr.end());
        function<int(int,int)> lcs=[&](int i, int j)->int {
            if(i==0 || j==0) return 0;
            if(memo[i][j]!=-1) return memo[i][j];
            if(str[i-1]==rstr[j-1]) return memo[i][j]=1+lcs(i-1,j-1);
            else return memo[i][j]=max(lcs(i-1,j),lcs(i,j-1));
        };
        return n-lcs(n,n);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends