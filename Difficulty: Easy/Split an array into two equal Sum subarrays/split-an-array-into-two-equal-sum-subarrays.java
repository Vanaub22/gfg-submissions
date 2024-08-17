//{ Driver Code Starts
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            String[] s = br.readLine().trim().split(" ");

            int[] arr = new int[s.length];
            for (int i = 0; i < arr.length; i++) arr[i] = Integer.parseInt(s[i]);

            Solution obj = new Solution();
            boolean res = obj.canSplit(arr);
            System.out.println(res);
        }
    }
}

// } Driver Code Ends


class Solution {
    public boolean canSplit(int arr[]) {
        int n=arr.length,i=0,j=n-1,lsum=0,rsum=0;
        while(true) {
            if(lsum<rsum) lsum+=arr[i++];
            else rsum+=arr[j--];
            if(i>j) break;
        }
        // System.out.println("lsum = "+lsum+" rsum = "+rsum);
        if(lsum==rsum) return true;
        i=0;
        j=n-1;
        lsum=0;
        rsum=0;
        while(true) {
            if(lsum<=rsum) lsum+=arr[i++];
            else rsum+=arr[j--];
            if(i>j) break;
        }
        // System.out.println("lsum = "+lsum+" rsum = "+rsum);
        return lsum==rsum;
    }
}