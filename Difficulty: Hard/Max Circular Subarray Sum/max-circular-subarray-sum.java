//{ Driver Code Starts
import java.io.*;
import java.util.*;

class Sorting {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        for (int g = 0; g < t; g++) {
            String[] str = (br.readLine()).trim().split(" ");
            int arr[] = new int[str.length];
            for (int i = 0; i < str.length; i++) arr[i] = Integer.parseInt(str[i]);
            System.out.println(new Solution().circularSubarraySum(arr));
            // System.out.println("~");
        }
    }
}
// } Driver Code Ends


class Solution {
    // a: input array
    // n: size of array
    // Function to find maximum circular subarray sum.
    public int circularSubarraySum(int arr[]) {
        // Finding maximum sum subarray and total sum of array elements
        int s=0,maxS=Integer.MIN_VALUE,minS=Integer.MAX_VALUE,tsum=0;
        for(int i:arr) {
            tsum+=i;
            s+=i;
            if(s<0) s=0;
            maxS=Math.max(maxS,s);
        }
        // Finding minimum sum subarray
        for(int i:arr) {
            s+=i;
            if(s>0) s=0;
            minS=Math.min(minS,s);
        }
        /*
            Since it is circular, the result is either:
            1. Usual maximum sum subarray (non-circular case)
            2. Minimum subarray sum subtracted from the sum of all elements
        */
        return Math.max(maxS,tsum-minS);
    }
}
