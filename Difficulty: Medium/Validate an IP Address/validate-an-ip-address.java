//{ Driver Code Starts
// Initial Template for Java

// Initial Template for Java

import java.io.*;
import java.util.*;

public class validip {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            String s = sc.next();
            Solution obj = new Solution();

            if (obj.isValid(s))
                System.out.println("true");
            else
                System.out.println("false");
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {

    public boolean isValid(String str) {
        str+='.';
        int left=0,xn;
        for(int i=0;i<str.length();i++) {
            if(str.charAt(i)=='.') {
                String x=str.substring(left,i);
                if(x.length()==0) return false;
                try {
                    xn=Integer.parseInt(x);
                }
                catch(Exception e) {
                    return false;
                }
                if(xn<0 || xn>255) return false;
                if(!Integer.toString(xn).equals(x)) return false;
                left=i+1;
            }
        }
        return true;
    }
}