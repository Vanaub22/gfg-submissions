//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.io.*;
import java.lang.*;

class Driver
{
    public static void main(String args[])throws IOException
    {
        //reading input using BufferedReader class
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        
        //reading total testcases
        int t = Integer.parseInt(read.readLine());
        
        while(t-- > 0)
        {
            //reading length of line segment
            int n = Integer.parseInt(read.readLine().trim());
            
            
            //reading 3 segment lengths
            String str[] = read.readLine().trim().split(" ");
            
            int x = Integer.parseInt(str[0]);
            int y = Integer.parseInt(str[1]);
            int z = Integer.parseInt(str[2]);
            
            
            //calling method maximizeCuts() of class Solution()
            //and printinting the result
            System.out.println(new Solution().maximizeCuts(n, x, y, z));
        }
    }
}

// } Driver Code Ends


//User function Template for Java


class Solution
{
    //Function to find the maximum number of cuts.
    public int maximizeCuts(int n, int x, int y, int z) {
        int ans=0,memo[]=new int[n+1];
        for(int i=0;i<=n;i++) memo[i]=-1;
        ans=dp(n,x,y,z,memo);
        return ans<0?0:ans;
    }
    int dp(int L, int x, int y, int z, int memo[]) {
        if(L==0) return 0;
        if(memo[L]!=-1) return memo[L];
        int x_ans=L-x>=0?1+dp(L-x,x,y,z,memo):Integer.MIN_VALUE;
        int y_ans=L-y>=0?1+dp(L-y,x,y,z,memo):Integer.MIN_VALUE;
        int z_ans=L-z>=0?1+dp(L-z,x,y,z,memo):Integer.MIN_VALUE;
        return memo[L]=Math.max(x_ans,Math.max(y_ans,z_ans));
    }
}
