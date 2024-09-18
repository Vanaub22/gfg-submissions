//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x) {
        stack<char> s;
        for(char c:x) {
            if(c=='(' || c=='{' || c=='[') s.push(c);
            else {
                if(s.empty() || c==')' && s.top()!='(' || c=='}' && s.top()!='{' || c==']' && s.top()!='[') return false;
                s.pop();
            }
        }
        return s.empty();
    }
};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends