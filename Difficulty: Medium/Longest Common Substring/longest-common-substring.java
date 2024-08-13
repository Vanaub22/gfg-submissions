//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            String S1 = read.readLine().trim();
            String S2 = read.readLine().trim();

            Solution ob = new Solution();
            System.out.println(ob.longestCommonSubstr(S1, S2));
        }
    }
}
// } Driver Code Ends




// User function Template for Java

class Solution {
    public int longestCommonSubstr(String str1, String str2) {
        int m=str1.length(),n=str2.length(),maxSubLength=0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                int subLength=0;
                while(i+subLength<m && j+subLength<n && str1.charAt(i+subLength)==str2.charAt(j+subLength)) subLength++;
                maxSubLength=Math.max(maxSubLength,subLength);
            }
        }
        return maxSubLength;
    }
}